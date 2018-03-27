#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "initialiser.h"
#include "lire.h"
#include "choixJoueur.h"
#include "yx2int.h"
#include "JouerCoup.h"
#include "enregistrementCoupJoue.h"
#include "testVoisin.h"
#include "sizeGameGridChoice.h"
#include "inputSecurity.h"
#include "unittest.h"
#include "test_hex.h"
#include "jeu.h"


void jeu(int* rejoue)
{
	//Déclaration des variables du jeu
	int joueur = 0;
	int indice = 0;
	int positionX = 0;
	int positionY = 0;
	int resultat = 0;
	int taille = 0;
	char choix[3];
	Plateau* hex = NULL;

	// Mettre le code de lancement du jeu ici
	taille = sizeGrid(taille);
	hex = (Plateau*)malloc((taille*taille) * sizeof(Plateau)+10); 
	initialiser_plateau(hex, taille);
	joueur = 1;

	//Boucle principale du jeu qui tourne tant qu'un joueur n'a pas gagné
	//la partie
	while (resultat != 1) {

		afficherPlateau(hex, taille);
		jouerCoup(&positionX, &positionY, hex, taille, joueur, &indice);
		enregistrerCoup(joueur, hex, taille, indice);
		resultat = init_Test_Voisin(hex, joueur, taille);
		changerJoueur(&joueur);
	}

	free(hex);

	//Goodbye!
	printf("\nVoila, la partie est finie !\nNous esperons que ce jeu vous a plu.\n\n\nL'Equipe : Francois et Louis\n");
	printf("\nVoulez-vous faire une nouvelle partie? \n 1-Oui\n 2-Non\n\n");
	lire(choix, sizeof(choix));
	*rejoue = (int)strtol(choix, NULL, 4);

}