#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"
#include "calcu.h"

int main()
{
    char pays[1][3] = {""};

    int poids = 0;
    int zone = 0;

    char nbrColis[2];
    long conv_nbrColis = 0;

    printf("-------------------------------------------------------\n");
    printf("----            Calculateur de prix                ----\n");
    printf("----                   Fedex                       ----\n");
    printf("----               International                   ----\n");
    printf("-------------------------------------------------------\n\n");

    do
    {
    printf("Code pays : ");
    lire(*pays, 3);
    zone = calcZone(pays);
    } while (zone <= -1);
    
    
    printf("Zone %d\n", zone);

    printf("Nombre de colis : ");
    conv_nbrColis = lire(nbrColis, 3);
    poids = calcPoids(conv_nbrColis);




    return 0;
}
