#ifndef Initialiser_h
#define Initialiser_h

#include <stdio.h>

typedef enum Couleur Couleur;
enum Couleur
{
    Bleu, Rouge, Gris
};

typedef struct Plateau Plateau;
struct Plateau
{
    Couleur couleur;
};

void initialiser_plateau(Plateau* p, int taille);
Couleur getColor(Plateau* hex, int indice);
void setColor(Plateau* hex, Couleur color, int indice);
void afficherPlateau(Plateau* hex, int taille);



#endif /* Initialiser_h */

