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
#include "aide.h"
#include "traitementArgcArgv.h"
int main(int argc, char *argv[])
{
	int valeur1 = 99;
	int valeur2 = 99;

	if (argc == 1){MenuAide();return (0);}
	
	if (argc != 3){
	printf("\n\nErreur arguments, entrez domoticsduino pour obtenir de l'aide\n\n");
	return (0);
	}

//printf("parametre 1: %s\n",argv[1]);
//printf("parametre 2: %s\n",argv[2]);
// -----------------------------------------------------------------------
// Transformation en int	
	if (strcmp(argv[1], "0") == 0){valeur1 = 0;}
	if (strcmp(argv[1], "1") == 0){valeur1 = 1;}
	if (strcmp(argv[1], "2") == 0){valeur1 = 2;}
	if (strcmp(argv[1], "3") == 0){valeur1 = 3;}
	if (strcmp(argv[1], "4") == 0){valeur1 = 4;}
	if (strcmp(argv[1], "5") == 0){valeur1 = 5;}
	if (strcmp(argv[1], "6") == 0){valeur1 = 6;}
	if (strcmp(argv[1], "7") == 0){valeur1 = 7;}
	if (strcmp(argv[1], "8") == 0){valeur1 = 8;}
	if (strcmp(argv[1], "9") == 0){valeur1 = 9;}
	if (strcmp(argv[1], "10") == 0){valeur1 = 10;}
	if (strcmp(argv[1], "11") == 0){valeur1 = 11;}
	if (strcmp(argv[1], "12") == 0){valeur1 = 12;}
	if (strcmp(argv[1], "13") == 0){valeur1 = 13;}
	

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
	
	if (valeur1 == 99){return(0);}
	if (valeur2 == 99){return(0);}
	traitementArgcArgv (valeur1, valeur2);

	return (0);
}

