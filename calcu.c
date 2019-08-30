#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"

int calcPoids(long nbrColis)
{
    int poids = 0, compteur = 1;
    double longu = 0, larg = 0, haut = 0, poidsVolume = 0, poidsReel = 0;
    do
    {
        if(nbrColis > 1)
        {
            printf("\nColis %d\n", compteur);
        }
        printf("Longueur (cm) : ");
        scanf("%lf", &longu);
        printf("Largeur (cm) : ");
        scanf("%lf", &larg);
        printf("Hauteur (cm) : ");
        scanf("%lf", &haut);
        printf("Poids (kg) : ");
        scanf("%lf", &poidsReel);
        compteur++;
        poidsVolume = (((longu/100.00)*(larg/100.00)*(haut/100.00))*166.00);
        if(poidsReel < poidsVolume)
        {
            poids = poidsVolume + poids;
        }
        else
        {
            poids = poidsReel + poids;
        }
    } while(nbrColis >= compteur);
    return poids;
}

int calcZone()
{
    int zone = 0;
    int result = 0;
    int i = 0;
    int j = 0;
    char *pays[1] = {"FR"};
    const char *zonePays[7][12] = {
    { "BE", "LU", "", "", "", "", "", "", "", "", "", "" },
    { "CH", "DE", "NL", "", "", "", "", "", "", "", "", "" },
    { "AD", "AC", "AT", "DK", "ES", "FI", "GB", "GR", "IE", "IT", "PT", "SE" },
    { "CZ", "EE", "HU", "LT", "LV", "NO", "PL", "SI", "SK", "", "", "" },
    { "GP", "US", "BG", "DZ", "HR", "MA", "RO", "TN", "", "", "", "" },
    { "CM", "BA", "", "", "", "", "", "", "", "", "", "" },
    { "SA", "", "", "", "", "", "", "", "", "", "", "" }
    };

    lire(pays, 3);


    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if(strncmp(pays[0], zonePays[i][j], 2) == 0)
                zone = i;
        }
    }


    printf("%d", zone);

    return zone;
}
