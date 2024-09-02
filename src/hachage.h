#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
/**
Fichier hachage.h
Auteur(s):
MANDIN Paul
*/
#ifndef __HACHAGE_H__
#define __HACHAGE_H__


struct hachage_s{
    char **liste;
    size_t size;
};

typedef struct hachage_s * hachage_t;
 
/**
Fonction de création d'une table de hachage vide de taille donné en argument
@param size la taille de la table
@return un pointeur sur une table de hachage vide
*/

hachage_t creer_tab_hachage(size_t size);

/**
Fonction de suppression d'une table de hachage 
@param table la table à supprimer
*/

void supp_tab_hachage(hachage_t table);

/**
Fonction pour ajouter un mot à une certaine position dans la stable de hachage 
@param table la table où l'on ajoute le mot
@param mot le mot à ajouter dans la table
*/

void ajouter_mot(hachage_t table, char *mot);

/**
Fonction pour récuperer l'identifiant qui est aussi sa position dans la table d'un mot
@param mot le mot dont on veut l'identifiant
@return l'identifiant du mot
*/

unsigned int get_identifiant(hachage_t table, char *mot);

/**
Fonction pour récuperer le mot dans la table à partir de son identifiant/position
@param identifiant l'identifiant du mot a récuperer
@return mot dont on a entré l'identifiant
*/

char * get_mot(hachage_t table, unsigned int identifiant);

#endif
