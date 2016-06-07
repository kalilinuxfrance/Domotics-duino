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
#include "aide.h"
#include "configuration.h"
#include "status.h"
#include "traitementArgcArgv.h"
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
	
// gestion des exceptions config et autres...
	if (strcmp(argv[1], "--config") == 0){config(); return(0);}
	if (strcmp(argv[1], "--status") == 0){status(); return(0);}
	
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
	if (strcmp(argv[1], "3") == 0){valeur1 = 98;}
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

