#include<stdlib.h>
#include<assert.h>
#include"../src/sauvegarde.h"
#include<time.h>
#include<string.h>
#include<stdio.h>
/*
Fichier test_sauvegarde.c
user : Karkashadze_luka_21907996
*/

void test_creerFichier() {
    char* text = "Hello, world!";
    char chemin[20];
    srand(time(NULL));

    int random = rand() % 100;
    sprintf(chemin, "fichier%d.txt", random);
    
    creerFichier(text, chemin);
    
    FILE* fichier = fopen(chemin, "r");
    char contenu[100];
    fgets(contenu, 100, fichier);
    fclose(fichier);

    assert(strcmp(contenu, text) == 0);

    remove(chemin);
}

void test_ouvrirFichierAjout() {
    srand(time(NULL));
    char chemin[20];
    int random = rand() % 100;
    sprintf(chemin, "test%d.txt", random);

    char contenu[100];
    FILE* fichier = ouvrirFichierAjout(chemin);
    fprintf(fichier, "Test d'écriture dans le fichier\n");
    fclose(fichier);

    fichier = fopen(chemin, "r");
    assert(fichier != NULL);
    fgets(contenu, 100, fichier);
    fclose(fichier);
    assert(strcmp(contenu, "Test d'écriture dans le fichier\n") == 0);

    remove(chemin);
}

void test_chaineDansFichier() {
    srand(time(NULL));
    int random = rand() % 100;

    char chemin[20];
    sprintf(chemin, "fichier%d.txt", random);

    FILE* fichier = ouvrirFichierAjout(chemin);

    char chaine[100];
    sprintf(chaine, "Hello, world! %d", random);

    chaineDansFichier(fichier, chaine);

    fclose(fichier);

    fichier = fopen(chemin, "r");
    char contenu[100];
    fgets(contenu, 100, fichier);
    assert(strcmp(contenu,chaine) == 32);

    fclose(fichier);
    remove(chemin);
}
int main(int argc, char *argv[]) {
  test_creerFichier();
  test_ouvrirFichierAjout();
  test_chaineDansFichier();
  printf("Sauvegarde passed.\n");
  return EXIT_SUCCESS;
}
