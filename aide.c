#include <stdio.h>
#include <stdlib.h>

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