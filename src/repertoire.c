/**
Fichier repertoire.c
Auteur(s): Fauquette Mael
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>

#include"repertoire.h"



iterateur_t creerIterateur(char* fichier){
    iterateur_t it = malloc(sizeof(iterateur_t));
    it->fichierit=malloc(sizeof(FILE*));
    it->fichierit = fopen(fichier,"r");
    it->finDePhrase=0;
    return it;
}
int hasNext(iterateur_t it){
    int i;
    while((i =fgetc(it->fichierit))!=EOF){
        if(isalpha(i)){
            ungetc(i, it->fichierit);
            return 1;
        }else if (i == '.' ||  i== '?' || i == '!') {
            it->finDePhrase=1;
        }
    }
    return 0;
}

char* next(iterateur_t it){

    char* mot=malloc(50); //on peut avoir des mots dans d'autres langues que le français
    int i = 0; 
    int c;
    while (i < 50 && (isalpha(c=fgetc(it->fichierit)))) {
        mot[i++] = tolower(c);      
    }
    mot[i] = '\0'; 
    while (ispunct(c) || isspace(c)) {
        if (c == '.' || c == '?' || c == '!') { 
            it->finDePhrase = 1;
        }
        c = fgetc(it->fichierit);
        
    }
    if(c!=EOF){
        ungetc(c,it->fichierit);
    }   
    return mot;

}



void libereEspace(iterateur_t it){
    fclose(it->fichierit);
    free(it);
}

markov_t initMarkov(int seed,int size, char* chemin) {
    markov_t m = creerMarkov(seed, size);
    DIR *d;
    struct dirent *dir;
    char fichier[300];
    d = opendir(chemin);
    if (d != NULL) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ".txt") != NULL) {
                snprintf(fichier, 300, "%s/%s", chemin, dir->d_name);
                iterateur_t it = creerIterateur(fichier);
                char* mot = next(it);
                ajouterMotMarkov(m, mot);
                char* prev = mot;
                while (hasNext(it)) {
                    mot = next(it);
                    ajouterMotMarkov(m, mot);
                    augmenterPoidsEntre(m, get_identifiant(m->hachage, prev), get_identifiant(m->hachage, mot));
                    free(prev);
                    prev = mot;
                }
                free(mot);
                libereEspace(it); 
            }
        }
        closedir(d);
    }
    return m;
}
