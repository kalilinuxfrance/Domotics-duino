#include <stdlib.h>
#include <stdio.h>

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