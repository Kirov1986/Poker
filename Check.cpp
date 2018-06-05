#ifndef CHECK_CPP
#define CHECK_CPP

#include "Struct.h"
#include "Check.h"

CheckRes PairCheck(Player P, Card D[5], int m) {
    int i, j, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
            tmp = C[j];
            C[j] = C[i];
            C[i] = tmp;
        }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < N - 1; i++) if (C[i].Level == C[i + 1].Level) {
        Res.R[0] = 1;
        Res.R[1] = C[i].Level;
        for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level) Res.R[3] = 1;
        break;
    }

    return Res;
}

CheckRes DPairCheck(Player P, Card D[5], int m) {
    int i, j, z, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
            tmp = C[j];
            C[j] = C[i];
            C[i] = tmp;
        }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    z = N;
    for (i = 0; i < N - 1; i++) if (C[i].Level == C[i + 1].Level) {
        z = i + 2;
        Res.R[1] = C[i].Level;
        break;
    }
    for (i = z; i < N - 1; i++) if (C[i].Level == C[i + 1].Level) {
        Res.R[2] = C[i].Level;
        break;
    }
    if (Res.R[1] != 0 && Res.R[2] != 0) {
        Res.R[0] = 2;
        for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level || Res.R[2] == P.Cards[j].Level) Res.R[3] = 1;
    }

    return Res;
}

CheckRes ThreeCheck(Player P, Card D[5], int m) {
    int i, j, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
            tmp = C[j];
            C[j] = C[i];
            C[i] = tmp;
        }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < N - 2; i++) if (C[i].Level == C[i + 1].Level && C[i].Level == C[i +2].Level) {
        Res.R[0] = 3;
        Res.R[1] = C[i].Level;
        for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level) Res.R[3] = 1;
        break;
    }

    return Res;
}

CheckRes StraightCheck(Player P, Card D[5], int m) {
    int i, j, x, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
        tmp = C[j];
        C[j] = C[i];
        C[i] = tmp;
    }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < N - 4; i++) {
        x = 0;
        for (j = i; j < N - 1; j++) {
            if (C[j].Level == C[j + 1].Level + 1) ++x;
            if (C[j].Level > C[j + 1].Level + 1) break;
            if (x == 4) {
                Res.R[0] = 4;
                Res.R[1] = C[j + 1].Level;
                for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level || Res.R[1] == P.Cards[j].Level - 1 || Res.R[1] == P.Cards[j].Level - 2 || Res.R[1] == P.Cards[j].Level - 3 || Res.R[1] == P.Cards[j].Level - 4) Res.R[3] = 1;
                break;
            }
        }
        if (Res.R[0] == 4) break;
    }

    return Res;
}

CheckRes FlushCheck(Player P, Card D[5], int m) {
    int i, j, z, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
        tmp = C[j];
        C[j] = C[i];
        C[i] = tmp;
    }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < NSuits; i++) {
        Res.R[2] = 0;
        z = 0;
        for (j = 0; j < N; j++) if (C[j].Suit == i) {
            if (C[j].Level > Res.R[2]) Res.R[2] = C[j].Level;
            ++z;
        }
        if (z >= 5) {
            Res.R[0] = 5;
            Res.R[1] = i;
            for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Suit) Res.R[3] = 1;
            break;
        }
    }

    return Res;
}

CheckRes FullCheck(Player P, Card D[5], int m) {
    int i, j, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
        tmp = C[j];
        C[j] = C[i];
        C[i] = tmp;
    }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < N - 2; i++) if (C[i].Level == C[i + 1].Level && C[i].Level == C[i + 2].Level) {
        Res.R[1] = C[i].Level;
        break;
    }
    for (i = 0; i < N - 1; i++) if (C[i].Level == C[i + 1].Level && C[i].Level != Res.R[1]) {
        Res.R[2] = C[i].Level;
        break;
    }
    if (Res.R[1] != 0 && Res.R[2] != 0) {
        Res.R[0] = 6;
        for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level || Res.R[2] == P.Cards[j].Level) Res.R[3] = 1;
    }

    return Res;
}

CheckRes FourCheck(Player P, Card D[5], int m) {
    int i, j, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
        for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
            tmp = C[j];
            C[j] = C[i];
            C[i] = tmp;
        }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < N - 2; i++) if (C[i].Level == C[i + 1].Level && C[i].Level == C[i + 2].Level && C[i].Level == C[i + 3].Level) {
        Res.R[0] = 7;
        Res.R[1] = C[i].Level;
        for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level) Res.R[3] = 1;
        break;
    }

    return Res;
}

CheckRes SFlushCheck(Player P, Card D[5], int m) {
    int i, j, x, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
        tmp = C[j];
        C[j] = C[i];
        C[i] = tmp;
    }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    for (i = 0; i < N - 4; i++) {
        x = 0;
        for (j = i; j < N - 1; j++) {
            if (C[j].Level == C[j + 1].Level + 1 && C[j + 1].Suit == C[i].Suit) ++x;
            if (C[j].Level > C[j + 1].Level + 1) break;
            if (x == 4) {
                Res.R[0] = 8;
                Res.R[1] = C[j + 1].Level;
                Res.R[2] = C[j + 1].Suit;
                for (j = 0; j < 2; j++) if (Res.R[1] == P.Cards[j].Level || Res.R[1] == P.Cards[j].Level - 1 || Res.R[1] == P.Cards[j].Level - 2 || Res.R[1] == P.Cards[j].Level - 3 || Res.R[1] == P.Cards[j].Level - 4) Res.R[3] = 1;
                break;
            }
        }
        if (Res.R[0] == 8) break;
    }

    return Res;
}

CheckRes RFlushCheck(Player P, Card D[5], int m) {
    int i, j, x, N = m + 2;
    Card C[7];
    Card tmp;
    CheckRes Res;

    for (i = 0; i < 2; i++) C[i] = P.Cards[i];
    for (i = 2; i < N; i++) C[i] = D[i - 2];
    for (i = 0; i < N; i++)
    for (j = i + 1; j < N; j++) if (C[j].Level > C[i].Level) {
        tmp = C[j];
        C[j] = C[i];
        C[i] = tmp;
    }

    for (i = 0; i < 4; i++) Res.R[i] = 0;
    i = 0;
    while (C[i].Level == 14) {
        x = 0;
        for (j = 0; j < N - 1; j++) {
            if (C[j].Level == C[j + 1].Level + 1 && C[j + 1].Suit == C[0].Suit) ++x;
            if (C[j].Level > C[j + 1].Level + 1) break;
            if (x == 4) {
                Res.R[0] = 9;
                Res.R[1] = C[j + 1].Suit;
                for (j = 0; j < 2; j++) if (P.Cards[j].Level == 14 || P.Cards[j].Level == 13 || P.Cards[j].Level == 12 || P.Cards[j].Level == 11 || P.Cards[j].Level == 10) Res.R[3] = 1;
                break;
            }
        }
        ++i;
    }

    return Res;
}

CheckRes CombCheck(Player P, Card D[5], int m) {
    CheckRes Res, tmp;

    Res.R[0] = 0;
    Res.R[1] = 0;
    Res.R[2] = 0;
    Res.R[3] = 0;
    tmp = PairCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = DPairCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = ThreeCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = StraightCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = FlushCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = FullCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = FourCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = SFlushCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;
    tmp = RFlushCheck(P, D, m); if (tmp.R[0] > Res.R[0]) Res = tmp;

    return Res;
}

CheckRes WinnerCheck(Player P[MaxPlayers], int N, Card D[5], int m) {
    int tmp = 0, i, j, k, l, g1, g2, x = m + 2, pos = 0;
    Card z;
    Card C1[7];
    Card C2[7];
    CheckRes Res;

    for (i = 0; i < 4; i++) Res.R[i] = -1;
    while (true) {
        if (P[tmp].Fold == 0 && P[tmp].Out == 0) break;
        else ++tmp;
    }
    for (i = tmp + 1; i < N; i++) if (P[i].Fold == 0 && P[i].Out == 0) if (CombCheck(P[i], D, m).R[0] > CombCheck(P[tmp], D, m).R[0]) tmp = i;
    Res.R[pos] = tmp;
    for (i = tmp + 1; i < N; i++) if (P[i].Fold == 0 && P[i].Out == 0 && CombCheck(P[i], D, m).R[0] == CombCheck(P[tmp], D, m).R[0]) {
        switch (CombCheck(P[i], D, m).R[0]) {
        case 0:
            for (j = 0; j < 2; j++) C1[j] = P[i].Cards[j];
            for (j = 2; j < x; j++) C1[j] = D[j - 2];
            for (j = 0; j < x; j++)
            for (k = j + 1; k < x; k++) if (C1[k].Level > C1[j].Level) {
                z = C1[k];
                C1[k] = C1[j];
                C1[j] = z;
            }
            for (j = 0; j < 2; j++) C2[j] = P[tmp].Cards[j];
            for (j = 2; j < x; j++) C2[j] = D[j - 2];
            for (j = 0; j < x; j++)
            for (k = j + 1; k < x; k++) if (C2[k].Level > C2[j].Level) {
                z = C2[k];
                C2[k] = C2[j];
                C2[j] = z;
            }
            j = 0;
            k = 0;
            while (j < 5) {
                if (C1[k].Level < C2[k].Level) break;
                if (C1[k].Level > C2[k].Level) {
                    for (l = 0; l < 4; l++) Res.R[l] = -1;
                    tmp = i;
                    pos = 0;
                    Res.R[pos] = tmp;
                    break;
                }
                if (C1[k].Level == C2[k].Level) ++j;
                ++k;
            }
            if (j == 5) {
                ++pos;
                Res.R[pos] = i;
            }
            break;
        case 1:
            if (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 2; j++) C1[j] = P[i].Cards[j];
                for (j = 2; j < x; j++) C1[j] = D[j - 2];
                for (j = 0; j < x; j++)
                for (k = j + 1; k < x; k++) if (C1[k].Level > C1[j].Level) {
                    z = C1[k];
                    C1[k] = C1[j];
                    C1[j] = z;
                }
                for (j = 0; j < 2; j++) C2[j] = P[tmp].Cards[j];
                for (j = 2; j < x; j++) C2[j] = D[j - 2];
                for (j = 0; j < x; j++)
                for (k = j + 1; k < x; k++) if (C2[k].Level > C2[j].Level) {
                    z = C2[k];
                    C2[k] = C2[j];
                    C2[j] = z;
                }
                j = 0;
                g1 = 0;
                g2 = 0;
                while (j < 3) {
                    while (C1[g1].Level == CombCheck(P[tmp], D, m).R[1]) ++g1;
                    while (C2[g2].Level == CombCheck(P[tmp], D, m).R[1]) ++g2;
                    if (C1[g1].Level < C2[g2].Level) break;
                    if (C1[g1].Level > C2[g2].Level) {
                        for (l = 0; l < 4; l++) Res.R[l] = -1;
                        tmp = i;
                        pos = 0;
                        Res.R[pos] = tmp;
                        break;
                    }
                    if (C1[g1].Level == C2[g2].Level) ++j;
                    ++g1;
                    ++g2;
                }
                if (j == 3) {
                    ++pos;
                    Res.R[pos] = i;
                }
            }
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 2:
            if (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1] && CombCheck(P[i], D, m).R[2] == CombCheck(P[tmp], D, m).R[2]) {
                for (j = 0; j < 2; j++) C1[j] = P[i].Cards[j];
                for (j = 2; j < x; j++) C1[j] = D[j - 2];
                for (j = 0; j < x; j++)
                for (k = j + 1; k < x; k++) if (C1[k].Level > C1[j].Level) {
                    z = C1[k];
                    C1[k] = C1[j];
                    C1[j] = z;
                }
                for (j = 0; j < 2; j++) C2[j] = P[tmp].Cards[j];
                for (j = 2; j < x; j++) C2[j] = D[j - 2];
                for (j = 0; j < x; j++)
                for (k = j + 1; k < x; k++) if (C2[k].Level > C2[j].Level) {
                    z = C2[k];
                    C2[k] = C2[j];
                    C2[j] = z;
                }
                j = 0;
                g1 = 0;
                g2 = 0;
                while (j < 1) {
                    while (C1[g1].Level == CombCheck(P[tmp], D, m).R[1] || C1[g1].Level == CombCheck(P[tmp], D, m).R[2]) ++g1;
                    while (C2[g2].Level == CombCheck(P[tmp], D, m).R[1] || C2[g2].Level == CombCheck(P[tmp], D, m).R[2]) ++g2;
                    if (C1[g1].Level < C2[g2].Level) break;
                    if (C1[g1].Level > C2[g2].Level) {
                        for (l = 0; l < 4; l++) Res.R[l] = -1;
                        tmp = i;
                        pos = 0;
                        Res.R[pos] = tmp;
                        break;
                    }
                    if (C1[g1].Level = C2[g2].Level) ++j;
                    ++g1;
                    ++g2;
                }
                if (j == 1) {
                    ++pos;
                    Res.R[pos] = i;
                }
            }
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1] || (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1] && CombCheck(P[i], D, m).R[2] > CombCheck(P[tmp], D, m).R[2])) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 3:
            if (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 2; j++) C1[j] = P[i].Cards[j];
                for (j = 2; j < x; j++) C1[j] = D[j - 2];
                for (j = 0; j < x; j++)
                for (k = j + 1; k < x; k++) if (C1[k].Level > C1[j].Level) {
                    z = C1[k];
                    C1[k] = C1[j];
                    C1[j] = z;
                }
                for (j = 0; j < 2; j++) C2[j] = P[tmp].Cards[j];
                for (j = 2; j < x; j++) C2[j] = D[j - 2];
                for (j = 0; j < x; j++)
                for (k = j + 1; k < x; k++) if (C2[k].Level > C2[j].Level) {
                    z = C2[k];
                    C2[k] = C2[j];
                    C2[j] = z;
                }
                j = 0;
                g1 = 0;
                g2 = 0;
                while (j < 2) {
                    while (C1[g1].Level == CombCheck(P[tmp], D, m).R[1]) ++g1;
                    while (C2[g2].Level == CombCheck(P[tmp], D, m).R[1]) ++g2;
                    if (C1[g1].Level < C2[g2].Level) break;
                    if (C1[g1].Level > C2[g2].Level) {
                        for (l = 0; l < 4; l++) Res.R[l] = -1;
                        tmp = i;
                        pos = 0;
                        Res.R[pos] = tmp;
                        break;
                    }
                    if (C1[g1].Level == C2[g2].Level) ++j;
                    ++g1;
                    ++g2;
                }
                if (j == 2) {
                    ++pos;
                    Res.R[pos] = i;
                }
            }
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 4:
            if (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1]) {
                ++pos;
                Res.R[pos] = i;
            }
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 5:
            if (CombCheck(P[i], D, m).R[2] > CombCheck(P[tmp], D, m).R[2]) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 6:
            if (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1] && CombCheck(P[i], D, m).R[2] == CombCheck(P[tmp], D, m).R[2]) {
                ++pos;
                Res.R[pos] = i;
            }
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1] || (CombCheck(P[i], D, m).R[1] == CombCheck(P[tmp], D, m).R[1] && CombCheck(P[i], D, m).R[2] > CombCheck(P[tmp], D, m).R[2])) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 7:
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        case 8:
            if (CombCheck(P[i], D, m).R[1] > CombCheck(P[tmp], D, m).R[1]) {
                for (j = 0; j < 4; j++) Res.R[j] = -1;
                tmp = i;
                pos = 0;
                Res.R[pos] = tmp;
            }
            break;
        }
    }

    return Res;
}

#endif
