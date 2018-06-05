#ifndef STRUCT_H
#define STRUCT_H

#include <QString>
#include <QTime>
#include <conio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

using namespace std;

#define MaxPlayers 9
#define NNames 15
#define NDesk 5
#define NCards 52
#define NSuits 4
#define CMaxLvel 14

//typedef char TName[20];

struct Card {
    int Suit, Level;
};
struct Player {
    QString Name;
    int Money, Bet, Check, Fold, Out;
    int UnableRaise, UnableCall, UnableCheck, ShowCards;
    Card Cards[2];
};
struct CheckRes {
    int R[4];
};

#endif // STRUCT_H
