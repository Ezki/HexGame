#include "yx2int.h"

//Fonction donnée par le professeur qui permet de calculer l'indice d'une grille de jeu
//en fonction de coordonnées.
int xy2int(int x, int y, int taille) {
    return x + (y-1)*taille;
}

