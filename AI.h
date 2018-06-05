#ifndef AI_H
#define AI_H

#include "Struct.h"

double Combination(int n, int k);
double CountCard(int C);
int CountHand(Player P, int D, int Pos, int NPlayers);
double CountPWinFactor(Player P, Card D[5], int S);
double CountRWinFactor(Card D[5], int S);

#endif // AI_H
