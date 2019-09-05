#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"

int calcPoids(long conv_nbrColis, long *poidsSup)
{
    int tranchePoids = 0;
    char longu[4];
    char larg[4];
    char haut[4];
    char poids[4];
    long conv_longu = 0, conv_larg = 0, conv_haut = 0, conv_poids = 0, compteur = 1;
    double poidsVolume = 0, poidsReel = 0;
    do
    {
        if (conv_nbrColis > 1)
        {
            printf("\nColis %ld\n", compteur);
        }
        printf("Longueur (cm) : ");
        conv_longu = lire(longu, 4);
        printf("Largeur (cm) : ");
        conv_larg = lire(larg, 4);
        printf("Hauteur (cm) : ");
        conv_haut = lire(haut, 4);
        printf("Poids (kg) : ");
        conv_poids = lire(poids, 4);
        compteur++;
        poidsVolume = (((conv_longu/100.00)*(conv_larg/100.00)*(conv_haut/100.00))*166.00);
        if (conv_poids < poidsVolume)
        {
            poidsReel += poidsVolume;
        }
        else
        {
            poidsReel += conv_poids;
        }
    } while (conv_nbrColis >= compteur);

    // Definition de la tranche de poids
    if (poidsReel >= 0 && poidsReel <= 2)
    {
        tranchePoids = 0;
    }
    else if (poidsReel >= 3 && poidsReel <= 5)
    {
        tranchePoids = 1;
    }
    else if (poidsReel >= 6 && poidsReel <= 10)
    {
        tranchePoids = 2;
    }
    else if (poidsReel >= 11 && poidsReel <= 15)
    {
        tranchePoids = 3;
    }
    else if (poidsReel >= 16 && poidsReel <= 20)
    {
        tranchePoids = 4;
    }
    else if (poidsReel >= 21 && poidsReel <= 30)
    {
        tranchePoids = 5;
    }
    else if (poidsReel >= 31 && poidsReel <= 40)
    {
        tranchePoids = 6;
    }
    else if (poidsReel >= 41 && poidsReel <= 50)
    {
        tranchePoids = 7;
    }
    else if (poidsReel >= 51 && poidsReel <= 60)
    {
        tranchePoids = 8;
    }
    else if (poidsReel >= 61 && poidsReel <= 70)
    {
        tranchePoids = 9;
    }
    else if (poidsReel >= 71 && poidsReel <= 80)
    {
        tranchePoids = 10;
    }
    else if (poidsReel >= 81 && poidsReel <= 90)
    {
        tranchePoids = 11;
    }
    else if (poidsReel >= 91 && poidsReel <= 100)
    {
        tranchePoids = 12;
    }
    else
    {
        tranchePoids = 12;
        *poidsSup = poidsReel - 100;
    }
    return tranchePoids;
}

int calcZone(char pays[1][3], int *fraisDossier)
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
            {
                zone = i;
                if (j == 0 && i == 1)
                {
                    *fraisDossier = 1;
                }
                else if (j == 0 && i == 2)
                {
                    *fraisDossier = 1;
                }
                else
                {
                    *fraisDossier = 0;
                }
            }
        }
    }
    if (zone <= -1)
    {
        printf("Erreur de saisie du code pays, veuillez ressaisir\n");
    }
    return zone;
}

double calcTarif(int poidsTranche, long poidsSup, int zone, long nbrColis, int fraisDossier)
{
    double prixBase = 0;
    const double carbu = 1.09;
    const double kSup[7] = { 2.60, 2.38, 3.58, 7.16, 9.47, 11.89, 14.27 };
    const double tableFD[2] = { 0, 76.87 };
    const double tablePrix[13][7] = {
    { 25.69, 37.77, 56.19, 122.26, 176.87, 191.94, 224.75 },
    { 28.53, 40.09, 59.91, 129.38, 186.37, 203.85, 239.04 },
    { 33.73, 44.80, 67.09, 143.62, 205.30, 227.74, 267.59 },
    { 41.31, 50.63, 76.19, 161.50, 228.98, 257.60, 303.28 },
    { 50.27, 56.46, 85.26, 179.33, 252.65, 287.45, 338.95 },
    { 59.34, 64.62, 98.00, 204.31, 285.80, 329.21, 388.90 },
    { 78.31, 76.29, 116.20, 240.04, 333.18, 388.90, 460.32 },
    { 99.62, 95.38, 144.84, 297.09, 408.95, 484.02, 574.49 },
    { 133.50, 119.40, 180.48, 368.47, 503.66, 602.78, 717.24 },
    { 156.57, 143.41, 216.20, 439.90, 598.46, 721.51, 859.99 },
    { 180.25, 176.73, 266.29, 539.66, 731.29, 887.73, 1059.57 },
    { 209.62, 216.30, 326.00, 658.37, 889.65, 1085.66, 1297.05 },
    { 241.75, 255.91, 385.69, 777.09, 1047.98, 1283.54, 1534.51 }
    };

    prixBase = (tablePrix[poidsTranche][zone] + (poidsSup * kSup[zone]) + (nbrColis * 0.20) + tableFD[fraisDossier] + 12.78) * carbu;

    return prixBase;
}

