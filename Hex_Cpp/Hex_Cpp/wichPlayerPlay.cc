#include "wichPlayerPlay.h"

//Cette fonction permet d'afficher quel est
//le joueur qui doit jouer le jeu en cours.
void whoIsThePlayer(int joueur) {
    printf("C'est au tour du joueur ");
    if (joueur == 1)
        printf("ROUGE de jouer !\n");
    if (joueur == 2)
        printf("BLEU de jouer !\n");
}
