
#ifndef testVoisin_h
#define testVoisin_h

#include <stdio.h>
#include <stdbool.h>


int init_Test_Voisin(Plateau* hex, int joueur, int taille);
int test_Voisin(Plateau* hex, int case_testee, int taille, int* memoire);
void init_Memoire (int* memoire, int taille);
void affecter_Memoire (int* memoire,int case_testee, int taille);
void desaffecter_Memoire (int* memoire, int taille);
bool detecter_Fin(Plateau* hex, int case_testee, int taille);
bool deja_Tester(int* memoire, int voisin);


#endif /* testVoisin_h */
