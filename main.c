#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"

int main()
{
    char *pays[1][1] = {""};

    int poids = 0;

    char nbrColis[2];
    long conv_nbrColis = 0;

    printf("-------------------------------------------------------\n");
    printf("----            Calculateur de prix                ----\n");
    printf("----                   Fedex                       ----\n");
    printf("----               International                   ----\n");
    printf("-------------------------------------------------------\n\n");

    printf("Code pays : ");
    lire(pays, 3);
    printf("Nombre de colis : ");
    conv_nbrColis = lire(nbrColis, 3);
    poids = calcPoids(conv_nbrColis);



    return 0;
}
