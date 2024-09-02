/**
Fichier repertoire.h
Auteur(s): Fauquette Mael
*/
#include <stdio.h>
#include <stdlib.h>
#include"sauvegarde.h"
#include"markov.h"
#include"hachage.h"
#ifndef __REPERTOIRE_H__
#define __REPERTOIRE_H__


struct iterateur_s{
    FILE* fichierit;
    int finDePhrase;
};

typedef struct iterateur_s * iterateur_t;

/**
    Cette fonction renvoie repertoiretialisé avec fichier. 
    @param fichier
    @requires fichier!=null
*/
iterateur_t creerIterateur(char* fichier);


/**
    Cette méthode vérifie si l'itérateur possède un lettre suivant.
    @param it est l'itérateur
    @requires it !=null
    @return 1 si it possède un lettre suivant 0 sinon.
*/
int hasNext(iterateur_t it);

/**
    Cette méthode renvoir le mot suivant.
    @param it est l'itérateur
    @requires it !=null
    @return le mot suivant et met à jour finDePhrase si le mot est une fin de phrase.
*/
char* next(iterateur_t it);

/**
    Fonction qui libère l'espace mémoire utilisée.
    @param it est l'itérateur que l'on veut fermer
*/
void libereEspace(iterateur_t it);

/**
    Cette fonction crée une chaine de markov
    @param seed la seed de probabilité
    @param size la taille de la chaine de markov
    @param repertoire  le repertoire qui comporte tout les fichiers à lire.
    @requires repertoire != null.
*/
markov_t initMarkov(int seed,int size,char* repertoire);

#endif

