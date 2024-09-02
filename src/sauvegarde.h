/**
Fichier sauvegarde.h
Auteur(s): Fauquette Mael
*/
#include <stdio.h>
#include <stdlib.h>
#ifndef __SAUVEGARDE_H__
#define __SAUVEGARDE_H__

/**
    Cette méthode créer un fichier dans le chemin donné avec un text dedans.
    @param text est le text qui sera contenu dans le fichier.
    @param chemin est le chemin ou le fichier ce trouvera.
    @requires text != null
    @requires chemin != null
*/
void creerFichier(char* text, char* chemin);


/**
    Cette méthode ouvre un fichier en mode "ajout" en renvoie le descripteur de fichier
    @param chemin est le chemin ou le fichier se trouve
    @requires chemin != null
    @return le descripteur de fichier
*/
FILE* ouvrirFichierAjout(char* chemin);


/**
    Cette méthode écrie une chaine de caractère dans le fichier.
    @param fichier est le descripteur de fichier ouvert en mode "ajout".
    @param chaine est la chaine de caractère qui sera dans le fichier.
    @requires fichier != null
    @requires chaine != null
*/
void chaineDansFichier(FILE* fichier, char* chaine);

#endif

