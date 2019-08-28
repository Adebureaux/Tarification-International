#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
