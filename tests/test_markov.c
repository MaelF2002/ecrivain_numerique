#include<stdlib.h>
#include<assert.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include"../src/markov.h"
#include<stdio.h>
/*
Fichier test_markov.c
user : Karkashadze_luka_21907996
*/
void test_creerMarkov(){
  srand( time( NULL ) );
  unsigned int r = rand();
  markov_t mrkv = creerMarkov(r,20);
  assert(mrkv != NULL);
  assert(mrkv->hachage != NULL);
  assert(mrkv->matriceTransition != NULL);
  detruireMarkov(mrkv);
}

void test_detruireMarkov(){
  srand( time( NULL ) );
  unsigned int r = rand();
  markov_t mrkv = creerMarkov(r,20);
  detruireMarkov(mrkv);
}

void test_ajouterMotMarkov(){
  srand( time( NULL ) );
  unsigned int r = rand();
  markov_t mrkv = creerMarkov(r,50);
  ajouterMotMarkov(mrkv, "Bonjour");
  ajouterMotMarkov(mrkv, "Le");  
  ajouterMotMarkov(mrkv, "Bon");
  ajouterMotMarkov(mrkv, "Monde");
  assert(strcmp(mrkv->hachage->liste[get_identifiant(mrkv->hachage, "Bonjour")], "Bonjour") == 0);
  assert(strcmp(mrkv->hachage->liste[get_identifiant(mrkv->hachage, "Bonjour")], "Bon")!= 0);
  assert(strcmp(mrkv->hachage->liste[get_identifiant(mrkv->hachage, "Le")], "Le") == 0);
  assert(strcmp(mrkv->hachage->liste[get_identifiant(mrkv->hachage, "Bon")], "Bon")== 0);
  assert(strcmp(mrkv->hachage->liste[get_identifiant(mrkv->hachage, "Monde")], "Monde") == 0);
  assert(strcmp(mrkv->hachage->liste[get_identifiant(mrkv->hachage, "Monde")], "onde") != 0);
  detruireMarkov(mrkv);
}

void test_augmenterPoidsEntre(){
  srand( time( NULL ) );
  unsigned int r = rand();
  markov_t mrkv = creerMarkov(r,20);
  unsigned int pr = rand() % (mrkv->hachage->size);
  unsigned int sg = rand() % (mrkv->hachage->size);
  unsigned int i = mrkv->matriceTransition[pr][sg];
  augmenterPoidsEntre(mrkv, pr, sg);
  assert(mrkv->matriceTransition[pr][sg] == i+1);
  detruireMarkov(mrkv);
}

void test_probabiliteEntre(){
  srand( time( NULL ) );
  unsigned int r = rand();
  markov_t mrkv = creerMarkov(r,50);
  unsigned int pr = rand() % (mrkv->hachage->size);
  unsigned int sg = rand() % (mrkv->hachage->size);
  unsigned int tr = rand() % (mrkv->hachage->size);

  unsigned int p1 = rand()%100;
  unsigned int p2 = rand()%100;
  for(int i = 0; i < p1; i++){
    augmenterPoidsEntre(mrkv,  pr, sg);
  }  
  for(int j = 0; j < p2; j++){
    augmenterPoidsEntre(mrkv,  pr, tr);
  }
  mrkv->matriceTransition[pr][sg];
  mrkv->matriceTransition[pr][tr];
  unsigned int pg = p1+p2;
  //assert(probabiliteEntre(mrkv,pr,sg)+probabiliteEntre(mrkv,pr,tr) == 1);
  //assert(probabiliteEntre(mrkv,pr,sg)*pg == p1);
  assert(probabiliteEntre(mrkv,pr,sg) <= 1 && probabiliteEntre(mrkv,pr,sg) >= 0);
  assert(probabiliteEntre(mrkv,pr,tr)*pg == p2);
  assert(probabiliteEntre(mrkv,pr,tr) <= 1 && probabiliteEntre(mrkv,pr,tr) >= 0);
  detruireMarkov(mrkv);
}

void test_etatSuivant(){
  srand( time( NULL ) );
  unsigned int r = rand();
  markov_t mrkv = creerMarkov(r,50);

  unsigned int pr = rand() % (mrkv->hachage->size);
  unsigned int sg = rand() % (mrkv->hachage->size);
  unsigned int tr = rand() % (mrkv->hachage->size);

  unsigned int p1 = rand()%100;
  unsigned int p2 = rand()%100;

  for(int i = 0; i < p1; i++){
    augmenterPoidsEntre(mrkv,  pr, sg);
  }  
  for(int j = 0; j < p2; j++){
    augmenterPoidsEntre(mrkv,  pr, tr);
  }

  unsigned int e = 0;

  mrkv->matriceTransition[pr][sg];
  mrkv->matriceTransition[pr][tr];


  for (int i = 0; i < 100; i++) {
    e = etatSuivant(mrkv, pr);
    assert(e == sg || e == tr);
  }

  detruireMarkov(mrkv);
}


int main(int argc, char *argv[]) {
  test_creerMarkov();
  test_detruireMarkov();
  test_ajouterMotMarkov();
  test_augmenterPoidsEntre();
  test_probabiliteEntre();
  test_etatSuivant();
  printf("Markov passed.\n");
  return EXIT_SUCCESS;
}


