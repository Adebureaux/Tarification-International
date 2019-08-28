//
//  ecriture.c
//  Tarification
//
//  Created by Augustin Debureaux on 18/08/2019.
//  Copyright © 2019 Augustin Debureaux. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

long lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;
    
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        positionEntree = strchr(chaine, '\n');
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';
        }
        else
        {
            viderBuffer();
        }
        return strtol(chaine, NULL, 10);
    }
    else
    {
        printf("Erreur buffer\n");
        viderBuffer();
        return 0;
    }
}
