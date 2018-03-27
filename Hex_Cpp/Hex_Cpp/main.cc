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


int main()
{
	int compteur_rejoue = 1;
	int* pcompteur_rejoue = NULL;
	pcompteur_rejoue = &compteur_rejoue;
	do // Boucle qui permet de relancer le jeu si l'utilisateur le souhaite
	{

		char choix[3];
		int n_choix = 0;
		
		
		do
		{
			printf("Bienvenue sur notre projet de Hex\n\n");
			printf("Choisissez ce que vous voulez faire\n\n 1 - Lancer une nouvelle partie\n 2 - Tester le bon fonctionnement du jeu\n 3 - Quitter\n");
			lire(choix, sizeof(choix));
			int n_choix = (int)strtol(choix, NULL, 10);

			switch (n_choix)
			{

			case 1:

				//fonction du jeu
				jeu(pcompteur_rejoue);

				break;

			case 2:

				// Lancer la fonction de test
				initTest();

				break;

			case 3:

				// Quitter le jeu
				exit(0);
				break;

			default:

				printf("Votre choix n'est pas bon\n\n");
				
				break;

			}
			
			
		} while (n_choix < 1 || n_choix > 3);

	} while (compteur_rejoue != 2);


	printf("Le jeu va maintenant se fermer.\n ");

    return 0;

}

