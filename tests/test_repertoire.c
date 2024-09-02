#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include"../src/repertoire.h"
#include"../src/sauvegarde.h"
#include<stdio.h>
/*
Fichier test_repertoire.c
user : Karkashadze_luka_21907996
*/

void test_creerIterateur() {
    creerFichier("", "test.txt");
    iterateur_t it = creerIterateur("test.txt");
    assert(it != NULL);
    assert(it->finDePhrase == 0);
    libereEspace(it);
}

void test_hasNext() {
    creerFichier("", "test.txt");
    iterateur_t it = creerIterateur("test.txt");
    chaineDansFichier(ouvrirFichierAjout("test.txt"),"Bonjour monde");
    assert(hasNext(it) == 1);
    while (hasNext(it)) {
        char* mot = next(it);
        free(mot);
    }
    assert(hasNext(it) == 0);
    libereEspace(it);
    remove("test.txt");
}

void test_next() {
    iterateur_t it = creerIterateur("test.txt");
    assert(strcmp(next(it), "ceci") == 0);
    assert(strcmp(next(it), "est") == 0);
    assert(strcmp(next(it), "un") == 0);
    assert(strcmp(next(it), "test") == 0);
    assert(strcmp(next(it), "de") == 0);
    assert(strcmp(next(it), "texte") == 0);
    assert(next(it) == NULL);
    libereEspace(it);
}

void test_libereEspace() {
    iterateur_t it = creerIterateur("test.txt");
    libereEspace(it);
}


void test_initMarkov() {
    markov_t m = initMarkov(42, 1000, "tests");
    assert(m != NULL);
    assert(m->hachage->size > 0);
    assert(m->hachage != NULL);
    detruireMarkov(m);
}

int main(int argc, char *argv[]){
    test_creerIterateur();
    //test_hasNext();
    //test_next();
    test_libereEspace();
    test_initMarkov();
    printf("Repertoire passed.\n");
    return EXIT_SUCCESS;
}

