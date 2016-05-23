/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2016 julien <kali.linux.france@gmail.com>
 * 
 * domotics-duino is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * domotics-duino is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MenuAide();
void tensionNulle (int num_gpio);
void tensionPositive (int num_gpio);
void tensionImpulsion (int num_gpio);
void traitementArgcArgv(int a,int b);


int main(int argc, char *argv[])
{
	int valeur1 = 99; // valeur pour gerer les erreurs
	int valeur2 = 99; // valeur pour gerer les erreurs
	
// test pour afficher l'aide
	if (argc == 1) // si pas d'arguments rentrés
		{
			MenuAide();
			return (0);
		}
// test pour verifier le bon nombre d'arguments juste 2
	if (argc != 3)
		{
			printf("\n\nErreur arguments, entrez domoticsduino pour obtenir de l'aide\n\n");
			return (0);
		}

// -----------------------------------------------------------------------
// Transformation en int des arguments de type char
	if (strcmp(argv[1], "0") == 0){valeur1 = 0;}
	if (strcmp(argv[1], "1") == 0){valeur1 = 1;}
	if (strcmp(argv[1], "2") == 0){valeur1 = 2;}
// -----------------------------------------------------------------------
// Transformation en int des arguments de type char
	if (strcmp(argv[2], "0") == 0){valeur2 = 0;}
	if (strcmp(argv[2], "1") == 0){valeur2 = 1;}
	if (strcmp(argv[2], "2") == 0){valeur2 = 2;}
	if (strcmp(argv[2], "3") == 0){valeur2 = 3;}
	if (strcmp(argv[2], "4") == 0){valeur2 = 4;}
	if (strcmp(argv[2], "5") == 0){valeur2 = 5;}
	if (strcmp(argv[2], "6") == 0){valeur2 = 6;}
	if (strcmp(argv[2], "7") == 0){valeur2 = 7;}
	if (strcmp(argv[2], "8") == 0){valeur2 = 8;}
	if (strcmp(argv[2], "9") == 0){valeur2 = 9;}
	if (strcmp(argv[2], "10") == 0){valeur2 = 10;}
	if (strcmp(argv[2], "11") == 0){valeur2 = 11;}
	if (strcmp(argv[2], "12") == 0){valeur2 = 12;}
	if (strcmp(argv[2], "13") == 0){valeur2 = 13;}
// -----------------------------------------------------------------------
// gestion des erreurs
	if (valeur1 == 99){printf("\n\nErreur arguments, entrez domoticsduino pour obtenir de l'aide\n\n"); return(0);}
	if (valeur2 == 99){printf("\n\nErreur arguments, entrez domoticsduino pour obtenir de l'aide\n\n"); return(0);}
// si pas d'erreur en parametre on commence a traiter les arguments
	traitementArgcArgv (valeur1, valeur2);
	return (0); // return (0) de fin d'execution normale du main()
}


void MenuAide()
{
printf("\nDomotics-duino v0.1 by Julien Amrein(https://github.com/kalilinuxfrance/Domotics-duino)\n");
printf("GNU General Public License.\n");
printf("ATTENTION: Penser a configurer le mode output des gpio a controler avec la valeur 1 dans:\n/sys/devices/virtual/misc/gpio/mode/.\n\n");
printf("Usage:\tdomoticsduino [Impulsion Type] [Adresse GPIO]\n");
printf("\nIMPULSION TYPE\n");
printf("\t0 : Pas de tension aux bornes du gpio (Exemple: Allumage pompe d'arrosage)\n");
printf("\t1 : Tension aux bornes du gpio        (Exemple: Extinction pompe d'arrosage)\n");
printf("\t2 : Tension aux bornes du gpio pendant 1 seconde (Exemple: telerupteurs pour eclairage)\n");
printf("ADRESSE GPIO\n");
printf("\t0\t-N/A\n");
printf("\t1\t-Salon\n");
printf("\t2\t-Salle a manger\n");
printf("\t3\t-Cuisine\n");
printf("\t4\t-Fond EST\n");
printf("\t5\t-Fond OUEST\n");
printf("\t6\t-Exterieur EST\n");
printf("\t7\t-Exterieur SUD\n");
printf("\t8\t-Exterieur OUEST\n");
printf("\t9\t-Exterieur NORD\n");
printf("\t10\t-N/A\n");
printf("\t11\t-N/A\n");
printf("\t12\t-N/A\n");
printf("\t13\t-N/A\n");
printf("EXAMPLES:\n");
printf("\tdomoticsduino 2 3 : Cree une impulsion pour enclencher le telerupteur de la cuisine\n");
}


void traitementArgcArgv(int a,int b)
{
	// envoi du parametre b correspondant aux numero du gpio a faire travailler
	if (a == 0)// mode tension nulle
		{
		tensionNulle(b);
		}

	if (a == 1)// mode tension positive
		{
		tensionPositive(b);
		}

	if (a == 2)// mode tension positive type impulsion pour telerupteur
		{
		tensionImpulsion(b);
		}
	
}







void tensionNulle (int num_gpio)
{
	// Creation du nom de fichier et ouverture de celui-ci
	
    FILE *gpio = NULL;
   
    char fichier[128] = "";
    snprintf(fichier, sizeof fichier, "/sys/devices/virtual/misc/gpio/pin/gpio%d", num_gpio);
	
	gpio = fopen(fichier, "w");
	
    if (gpio != NULL)
		{
		fputc('0', gpio);
        fclose(gpio), gpio = NULL;
		}
	
    else
		{
        printf("\nerreur lors de l'ecriture du gpio\n");
		}
}





void tensionPositive (int num_gpio)
{
	// Creation du nom de fichier et ouverture de celui-ci
	
    FILE *gpio = NULL;
   
    char fichier[128] = "";
    snprintf(fichier, sizeof fichier, "/sys/devices/virtual/misc/gpio/pin/gpio%d", num_gpio);
	
	gpio = fopen(fichier, "w");
	
    if (gpio != NULL)
		{
		fputc('1', gpio);
        fclose(gpio), gpio = NULL;
		}
	
    else
		{
        printf("\nerreur lors de l'ecriture du gpio\n");
		}
}





void tensionImpulsion (int num_gpio)
{
	// -------------------------partie activation du gpio------------------------------------------------

	// Creation du nom de fichier et ouverture de celui-ci
	
    FILE *gpio = NULL;
   
    char fichier[128] = "";
    snprintf(fichier, sizeof fichier, "/sys/devices/virtual/misc/gpio/pin/gpio%d", num_gpio);
	
	gpio = fopen(fichier, "w");
	
    if (gpio != NULL)
		{
		fputc('1', gpio);
        fclose(gpio), gpio = NULL;
		}
	
    else
		{
        printf("\nerreur lors de l'ecriture du gpio en allumage\n");
		}
	// ----------------------------------------------------------------------------
	
	system("sleep 1"); // Pause en appel system
	
	/* inserer une pause ici en C -------------------------------------
	int compteur = 0;
	int compteur2 = 0;
	for (compteur = 0; compteur <= 10 ; compteur++ )
		printf(".");
		for (compteur2 = 0; compteur2 <= 99999999 ; compteur2++ )
		; // instruction vide norme
	*/

	// ------------------partie desactivation du gpio------------------------------------------------

	// Creation du nom de fichier et ouverture de celui-ci
	
    FILE *gpioB = NULL;
   
    char fichierB[128] = "";
    snprintf(fichierB, sizeof fichierB, "/sys/devices/virtual/misc/gpio/pin/gpio%d", num_gpio);
	
	gpioB = fopen(fichierB, "w");
	
    if (gpioB != NULL)
		{
		fputc('0', gpioB);
        fclose(gpioB), gpioB = NULL;
		}
	
    else
		{
        printf("\nerreur lors de l'ecriture du gpio en extinction\n");
		}
	
	// ----------------------------------------------------------------------------



}