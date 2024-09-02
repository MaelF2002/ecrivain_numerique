#include"hachage.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


hachage_t creer_tab_hachage(size_t size){
    hachage_t table= malloc(sizeof(struct hachage_s));
    
    table->liste = malloc(size * sizeof(char*));
    table->size = size;
    
    for (int i = 0; i < table->size; i++) {
        table->liste[i] = malloc(50 * sizeof(char));
    }
    return table;
}



void supp_tab_hachage(hachage_t table){
    for (int i = 0; i < table->size; i++) {
        free(table->liste[i]);
    }
    free(table->liste);
    free(table);
}



void ajouter_mot(hachage_t table, char *mot){
    unsigned int position = get_identifiant(table, mot);
    
    strcpy(table->liste[position] , mot);
}


unsigned int get_identifiant(hachage_t table, char *mot){
    unsigned int id = 0;
    size_t length = strlen(mot); 
    for (size_t i = 0; i < length; i++){
        id+= mot[i] * (i+1);
    }

    id = id%table->size;
    return id;
}


char * get_mot(hachage_t table, unsigned int identifiant){
    return table->liste[identifiant]; 
}
