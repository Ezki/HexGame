#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Initialiser.h"


//Cette fonction est une booléenne de controle qui permet d'affirmer (ou pas) que la coordonnée proposée
//par le joueur en cours est valide.
bool inputControl(Plateau* hex, int* positionX, int* positionY, int taille, int* indice) {
    if((*positionX <= 0 || *positionX > taille) || (*positionY <= 0 || *positionY > taille)) {
        printf("********************************************\nVous avez entré de mauvaises coordonnées.\n");
        printf("Les coordonnées des cellules doivent être comprises entre 1 et %i.\n", taille);
        return false;
    } else if(getColor(hex, *indice) != Gris){
        printf("**************************************************\nImpossible. La case est déjà prise !! Try again...\n");
        return false;
    } else {
        printf("Vous avez choisi la position : %i pour la ligne et %i pour la colonne.\n", *positionY, *positionX);
        printf("Cette position est libre, votre coup est enregistré. Bravo !\n\n");
        return true;
    }
}
