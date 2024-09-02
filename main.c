/**
Fichier main.c
Auteur(s): Lavandier Agustin /Karkashadze Luka /Fauquette Mael /Mandin Paul
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"src/sauvegarde.h"
#include"src/hachage.h"
#include"src/markov.h"
#include"src/repertoire.h"

int main(int argc, char *argv[]){
  char* chemin = NULL;
  int seed = 0;
  int size =1000;
  if (argc < 2) {
    exit(EXIT_FAILURE);
  }

  chemin = argv[1];
  if (argc >= 3) {
    seed = atoi(argv[2]);
    srand(seed);
    if (argc >= 4) {
      size = atoi(argv[3]);
    } 
  }
  else {
    srand(time(NULL));
  }



  markov_t m=initMarkov(seed,size,chemin);
  int x=rand()%m->hachage->size;
  creerFichier("","rendu.txt");
  FILE* fichier=ouvrirFichierAjout("rendu.txt");
  for(int i=0;i<10;i++){
    int s =etatSuivant(m,x);
    char* mot =get_mot(m->hachage,s);
    chaineDansFichier(fichier,("%s",mot));
  }
  
  detruireMarkov(m);
  return EXIT_SUCCESS;
}



