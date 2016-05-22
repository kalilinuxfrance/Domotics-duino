#include <stdio.h>
#include <stdlib.h>
#include "aide.h"
#include "impulsionType0.h"
#include "impulsionType1.h"
#include "impulsionType2.h"

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