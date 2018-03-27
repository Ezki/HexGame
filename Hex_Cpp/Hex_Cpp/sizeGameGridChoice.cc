#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sizeGameGridChoice.h"
#include "Lire.h"


int sizeGrid(int taille) {
    char user_input[4];
    do {
        printf("La taille minimum conseillée pour jouer au jeu d'Hex est de 3x3, de maximum 15x15.\nVeuillez entrer la taille de la grille (entre 3 et 15) sur laquelle vous souhaitez jouer ->\n");
        lire(user_input, sizeof(user_input));
        taille = (int)strtol(user_input, NULL, 10);
        printf("Vous avez choisi une grille de taille %d.\n\n", taille);
    }while(taille < 3 || taille > 15);
    
    return taille;
}



