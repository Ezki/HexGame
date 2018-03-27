#include <stdio.h>
#include "Initialiser.h"
#include "Lire.h"
#include "choixJoueur.h"
#include "yx2int.h"
#include "JouerCoup.h"
#include "enregistrementCoupJoue.h"

//Cette fonction permet de valider et enregistrer le coup tenté par le joueur en cours.
//Elle fait intervenir la fonction "jouerCoup" directement à l'interieur
void enregistrerCoup (int joueur, Plateau* hex, int taille, int indice) {
    int longueur_tableau = taille*taille;
    for(int i = 1; i <= longueur_tableau; i++) {
            if(i == indice) {
                if(joueur == 1) {
                    setColor(hex, Rouge, indice);
                } else if(joueur == 2) {
                    setColor(hex, Bleu, indice);
                } else {
                    printf("ERROR ENREGISTREMENT\n");
                }
            }
        }
    
}
