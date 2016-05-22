#include <stdlib.h>
#include <stdio.h>

void tensionImpulsion (int num_gpio)
{
	// -------------------------partie activation du gpio------------------------------------------------

	// Creation du nom de fichier et ouverture de celui-ci
	
    FILE *gpio = NULL;
   
    char fichier[128] = "";
    snprintf(fichier, sizeof fichier, "tensionNulle%d.txt", num_gpio);
	
	gpio = fopen(fichier, "w");
	
    if (gpio != NULL)
		{
		fputc('0', gpio);
        fclose(gpio), gpio = NULL;
		}
	
    else
		{
        printf("\nerreur lors de l'ecriture du gpio en allumage\n");
		}
	// ----------------------------------------------------------------------------

	// inserer une pause ici----

	// ------------------partie desactivation du gpio------------------------------------------------

	// Creation du nom de fichier et ouverture de celui-ci
	
    FILE *gpioB = NULL;
   
    char fichierB[128] = "";
    snprintf(fichierB, sizeof fichierB, "tensionNulle%d.txt", num_gpio);
	
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