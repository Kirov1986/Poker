#ifndef AI_CPP
#define AI_CPP

#include "Struct.h"
#include "Check.h"
#include "AI.h"

double Combination(int n, int k) {
    int i;
    double tmp1, tmp2, tmp3;
    double Res;

    tmp1 = 1;
    tmp2 = 1;
    tmp3 = 1;
    for (i = 2; i <= n; i++) tmp1 = tmp1 * i;
    for (i = 2; i <= n - k; i++) tmp2 = tmp2 * i;
    for (i = 2; i <= k; i++) tmp3 = tmp3 * i;
    Res = tmp1 / (tmp2 * tmp3);

    return Res;
}

double CountCard(int C) {
    double Res;
    Res = ((C - 2.0) / 12) + 1;
    return Res;
}

int CountHand(Player P, int D, int Pos, int NPlayers) {
    int i;
    int Res = 0;

    for (i = 0; i < 2; i++) {
        if (P.Cards[i].Level < 10) Res += P.Cards[i].Level;
        if (P.Cards[i].Level > 9 && P.Cards[i].Level < 14) Res += (P.Cards[i].Level + 1);
        if (P.Cards[i].Level == 14) Res += (P.Cards[i].Level + 2);
    }
    if (P.Cards[0].Level == P.Cards[1].Level) Res += 10;
    if (P.Cards[0].Suit == P.Cards[1].Suit) Res += 4;
    for (i = 1; i < 4; i++) {
        if (abs(P.Cards[0].Level - P.Cards[1].Level) == i) Res += (4 - i);
    }
    if (NPlayers - D + Pos > NPlayers / 2) Res += 3;
    if (NPlayers - D + Pos > NPlayers / 1.5) Res += 2;

    return Res;
}


double CountPWinFactor(Player P, Card D[5], int S) {
    int i, j, k, n, l, z;
    CheckRes Result;
    double Probability;
    double Res = 0;

    Result = CombCheck(P, D, S);
    switch (Result.R[0]) {
    case 0 :
        if (P.Cards[0].Level > P.Cards[1].Level) Res += CountCard(P.Cards[0].Level);
        else Res += CountCard(P.Cards[1].Level);
    case 1:
        if (Result.R[0] == 1) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[1]) * 2;
        }
        else if (S < 5) {
            k = 0;
            Probability = 0;
            while (k < 5 - S) {
                Probability += 3.0 / (50 - S - k);
                ++k;
            }
            for (i = 0; i < 2; i++) Res += CountCard(P.Cards[i].Level) * 2 * Probability;
        }
    case 2:
        if (Result.R[0] == 2) {
            if (Result.R[3] == 1) Res += (CountCard(Result.R[1]) + CountCard(Result.R[2])) * 2;
        }
        else {
            if (Result.R[0] == 0 && S < 4) {
                Probability = (3.0 / (50 - S)) * (3.0 / (50 - S - 1));
                Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 2 * Probability;
                for (i = 0; i < S; i++) {
                    Res += (CountCard(P.Cards[0].Level) + CountCard(D[i].Level)) * 2 * Probability;
                    Res += (CountCard(P.Cards[1].Level) + CountCard(D[i].Level)) * 2 * Probability;
                }
            }
            if (Result.R[0] == 1 && Result.R[3] == 0 && S < 5) {
                k = 0;
                Probability = 0;
                while (k < 5 - S) {
                    Probability += 3.0 / (50 - S - k);
                    ++k;
                }
                for (i = 0; i < 2; i++) Res += (CountCard(P.Cards[i].Level) + CountCard(Result.R[1])) * 2 * Probability;
            }
            if (Result.R[0] == 1 && Result.R[3] == 1 && S < 5) {
                k = 0;
                Probability = 0;
                while (k < 5 - S) {
                    Probability += 3.0 / (50 - S - k);
                    ++k;
                }
                for (i = 0; i < 2; i++) if (P.Cards[i].Level != Result.R[1]) k = i;
                Res += (CountCard(P.Cards[k].Level) + CountCard(Result.R[1])) * 2 * Probability;
                for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(Result.R[1]) + CountCard(D[i].Level)) * 2 * Probability;
            }
        }
    case 3:
        if (Result.R[0] == 3) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[1]) * 8;
        }
        else {
            if ((Result.R[0] == 0 && S < 4) || (Result.R[0] == 1 && Result.R[3] == 0 && S < 4)) {
                Probability = (3.0 / (50 - S)) * (2.0 / (50 - S - 1));
                for (i = 0; i < 2; i++) Res += CountCard(P.Cards[i].Level) * 8 * Probability;
            }
            if (Result.R[0] == 1 && Result.R[3] == 1) {
                Probability = (3.0 / (50 - S)) * (2.0 / (50 - S - 1));
                for (i = 0; i < 2; i++) if (P.Cards[i].Level != Result.R[1]) k = i;
                Res += CountCard(P.Cards[k].Level) * 8 * Probability;
                k = 0;
                Probability = 0;
                while (k < 5 - S) {
                    Probability += (3.0 - k) / (50 - S - k);
                    ++k;
                }
                Res += CountCard(Result.R[1]) * 8 * Probability;
            }
            if (Result.R[0] == 2 && Result.R[3] == 1) {
                Probability = (3.0 / (50 - S)) * (2.0 / (50 - S - 1));
                for (i = 0; i < 2; i++) for (j = 1; j < 3; j++) if (P.Cards[i].Level == Result.R[j]) k = i;
                k = abs(k - 1);
                Res += CountCard(P.Cards[k].Level) * 8 * Probability;
                k = 0;
                Probability = 0;
                while (k < 5 - S) {
                    Probability += (3.0 - k) / (50 - S - k);
                    ++k;
                }
                for (i = 0; i < 2; i++) for (j = 1; j < 3; j++) if (P.Cards[i].Level == Result.R[j]) k = i;
                Res += CountCard(P.Cards[k].Level) * 8 * Probability;
            }
        }
    case 4:
        if (Result.R[0] == 4) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[1]) * 16;
        }
        else {
            for (i = 2; i < 11; i++) if ((P.Cards[0].Level >= i && P.Cards[0].Level <= i + 4) || (P.Cards[1].Level >= i && P.Cards[1].Level <= i + 4)) {
                n = 0;
                for (k = 0; k < 5; k++) {
                    l = 0;
                    for (j = 0; j < S; j++) if (D[j].Level == i + k) l = 1;
                    for (j = 0; j < 2; j++) if (P.Cards[j].Level == i + k) l = 1;
                    n += l;
                }
                if (n == 3 && S < 4) {
                    Probability = (4.0 / (50 - S)) * (4.0 / (50 - S - 1));
                    Res += CountCard(i) * 16 * Probability;
                }
                if (n == 4 && S < 5) {
                    k = 0;
                    while (k < 5 - S) {
                        Probability += 4.0 / (50 - S - k);
                        ++k;
                    }
                    Res += CountCard(i) * 16 * Probability;
                }
            }
        }
    case 5:
        if (Result.R[0] == 5) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[2]) * 20;
        }
        else {
            for (i = 0; i < NSuits; i++) if (P.Cards[0].Suit == i || P.Cards[1].Suit == i) {
                n = 0;
                l = 0;
                for (j = 0; j < S; j++) if (D[j].Suit == i) {
                    n += 1;
                    if (D[j].Level > l) l = D[j].Level;
                }
                for (j = 0; j < 2; j++) if (P.Cards[j].Suit == i) {
                    n += 1;
                    if (P.Cards[j].Level > l) l = P.Cards[j].Level;
                }
                if (n == 3 && S < 4) {
                    Probability = (10.0 / (50 - S)) * (9.0 / (50 - S - 1));
                    Res += CountCard(l) * 20 * Probability;
                }
                if (n == 4 && S < 5) {
                    k = 0;
                    while (k < 5 - S) {
                        Probability += 9.0 / (50 - S - k);
                        ++k;
                    }
                    Res += CountCard(l) * 20 * Probability;
                }
            }
        }
    case 6:
        if (Result.R[0] == 6) {
            if (Result.R[3] == 1) Res += (CountCard(Result.R[1]) + CountCard(Result.R[2])) * 20;
        }
        else {
            if (Result.R[0] == 1 && Result.R[3] == 0 && S < 4) {
                Probability = (2.0 / (50 - S)) * (3.0 / (50 - S - 1));
                for (i = 0; i < 2; i++) Res += (CountCard(P.Cards[i].Level) + CountCard(Result.R[1])) * 40 * Probability;
            }
            if (Result.R[0] == 1 && Result.R[3] == 1 && S < 4) {
                Probability = (2.0 / (50 - S)) * (3.0 / (50 - S - 1));
                for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(Result.R[1]) + CountCard(D[i].Level)) * 40 * Probability;
                Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 40 * Probability;
            }
            if (Result.R[0] == 2 && Result.R[3] == 1 && S < 5) {
                k = 0;
                while (k < 5 - S) {
                    Probability += 3.0 / (50 - S - k);
                    ++k;
                }
                for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(D[i].Level) + CountCard(Result.R[1])) * 20 * Probability;
                Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 20 * Probability;
                if (S < 4) {
                    Probability = (2.0 / (50 - S)) * (3.0 / (50 - S - 1));
                    Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 20 * Probability;
                }
            }
            if (Result.R[0] == 3 && Result.R[3] == 0 && S < 5) {
                k = 0;
                while (k < 5 - S) {
                    Probability += 3.0 / (50 - S - k);
                    ++k;
                }
                for (i = 0; i < 2; i++) Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 20 * Probability;
                if (S < 4) {
                    Probability = (2.0 / (50 - S)) * (3.0 / (50 - S - 1));
                    Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 20 * Probability;
                }
            }
            if (Result.R[0] == 3 && Result.R[3] == 1 && S < 5) {
                k = 0;
                while (k < 5 - S) {
                    Probability += 3.0 / (50 - S - k);
                    ++k;
                }
                for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(D[i].Level) + CountCard(Result.R[1])) * 20 * Probability;
                Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 20 * Probability;
                if (S < 4) {
                    Probability = (2.0 / (50 - S)) * (3.0 / (50 - S - 1));
                    for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(D[i].Level) + CountCard(Result.R[1])) * 20 * Probability;
                    Res += (CountCard(P.Cards[0].Level) + CountCard(P.Cards[1].Level)) * 20 * Probability;
                }
            }
        }
    case 7:
        if (Result.R[0] == 7) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[1]) * 80;
        }
        else {
            if ((Result.R[0] == 1 || Result.R[0] == 2) && Result.R[3] == 1 && S < 4) {
                Probability = (2.0 / (50 - S)) * (1.0 / (50 - S - 1));
                Res += CountCard(Result.R[1]) * 80 * Probability;
            }
            if (Result.R[0] == 3 && Result.R[3] == 1 && S < 5){
                k = 0;
                while (k < 5 - S) {
                    Probability += 3.0 / (50 - S - k);
                    ++k;
                }
                Res += CountCard(Result.R[1]) * 80 * Probability;
            }
        }
    case 8:
        if (Result.R[0] == 8) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[1]) * 160;
        }
        else {
            for (i = 2; i < 11; i++) for (j = 0; j < NSuits; j++) if ((P.Cards[0].Level >= i && P.Cards[0].Level <= i + 4 && P.Cards[0].Suit == j) || (P.Cards[1].Level >= i && P.Cards[1].Level <= i + 4 && P.Cards[1].Suit == j)) {
                n = 0;
                for (k = 0; k < 5; k++) {
                    l = 0;
                    for (z = 0; z < S; z++) if (D[z].Level == i + k && D[z].Suit == j) l = 1;
                    for (z = 0; z < 2; z++) if (P.Cards[z].Level == i + k && P.Cards[z].Suit == j) l = 1;
                    n += l;
                }
                if (n == 3 && S < 4) {
                    Probability = (1.0 / (50 - S)) * (1.0 / (50 - S - 1));
                    Res += CountCard(i) * 160 * Probability;
                }
                if (n == 4 && S < 5) {
                    k = 0;
                    while (k < 5 - S) {
                        Probability += 1.0 / (50 - S - k);
                        ++k;
                    }
                    Res += CountCard(i) * 160 * Probability;
                }
            }
        }
    case 9:
        if (Result.R[0] == 9) {
            if (Result.R[3] == 1) Res += CountCard(Result.R[1]) * 270;
        }
        else {
            for (i = 0; i < NSuits; i++) if ((P.Cards[0].Level >= 10 && P.Cards[0].Level <= 14 && P.Cards[0].Suit == i) || (P.Cards[1].Level >= 10 && P.Cards[1].Level <= 14 && P.Cards[1].Suit == i)) {
                n = 0;
                for (k = 0; k < 5; k++) {
                    l = 0;
                    for (j = 0; j < S; j++) if (D[j].Level == 10 + k && D[j].Suit == i) l = 1;
                    for (j = 0; j < 2; j++) if (P.Cards[j].Level == 10 + k && P.Cards[j].Suit == i) l = 1;
                    n += l;
                }
                if (n == 3 && S < 4) {
                    Probability = (1.0 / (50 - S)) * (1.0 / (50 - S - 1));
                    Res += CountCard(i) * 270 * Probability;
                }
                if (n == 4 && S < 5) {
                    k = 0;
                    while (k < 5 - S) {
                        Probability += 1.0 / (50 - S - k);
                        ++k;
                    }
                    Res += CountCard(i) * 270 * Probability;
                }
            }
        }
    }

    return Res;
}

double CountRWinFactor(Card D[5], int S) {
    int i, j, k, n, l, z;
    CheckRes Result;
    Player Dummy;
    double Probability;
    double Res = 0;

    Dummy.Cards[0].Level = 0;
    Dummy.Cards[0].Suit = -1;
    Dummy.Cards[1].Level = 1;
    Dummy.Cards[1].Suit = -2;
    Result = CombCheck(Dummy, D, S);

    switch (Result.R[0] + 1) {
    case 0:
        i = 0;
    case 1:
        Probability = 3.0 / (50 - S);
        for (i = 0; i < S; i++) Res += CountCard(D[i].Level) * 2 * Probability;
    case 2:
        if (Result.R[0] == 0) {
            Probability = (3.0 / (50 - S)) * (3.0 / (50 - S));
            for (i = 0; i < S; i++) Res += CountCard(D[i].Level) * 4 * Probability;
        }
        if (Result.R[0] == 1) {
            Probability = 3.0 / (50 - S);
            for (i = 0; i < S; i++) Res += CountCard(Result.R[1]) * 4 * Probability;
            Probability = (3.0 / (50 - S)) * (3.0 / (50 - S));
            for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += CountCard(D[i].Level) * 4 * Probability;
        }
    case 3:
        if (Result.R[0] == 0) {
            Probability = (3.0 / (50 - S)) * (2.0 / (50 - S));
            for (i = 0; i < S; i++) Res += CountCard(D[i].Level) * 8 * Probability;
        }
        if (Result.R[0] == 1) {
            Probability = 2.0 / (50 - S);
            for (i = 0; i < S; i++) Res += CountCard(Result.R[1]) * 8 * Probability;
            Probability = (3.0 / (50 - S)) * (2.0 / (50 - S));
            for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += CountCard(D[i].Level) * 8 * Probability;
        }
        if (Result.R[0] == 2) {
            Probability = 2.0 / (50 - S);
            for (i = 0; i < S; i++) for (j = 1; j < 3; j++) Res += CountCard(Result.R[j]) * 8 * Probability;
        }
    case 4:
        for (i = 2; i < 11; i++) {
            n = 0;
            for (k = 0; k < 5; k++) {
                l = 0;
                for (j = 0; j < S; j++) if (D[j].Level == i + k) l = 1;
                n += l;
            }
            switch (n) {
            case 1:
                Probability = (4.0 / (50 - S)) * (4.0 / (50 - S - 1)) * (4.0 / (50 - S - 2)) * (4.0 / (50 - S - 3));
                break;
            case 2:
                Probability = (4.0 / (50 - S)) * (4.0 / (50 - S - 1)) * (4.0 / (50 - S - 2));
                break;
            case 3:
                Probability = (4.0 / (50 - S)) * (4.0 / (50 - S - 1));
                break;
            case 4:
                Probability = 4.0 / (50 - S);
                break;
            }
            Res += CountCard(i) * 16 * Probability;
        }
    case 5:
        for (i = 0; i < NSuits; i++) {
            n = 0;
            l = 0;
            for (j = 0; j < S; j++) if (D[j].Suit == i) {
                ++n;
                if (D[j].Level > l) l = D[j].Level;
            }
            switch (n) {
            case 1:
                Probability = (13.0 / (50 - S)) * (12.0 / (50 - S - 1)) * (11.0 / (50 - S - 2)) * (10.0 / (50 - S - 3));
                break;
            case 2:
                Probability = (12.0 / (50 - S)) * (11.0 / (50 - S - 1)) * (10.0 / (50 - S - 2));
                break;
            case 3:
                Probability = (11.0 / (50 - S)) * (10.0 / (50 - S - 1));
                break;
            case 4:
                Probability = 10.0 / (50 - S);
                break;
            }
            Res += CountCard(l) * 20 * Probability;
        }
    case 6:
        if (Result.R[0] == 1) {
            Probability = (2.0 / (50 - S)) * (3.0 / (50 - S - 1));
            for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(Result.R[1]) + CountCard(D[i].Level)) * 40 * Probability;
        }
        if (Result.R[0] == 3) {
            Probability = 3.0 / (50 - S);
            for (i = 0; i < S; i++) if (D[i].Level != Result.R[1]) Res += (CountCard(Result.R[1]) + CountCard(D[i].Level)) * 20 * Probability;
        }
    case 7:
        if (Result.R[0] == 1) {
            Probability = (2.0 / (50 - S)) * (1.0 / (50 - S - 1));
            for (i = 0; i < S; i++) Res += CountCard(Result.R[1]) * 80 * Probability;
        }
        if (Result.R[0] == 3) {
            Probability = 1.0 / (50 - S);
            for (i = 0; i < S; i++) Res += CountCard(Result.R[1]) * 80 * Probability;
        }
    case 8:
        for (i = 2; i < 11; i++)  for (j = 0; j < NSuits; j++) {
            n = 0;
            for (k = 0; k < 5; k++) {
                l = 0;
                for (z = 0; z < S; z++) if (D[z].Level == i + k && D[z].Suit == j) l = 1;
                n += l;
            }
            switch (n) {
            case 1:
                Probability = (4.0 / (50 - S)) * (3.0 / (50 - S - 1)) * (2.0 / (50 - S - 2)) * (1.0 / (50 - S - 3));
                break;
            case 2:
                Probability = (3.0 / (50 - S)) * (2.0 / (50 - S - 1)) * (1.0 / (50 - S - 2));
                break;
            case 3:
                Probability = (2.0 / (50 - S)) * (1.0 / (50 - S - 1));
                break;
            case 4:
                Probability = 1.0 / (50 - S);
                break;
            }
            Res += CountCard(i) * 160 * Probability;
        }
    case 9:
        for (i = 0; i < NSuits; i++) {
            n = 0;
            for (k = 0; k < 5; k++) {
                l = 0;
                for (j = 0; j < S; j++) if (D[j].Level == 10 + k && D[j].Suit == i) l = 1;
                n += l;
            }
            switch (n) {
            case 1:
                Probability = (4.0 / (50 - S)) * (3.0 / (50 - S - 1)) * (2.0 / (50 - S - 2)) * (1.0 / (50 - S - 3));
                break;
            case 2:
                Probability = (3.0 / (50 - S)) * (2.0 / (50 - S - 1)) * (1.0 / (50 - S - 2));
                break;
            case 3:
                Probability = (2.0 / (50 - S)) * (1.0 / (50 - S - 1));
                break;
            case 4:
                Probability = 1.0 / (50 - S);
                break;
            }
            Res += CountCard(i) * 270 * Probability;
        }
    }
    return Res;
}

#endif
