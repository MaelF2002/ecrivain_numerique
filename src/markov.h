/**
Fichier markov.h
Auteur(s): LAVANDIER Augustin
*/
#ifndef __MARKOV_H__
#define __MARKOV_H__

// Vous travaillerez ici

#include"hachage.h"


struct markov_s
{
    hachage_t hachage;
    int ** matriceTransition;
};


typedef struct markov_s * markov_t;



/**
 * Cette fonction renvoie une chaîne de Markov possédant la graine aléatoire mise en argument
 * @param seed est la graîne aléatoire dont dépend la chaîne de Markov
 * @param size est le nombre maximum de mots que l'on peut mettre dans notre chaine
 * @requires size != NULL
 * @requires seed != NULL
 * @ensures resultat != NULL
 * @return markov_t la chaîne de Markov initialisée avec la seed mise en argument
 */
markov_t creerMarkov(int seed, unsigned int size);


/**
 * Cette fonction libère l'espace mémoire alloué à la chaîne de Markov mise en argument
 * @param m est la chaîne de Markov qui sera supprimée et dont l'espace mémoire sera libéré
 * @requires m != NULL
 */
void detruireMarkov(markov_t m);


/**
 * Cette fonction ajoute le mot à la chaine de markov m
 * @param m est la chaîne de Markov a qui se verra ajouter le mot mot
 * @param mot est la chaine de caracteres qui sera ajouté à la chaine
 * @requires m != NULL
 * @requires mot != NULL 
 * 
 */
void ajouterMotMarkov(markov_t m, char* mot);



/**
 * Cette fonction augmente le poids entre deux états dans la chaîne de Markov m
 * @param m est la chaîne de Markov dont les poids des états seront augmentés
 * @param e1 est l'état initial
 * @param e2 est l'état suivant
 * @requires m != NULL && e1 != NULL && e2 != NULL
 * @requires e1 < m->hachage->taille && e2 < m->hachage->taille
 * @ensures debut m->matriceTransition[e1][e2] == fin m->matriceTransition[e1][e2] +1
 */
void augmenterPoidsEntre(markov_t m,  unsigned int e1, unsigned int e2);


/**
 * Cette fonction calcul la probabilité de passer d'un état e1 à un état e2 dans la chaine de Markov m
 * @param m  est la chaîne de Markov dans laquelle nous allons calculer les probabilités
 * @param e1  est l'état initial
 * @param e2  est l'état suivant
 * @requires m != NULL && e1 != NULL && e2 != NULL
 * @requires e1 < m->hachage->taille && e2 < m->hachage->taille
 * @ensures resultat >= 0 && resultat <= 1
 * @return Un double représentant la probabilité de passer de l'état e1 à l'état e2 dans la chaîne de Markov m
 */
double probabiliteEntre(markov_t m, unsigned int e1, unsigned int e2);


/**
 * Cette fonction renvoie un état aléatoirement choisi parmi les voisins de l'état de départ e dans la chaîne de Markov
 * @param m 
 * @param e 
 * @requires m != NULL && e != NULL
 * @requires e < m->hachage->taille && e >= 0
 * @return unsigned int l'état aléatoirement choisi, voisin de celui de départ
 */
unsigned int etatSuivant(markov_t m, unsigned int e);



#endif