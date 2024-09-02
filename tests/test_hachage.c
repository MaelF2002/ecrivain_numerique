#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"../src/hachage.h"
#include<stdio.h>
/**
Fichier test_hachage.c
Auteur(s): karkashadze_luka_21907996
*/

void test_creer_tab_hachage(){
    hachage_t table = creer_tab_hachage(5);

    assert(table->size == 5);

    for (int i = 0; i < table->size; i++) {
        assert(strcmp(table->liste[i], "") == 0);
    }

    supp_tab_hachage(table);
}

void test_supp_tab_hachage() {
    hachage_t table = creer_tab_hachage(20);
    char *mot1 = "hello";
    char *mot2 = "world";
    ajouter_mot(table, mot1);
    ajouter_mot(table, mot2);
    assert(strcmp(table->liste[get_identifiant(table, mot1)], mot1) == 0);
    assert(strcmp(table->liste[get_identifiant(table, mot2)], mot2) == 0);

    supp_tab_hachage(table);
}


void test_ajouter_mot() {
    hachage_t table = creer_tab_hachage(20);    
    char *mot1 = "hello";
    char *mot2 = "world";
    ajouter_mot(table, mot1);
    ajouter_mot(table, mot2);
    assert(strcmp(table->liste[get_identifiant(table, mot1)], mot1) == 0);
    assert(strcmp(table->liste[get_identifiant(table, mot1)], mot2) != 0);
    assert(strcmp(table->liste[get_identifiant(table, mot2)], mot2) == 0);
    assert(strcmp(table->liste[get_identifiant(table, mot2)], mot1) != 0);
    supp_tab_hachage(table);
}



void test_get_identifiant() {
    hachage_t table = creer_tab_hachage(20);
    assert(get_identifiant(table, "hello") != get_identifiant(table, "olelh"));
    assert(get_identifiant(table, "world") != get_identifiant(table, "dlorw"));
    assert(get_identifiant(table, "hello") == get_identifiant(table, "hello"));
    assert(get_identifiant(table, "world") == get_identifiant(table, "world"));

    assert(get_identifiant(table, "hello") >= 0 && get_identifiant(table, "hello") < 20);
    assert(get_identifiant(table, "world") >= 0 && get_identifiant(table, "world") < 20);    supp_tab_hachage(table);
}


void test_get_mot() {
    hachage_t table = creer_tab_hachage(20);
    ajouter_mot(table, "hello");
    ajouter_mot(table, "world");
    assert(strcmp(get_mot(table, get_identifiant(table, "hello")), "hello") == 0);
    assert(strcmp(get_mot(table, get_identifiant(table, "hello")), "world") != 0);
    assert(strcmp(get_mot(table, get_identifiant(table, "world")), "world") == 0);
    assert(strcmp(get_mot(table, get_identifiant(table, "world")), "hello") != 0);
    supp_tab_hachage(table);
}


int main(int argc, char *argv[]) {
  test_creer_tab_hachage();
  test_supp_tab_hachage();
  test_ajouter_mot();
  test_get_identifiant();
  test_get_mot();
  printf("Hachage passed.\n");
  return EXIT_SUCCESS;
}



