#include <stdio.h>
#include <stdlib.h>

void MenuAide()
{


printf("Domotics-duino v0.1(https://github.com/kalilinuxfrance/Domotics-duino)\n");
printf("Usage: domoticsduino [Impulsion Type] [Adresse GPIO]\n");
printf("\nIMPULSION TYPE\n");
printf("\t0 : Pas de tension aux bornes du gpio\n");
printf("\t1 : Tension aux bornes du gpio\n");
printf("\t2 : Tension aux bornes du gpio de courte duree\n");
printf("\nADRESSE GPIO\n");
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
printf("\t10\n");
printf("\t11\n");
printf("\t12\n");
printf("\t13\n");
printf("\nEXAMPLES:\n");
printf("\tdomoticsduino 2 3 : Cree une impulsion pour enclencher le telerupteur de la cuisine\n");
}