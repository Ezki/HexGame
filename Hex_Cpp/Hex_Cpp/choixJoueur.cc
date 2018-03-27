#include "choixJoueur.h"

//Simple fonction de changement de joueur.
void changerJoueur(int* joueur) {
    if(*joueur == 1) {
        *joueur = 2;
    } else if(*joueur == 2) {
        *joueur = 1;
    } else {
        printf("PLAYER CHANGE ERROR!");
    }
}
