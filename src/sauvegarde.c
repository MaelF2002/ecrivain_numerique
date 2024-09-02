/**
Fichier sauvegarde.c
Auteur(s): Fauquette Mael
*/

#include <stdio.h>
#include <stdlib.h>
#include"sauvegarde.h"

void creerFichier(char* text, char* chemin){
    if(text !=NULL && chemin != NULL){
        FILE* fichier = fopen(chemin, "w");
        fprintf(fichier, "%s", text);
        fclose(fichier);
    }
}

FILE* ouvrirFichierAjout(char* chemin){
    if(chemin != NULL){
        FILE* fichier = fopen(chemin, "a");
        return fichier;

    }
}

void chaineDansFichier(FILE* fichier, char* chaine){
    if(fichier!=NULL && chaine !=NULL){
        fprintf(fichier, "%s ", chaine);
        
    }
}

