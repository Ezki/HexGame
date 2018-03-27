#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdbool.h"
#include "Initialiser.h"
#include "Lire.h"
#include "choixJoueur.h"
#include "yx2int.h"
#include "JouerCoup.h"
#include "userInput.h"
#include "wichPlayerPlay.h"
#include "inputSecurity.h"
#define LONGUEUR_CHAINE 4


void jouerCoup (int *positionX, int *positionY, Plateau* hex, int taille, int joueur, int* indice) {
    bool isTrueInputControl;

    //une boucle infinie qui tourne tant que l'utilisateur ne rentre pas de bonnes coordonnées de jeu, càd :
    //une case libre et valide, à l'intérieur de la grille de jeu.1
    do {
        //accueil et présentation du joueur
        printf("\n*************************************************************\n");
        whoIsThePlayer(joueur);
        
        //saisie de la ligne
        *positionX = userInputForX(taille);
        
        //saisie de la colonne
        *positionY = userInputForY(taille);
        
        //Calcul de l'indice de la case du tableau (id la grille de Hex) en fonction de l'entrée utilisateur
        *indice = xy2int(*positionX, *positionY, taille);
        
        //Structure de controle des valeurs des coordonnées entrées par l'utilisateur.
        isTrueInputControl = inputControl(hex, positionX, positionY, taille, indice);
        
    } while (isTrueInputControl == false);
}
