#include"markov.h"
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>


markov_t creerMarkov(int seed, unsigned int size){
    int i;
    int j;
    markov_t m = malloc(sizeof(struct markov_s));
    m->hachage = creer_tab_hachage(size);
    m->matriceTransition = malloc(sizeof(int*)*m->hachage->size);
    for(i = 0; i < m->hachage->size; i++){
        m->matriceTransition[i] = malloc(sizeof(int) * m->hachage->size);
        for(j = 0; j < m->hachage->size; j ++)
            m->matriceTransition[i][j] = 0;
    }
    
    srand(seed);
    return m;
}



void detruireMarkov(markov_t m){
    int i;
    for(i = 0; i < m->hachage->size; i ++)
        free( m->matriceTransition[i] );
    free(m->matriceTransition);
    supp_tab_hachage(m->hachage);
    free(m);
}


void ajouterMotMarkov(markov_t m, char* mot){
    ajouter_mot(m->hachage, mot);
}



void augmenterPoidsEntre(markov_t m,  unsigned int e1, unsigned int e2){
    m->matriceTransition[e1][e2] += 1;
}



double probabiliteEntre(markov_t m, unsigned int e1, unsigned int e2){
    int i;
    double res = 0;
    int prob = m->matriceTransition[e1][e2];
    for(i = 0; i < m->hachage->size; i++){
        res += m->matriceTransition[e1][i];
    }
    res = prob/res;
    return res;
}



unsigned int etatSuivant(markov_t m, unsigned int e){
    unsigned int res = 0;
    double prob = 0;
    double rndm = (double)rand() / (double)RAND_MAX;

    for(res = 0; res < m->hachage->size; res ++){
        prob += probabiliteEntre(m, e, res);
        if(prob >= rndm) return res;
    }
    return e;
}