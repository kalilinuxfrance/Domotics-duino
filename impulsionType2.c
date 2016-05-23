#include <stdlib.h>
#include <stdio.h>

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