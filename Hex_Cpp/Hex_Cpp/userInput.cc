#include <stdio.h>
#include <stdlib.h>
#include "Lire.h"
#include "userInput.h"
#define LONGUEUR_CHAINE 4

//Fonction sécurisée de lecture d'entrée par l'utilisateur.
int userInputForX(int taille) {
    int userInputX = 0;
    char userInput_X[LONGUEUR_CHAINE];
    
    printf("Quelle colonne de 1 à %i ?\n", taille);
    lire(userInput_X, sizeof(userInput_X));
    
    userInputX = (int)strtol(userInput_X, NULL, 10);
    
    return userInputX;
}

int userInputForY(int taille) {
    int userInputY = 0;
    char userInput_Y[LONGUEUR_CHAINE];
    
    printf("Quelle ligne de 1 à %i ?\n", taille);
    lire(userInput_Y, sizeof(userInput_Y));
    
    userInputY = (int)strtol(userInput_Y, NULL, 10);
    
    return userInputY;
}
