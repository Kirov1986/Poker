#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Struct.h"
#include "Check.h"
#include "AI.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void StartPoker();
    void PokerExit();
    void RoundStart();
    void Round();
    void RoundF();
    void RoundE();
    void RoundEnd();
    void UpdateInfo();
    void Raise();
    void Call();
    void Check();
    void Fold();

signals:
    void Signal1();
    void Signal2();
    void Signal3();
    void Signal4();
    void Signal5();
    void Signal6();

private:
    Ui::MainWindow *ui;

    int NPlayers, NCard, NPlayer, SBlind, BBlind, Stage, Dealer, Winner, Bank, Blind, Bet, BetEnd, PlayerBetEnd, Menu, Exit1, Exit2, Exit3;
    int i, j, k;
    Player Players[MaxPlayers];
    Card Deck[NCards];
    Card Desk[NDesk];
    QString Names[NNames];
    CheckRes BankWinner;
};

#endif // MAINWINDOW_H
