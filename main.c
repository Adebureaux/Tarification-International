#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ecriture.h"
#include "calcu.h"

int main(int argc, char *argv[])
{
    char pays[1][3] = {""};
    char nbrColis[1];
    char run[1];
    long conv_run = 0;
    long conv_nbrColis = 0;
    int poidsTranche = 0;
    int poidsSup = 0;
    int zone = 0;
    int ch = 0, ad = 0;

    int div = 0;
    double marge = 0, diviseurMarge = 0;
    double diviseur[40] = { 0.30, 0.40, 0.45, 0.50, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.60, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69, 0.70, 0.71, 0.72, 0.73, 0.735, 0.740, 0.745, 0.750, 0.755, 0.760, 0.765, 0.770, 0.775, 0.780, 0.785, 0.790, 0.795 };
do
{
    double prixBase = 0, prixMarge = 0, prixTTC = 0;

    printf("-------------------------------------------------------\n");
    printf("----            Calculateur de prix                ----\n");
    printf("----                   Fedex                       ----\n");
    printf("----               International                   ----\n");
    printf("-------------------------------------------------------\n\n");

    // Zone
    do
    {
        printf("Code pays : ");
        lire(*pays, 3);
        zone = calcZone(pays, &ch, &ad);
    } while (zone <= -1);
    printf("Zone %d\n\n", zone+1);

    // Tranche poids et poids supplementaire
    printf("Nombre de colis : ");
    conv_nbrColis = lire(nbrColis, 3);
    poidsTranche = calcPoids(conv_nbrColis,  &poidsSup);

    // Calcul du tarif
    prixBase = calcTarif(poidsTranche, poidsSup, zone, conv_nbrColis);
    printf("\n\nTarif d'achat : %.2lf Euros\n", prixBase);

    if (prixBase < 500)
    {
        div = prixBase / 12.5;
        diviseurMarge = diviseur[div];
    }
    else
    {
        diviseurMarge = 0.80;
    }

    prixMarge = prixBase / diviseurMarge;

    printf("Tarif de vente HT : %.2lf Euros\n", prixMarge);

    prixTTC = prixMarge * 1.2;
    printf("Tarif de vente TTC : %.2lf Euros\n", prixTTC);

    // Affichage de la marge
    marge = (1 - (diviseurMarge)) * 100;
    printf("Marge : %.0lf%%\n\n", marge);

    printf("Voulez-vous continuer ? 1 -> OUI 0 -> NON : ");
    conv_run = lire(run, 2);
    printf("\n\n\n\n\n");
} while (conv_run);

    return 0;
}
