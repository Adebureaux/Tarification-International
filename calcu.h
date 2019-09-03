#ifndef CALCU_H_INCLUDED
#define CALCU_H_INCLUDED

int calcPoids(long nbrColis, int *poidsSup);
int calcZone(char pays[1][3], int *ch, int *ad);
double calcTarif(int poidsTranche, int poidsSup, int zone, long nbrColis);

#endif // CALCU_H_INCLUDED
