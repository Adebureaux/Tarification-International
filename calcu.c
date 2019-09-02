#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"

int calcPoids(long nbrColis)
{
    int tranchePoids = 0, poids = 0, compteur = 1;
    double longu = 0, larg = 0, haut = 0, poidsVolume = 0, poidsReel = 0;
    do
    {
        if (nbrColis > 1)
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
        if (poidsReel < poidsVolume)
        {
            poids = poidsVolume + poids;
        }
        else
        {
            poids = poidsReel + poids;
        }
    } while (nbrColis >= compteur);


    // Definition de la tranche de poids
    if (poids >= 0 && poids <= 2)
    {
        tranchePoids = 0;
    }
    else if (poids >= 3 && poids <= 5)
    {
        tranchePoids = 1;
    }
    else if (poids >= 6 && poids <= 10)
    {
        tranchePoids = 2;
    }
    else if (poids >= 11 && poids <= 15)
    {
        tranchePoids = 3;
    }
    else if (poids >= 16 && poids <= 20)
    {
        tranchePoids = 4;
    }
    else if (poids >= 21 && poids <= 30)
    {
        tranchePoids = 5;
    }
    else if (poids >= 31 && poids <= 40)
    {
        tranchePoids = 6;
    }
    else if (poids >= 41 && poids <= 50)
    {
        tranchePoids = 7;
    }
    else if (poids >= 51 && poids <= 60)
    {
        tranchePoids = 8;
    }
    else if (poids >= 61 && poids <= 70)
    {
        tranchePoids = 9;
    }
    else if (poids >= 71 && poids <= 80)
    {
        tranchePoids = 10;
    }
    else if (poids >= 81 && poids <= 90)
    {
        tranchePoids = 11;
    }
    else if (poids >= 91 && poids <= 100)
    {
        tranchePoids = 12;
    }

    return tranchePoids;
}

int calcZone(char pays[1][3])
{
    int zone = -1;
    int i = 0;
    int j = 0;
    const char *zonePays[7][12] = {
    { "BE", "LU", "", "", "", "", "", "", "", "", "", "" },
    { "CH", "DE", "NL", "", "", "", "", "", "", "", "", "" },
    { "AD", "AC", "AT", "DK", "ES", "FI", "GB", "GR", "IE", "IT", "PT", "SE" },
    { "CZ", "EE", "HU", "LT", "LV", "NO", "PL", "SI", "SK", "", "", "" },
    { "GP", "US", "BG", "DZ", "HR", "MA", "RO", "TN", "", "", "", "" },
    { "CM", "BA", "", "", "", "", "", "", "", "", "", "" },
    { "SA", "", "", "", "", "", "", "", "", "", "", "" }
    };


    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (strncmp(pays[0], zonePays[i][j], 2) == 0)
                zone = i;
        }
    }
    if (zone <= -1)
    {
        printf("Erreur de saisie de la zone, veuillez ressaisir\n");
    }


    return zone;
}

int calcTarif()
{

}
