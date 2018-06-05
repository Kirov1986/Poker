#ifndef CHECK_H
#define CHECK_H

#include "Struct.h"

CheckRes PairCheck(Player P, Card D[5], int m);
CheckRes DPairCheck(Player P, Card D[5], int m);
CheckRes ThreeCheck(Player P, Card D[5], int m);
CheckRes StraightCheck(Player P, Card D[5], int m);
CheckRes FlushCheck(Player P, Card D[5], int m);
CheckRes FullCheck(Player P, Card D[5], int m);
CheckRes FourCheck(Player P, Card D[5], int m);
CheckRes SFlushCheck(Player P, Card D[5], int m);
CheckRes RFlushCheck(Player P, Card D[5], int m);
CheckRes CombCheck(Player P, Card D[5], int m);
CheckRes WinnerCheck(Player P[MaxPlayers], int N, Card D[5], int m);

#endif // CHECK_H
