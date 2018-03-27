#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Initialiser.h"

Couleur getColor(Plateau* hex, int indice) {
    return (hex[indice]).couleur;
}

void setColor(Plateau* hex, Couleur color, int indice) {
    (hex[indice]).couleur = color;
}


//Cette fonction sert à initialiser toutes les cellules
//du plateau de jeu à la valeur par défaut(ici gris).
void initialiser_plateau(Plateau* hex, int taille)
{
    int i;
    for (i = 1; i <= taille*taille; ++i)
    {
        setColor(hex, Gris, i);
    }
}


//Cette fonction est utilisé pour afficher le plateau de jeu en cours.
//La lettre R représente une cellule joué par le joueur rouge, B pour le joueur bleu.
//Une étoile représente une cellule vide donc disponible.
void afficherPlateau(Plateau* hex, int taille) {
    int ligne = 1;
    int longueur_tab = (taille) * (taille);
    
    for(int j = 1; j <= taille; ++j) {
        if(j < 10){
            printf(" %i ", j);
        } else {
            printf(" %i", j);
        }
    }
    
    printf("\n");
    
    for (int i = 1; i <= longueur_tab; ++i) {
            if(i == 1){
                printf("%i", i);
            }
            if (getColor(hex, i) == Rouge) {
                printf(" R ");
            }
            else if (getColor(hex, i) == Bleu) {
                printf(" B ");
            }
            else if (getColor(hex, i) == Gris) {
                printf(" * ");
            }
            else {
                printf("ERROR AFFICHAGE!\n");
            }
            if((i%taille+1) == 1){
                ligne+= 1;
                printf("\n");
                if(ligne <= taille) {
                    printf("%i", ligne);
                    for(int j = i/taille; j > 0; j--) {
                        printf(".");
                    }
                }
                
            }
        }
}

