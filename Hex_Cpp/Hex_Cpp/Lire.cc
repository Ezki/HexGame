#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lire.h"


//Fonction personnalisée de lecture d'entrée saisie par l'utilisateur avec securisation des entrées.
int lire(char* chaine, int lon) {
    char *positionEntree = NULL;
    if (fgets(chaine, lon, stdin) != NULL) {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL) {
            *positionEntree = '\0';
        }
        return 1;
    }
    else {
        viderBuffer();
        return 0;
    }
}

//Fonction annexe qui permet de vider le buffer a chaque entree utilisateur.
//Elle est insérée directement dans la fonction LIRE.
void viderBuffer(void) {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}


