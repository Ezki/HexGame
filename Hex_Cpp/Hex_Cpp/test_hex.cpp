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

void initTest() {

	int joueur = 0;
	int indice = 0;
	int positionX = 0;
	int positionY = 0;
	int resultat = 0;
	int taille = 0;
	Plateau* hex = NULL;

	int* ppositionX = NULL;
	int* ppositionY = NULL;
	int* pindice = NULL;
	ppositionX = &positionX;
	ppositionY = &positionY;
	pindice = &indice;

	taille = 11;
	hex = (Plateau*)malloc((taille*taille) * sizeof(Plateau) + 19);



	//test d'initialiser_plateau
	initialiser_plateau(hex, taille);

	printf("\nTest d'initialiser plateau\n\n");

	assertEquals(Gris, hex[0].couleur, "test couleur case 0");
	assertEquals(Gris, hex[1].couleur, "test couleur case 1");
	assertEquals(Gris, hex[10].couleur, "test couleur case 10");
	assertEquals(Gris, hex[121].couleur, "test couleur case 121");
	assertEquals(Gris, hex[122].couleur, "test couleur case sans couleur allouée 122");

	//test de setColor

	printf("\nTest de setColor\n\n");

	setColor(hex, Rouge, 10);
	setColor(hex, Bleu, 22);
	assertEquals(Rouge, getColor(hex, 10), "test de la case 10");
	assertEquals(Bleu, getColor(hex, 22), "test de la case 22");

	//test de xy2int

	printf("\nTest de xy2int\n\n");

	positionX = 3;
	positionY = 7;
	assertEquals(69, xy2int(positionX, positionY, taille), "test de l'indice aux coordonnées x = 3 et y = 7");

	positionX = 1;
	positionY = 1;
	assertEquals(1, xy2int(positionX, positionY, taille), "test de l'indice aux coordonnées x = 1 et y = 1");

	positionX = 11;
	positionY = 11;
	assertEquals(121, xy2int(positionX, positionY, taille), "test de l'indice aux coordonnées x = 11 et y = 11");

	positionX = 0;
	positionY = -5;
	assertEquals(-66, xy2int(positionX, positionY, taille), "test de l'indice en dehors des valeurs de tableau x = 0 et y = -5");

	//test d'inputControl


	printf("\nTest d'inputControl\n\n");

	positionX = 0;
	positionY = 0;
	indice = xy2int(positionX, positionY, taille);
	assertFalse(inputControl(hex, ppositionX, ppositionY, taille, pindice), "test input control false quand x et y = 0");
	printf("\n");
	
	positionX = 5;
	positionY = 4;
	indice = xy2int(positionX, positionY, taille);
	assertTrue(inputControl(hex, ppositionX, ppositionY, taille, pindice), "test input control true quand x = 5 et y = 4");
	printf("\n");

	//test d'enregistrerCoup

	printf("\nTest d'inputControl\n\n");

	joueur = 1;
	indice = 22;
	enregistrerCoup(joueur, hex, taille, indice);
	assertEquals(Rouge, hex[indice].couleur, "Test enregistrer Coup avec Joueur 1");

	joueur = 2;
	indice = 23;
	enregistrerCoup(joueur, hex, taille, indice);
	assertEquals(Bleu, hex[indice].couleur, "Test enregistrer Coup avec Joueur 2");
	printf("\n");

	//test d'init_Memoire

	printf("\nTest d'init_Memoire\n\n");

	int memoire[61];
	init_Memoire(memoire, taille);
	assertEquals(-1, memoire[0], "Test de la case memoire 0");
	assertEquals(-1, memoire[10], "Test de la case memoire 10");
	assertEquals(-1, memoire[62], "Test de la case memoire non allouée 62");

	//test de test_Voisin

	printf("\nTest de test_Voisin\n\n");

	initialiser_plateau(hex, taille);
	assertEquals(Gris, hex[1].couleur, "test de la couleur de la 1re case après initialisation");
	
	hex[1].couleur = Rouge;
	hex[12].couleur = Rouge;
	hex[23].couleur = Rouge;
	hex[34].couleur = Rouge;
	hex[45].couleur = Rouge;
	hex[56].couleur = Rouge;
	hex[67].couleur = Rouge;
	hex[78].couleur = Rouge;
	hex[89].couleur = Rouge;
	hex[100].couleur = Rouge;
	assertEquals(Rouge, hex[1].couleur, "test de la couleur de la 1re case après ré-initialisation");
	indice = 1;
	assertEquals(0, test_Voisin(hex, indice, taille, memoire), "test des voisins sur une chaine pas finie de case rouge");

	hex[111].couleur = Rouge;
	assertEquals(1, test_Voisin(hex, indice, taille, memoire), "test des voisins sur une chaine finie de case rouge");

	init_Memoire(memoire, taille);
	hex[1].couleur = Bleu;
	hex[13].couleur = Bleu;
	hex[25].couleur = Bleu;
	hex[37].couleur = Bleu;
	hex[49].couleur = Bleu;
	hex[61].couleur = Bleu;
	hex[73].couleur = Bleu;
	hex[85].couleur = Bleu;
	hex[97].couleur = Bleu;
	hex[109].couleur = Bleu;
	
	hex[12].couleur = Bleu;
	hex[24].couleur = Bleu;
	hex[36].couleur = Bleu;
	hex[48].couleur = Bleu;
	hex[60].couleur = Bleu;
	hex[72].couleur = Bleu;
	hex[84].couleur = Bleu;
	hex[96].couleur = Bleu;
	hex[108].couleur = Bleu;
	indice = 1;
	assertEquals(0, test_Voisin(hex, indice, taille, memoire), "test des voisins sur une chaine pas finie de cases bleues");

	hex[120].couleur = Bleu;
	hex[121].couleur = Bleu;
	assertEquals(1, test_Voisin(hex, indice, taille, memoire), "test des voisins sur une chaine finie de cases bleues");

	printf("\nFin des tests\n\n\n");
}