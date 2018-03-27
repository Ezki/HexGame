#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Initialiser.h"
#include "testVoisin.h"
#include "whoIsTheWinner.h"

int init_Test_Voisin(Plateau* hex, int joueur, int taille)
// On crée le tableau memoire permettant de vérifier qu'on ne teste pas 2 fois la même case dans une même chaine,
// puis on teste si une des cases du haut est bleue ou une des cases de gauche est rouge.
// Si oui, on lance la fonction de test des voisins.
{

    int i, resultat = 0;
    
    int* memoire = NULL;
    memoire = (int*)malloc(((taille*taille)/2) * sizeof(int));   // On alloue à la mémoire une taille de la moitié des cases possibles du tableau (pas possible pour une couleur d'avoir plus que la moitié des cases occupées)
    
    
    switch (joueur) 
	// Si joueur rouge, on teste si une des cases de la rangée du haut est rouge.
	// Si joueur bleu, on teste si une des cases de la rangée de gauche est bleue.
    {
        case 1:
            for (i = 1; i <= taille; ++i)
            {
                if (getColor(hex, i) == Rouge)
                {
					init_Memoire(memoire, taille);
                    resultat = test_Voisin(hex, i, taille, memoire);
                }
            }
            break;
            
        case 2:
            for (i = 0; (i * taille) < (taille * taille) - taille + 1 ; ++i)
            {
                if (getColor(hex, i*taille+1) == Bleu)
                {
					init_Memoire(memoire, taille); // Fonction qui réinitialise les valeurs de "memoire" avant chaque appel de Test_Voisin
                    resultat = test_Voisin(hex, (i*taille + 1), taille, memoire); // si sur la case étudiée, le test est concluant, on regarde la couleur des voisins de cette case
                }
            }
            break;
            
        default:
            printf("PLAYER ERROR IN THE SWITCH LOOP IN INIT_TEST_VOISIN");
            break;
    }
    
	free(memoire);
    
    if (resultat == 1)
    {
        printf("\n!!!!!!!VICTORY!!!!!!!!!\n");
        whoIsTheWinner(joueur);
        afficherPlateau(hex, taille);
		return 1;
    }
    else
    {
        printf ("La partie n'est pas terminée! Continuez...\n\n");
		return 0;
    }
}


int test_Voisin(Plateau* hex, int case_testee, int taille, int* memoire)
// Vérifie que la case testée est une des cases permettant la victoire
// Sinon, test si l'une des 6 cases voisines de la case testée partage sa couleur, n'a pas encore été testée, et appartient au plateau.
// Si oui, appelle test_Voisin avec cette nouvelle case en paramètre
{
    if (detecter_Fin (hex, case_testee, taille) == true)
    {
        return 1;
    }
    
    else
    {
        int y = 0; // valeur de la case voisine
        affecter_Memoire(memoire, case_testee, taille); // Inscrit la valeur de la case testée dans "memoire", pour éviter de retester cette case plus loin dans la chaîne de tests
        
        y = (case_testee - taille);                    // Test 1 en haut à gauche
        if (!(y < 0)) // test que la case voisine est bien dans la zone de jeu
        {
            if(getColor(hex, y) == getColor(hex, case_testee)) // test que la voisine a la même couleur que la case testée
            {
                if (deja_Tester(memoire, y) == false) // test que la voisine n'a pas déja été testée
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1) // lance le test_Voisin suivant
                        return 1;
                }
                
            }
        }
        
        y = (case_testee - taille + 1);              // Test 2 en haut à droite
        if (!(y < 0) && !(case_testee % taille == 0))
        {
            if(getColor(hex, y) == getColor(hex, case_testee))
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee - 1);                        // Test 3 à gauche
        if (!(case_testee % taille == 1))
        {
            if(getColor(hex, y) == getColor(hex, case_testee))
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee + 1);                        // Test 4 à droite
        if (!(case_testee % taille == 0))
        {
            if(getColor(hex, y) == getColor(hex, case_testee))
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee + taille - 1);              // Test 5 en bas à gauche
        if (!(y > taille * taille) && !(case_testee % taille == 1))
        {
            if(getColor(hex, y) == getColor(hex, case_testee))
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
        
        y = (case_testee + taille);                    // Test 6 en bas à droite
        if (!(y > taille * taille))
        {
            if(getColor(hex, y) == getColor(hex, case_testee))
            {
                if (deja_Tester(memoire, y) == false)
                {
                    if (test_Voisin(hex, y, taille, memoire) == 1)
                        return 1;
                }
                
            }
        }
		desaffecter_Memoire(memoire, taille); // retire la valeur mémoire de la case testée du tableau, afin qu'elle puisse être retestée dans une autre chaîne possible.
    }
    return 0;
}


void init_Memoire (int* memoire, int taille) // On met toutes les valeurs du tableau memoire à - 1 (fonction appelée avant de lancer un test_Voisin)
{
    int i  = 0;
    for (i=0; i < (taille*taille) / 2 ; i++)
    {
        memoire[i] = -1;
    }
}

// ??? add comments
void affecter_Memoire (int* memoire, int case_testee, int taille) // On remplace la premiËre case inocuppÈe du tableau par la valeur de la case testÈe (fonction appelée au début de test_Voisin)
{
    int i, j = 0;
    for (i=0; i < (taille*taille) / 2 && j == 0 ; i++)
    {
        if (memoire[i] == -1)
        {
            memoire[i] = case_testee;
            ++j;
        }
    }
}

// ??? add comments
void desaffecter_Memoire (int* memoire, int taille) // On remplace la dernière valeur de mémoire du tableau par -1 (fonction appelée à la fin de test_Voisin, pour que le tableau mémoire ne contienne que les cases effectivement parcourues au cours du test)
{
    int i, j = 0;
    for (i=0; i < (taille*taille) / 2 && j == 0; i++)
    {
		if (memoire[i] == -1)
		{
			memoire[i - 1] = -1;
			++j;
		}
    }
}


bool detecter_Fin(Plateau* hex, int case_testee, int taille)
// on détecte si la couleur de la case à tester est bleue ou rouge.

{
    int i = 0;
    int j = 0; // valeur de la case de la ligne finale
    if(getColor(hex, case_testee) == Bleu) // 
    {
        for (i=0;i<taille;i++)
        {
            j = (taille*(i+1));
            if(case_testee==j)
            {
                return true;
            }
        }
    }
    else if(getColor(hex, case_testee) == Rouge)
    {
        for(i=0; i<taille; i++)
        {
            j=(taille*taille) - taille + 1 + i;
            if(case_testee==j)
            {
                return true;
            }
        }
    }
    return false;
    
}


bool deja_Tester(int* memoire, int voisin) // Permet de vérifier, dans test_Voisin, que la case voisine testée n'a pas déjà été parcourue au cours de la chaîne de test)
{
    int i;
    for (i = 0; memoire[i] != -1; ++i)
    {
        if (memoire[i] == voisin)
            return true;
    }
    return false;
}


