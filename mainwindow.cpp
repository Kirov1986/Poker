#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Game->hide();
    connect(ui->StartGame, SIGNAL(clicked()), this, SLOT(StartPoker()));
    connect(ui->GExit, SIGNAL(clicked()), this, SLOT(PokerExit()));
    connect(ui->Exit, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->Raise, SIGNAL(clicked()), this, SLOT(Raise()));
    connect(ui->Call, SIGNAL(clicked()), this, SLOT(Call()));
    connect(ui->Check, SIGNAL(clicked()), this, SLOT(Check()));
    connect(ui->Fold, SIGNAL(clicked()), this, SLOT(Fold()));
    connect(this, SIGNAL(Signal1()), this, SLOT(RoundStart()));
    connect(this, SIGNAL(Signal2()), this, SLOT(UpdateInfo()));
    connect(this, SIGNAL(Signal3()), this, SLOT(Round()));
    connect(this, SIGNAL(Signal4()), this, SLOT(RoundEnd()));
    connect(this, SIGNAL(Signal5()), this, SLOT(RoundF()));
    connect(this, SIGNAL(Signal6()), this, SLOT(RoundE()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UpdateInfo() {
    ui->textBrowser->setText("");
    for (i = 1; i < NPlayers; i++) {
        ui->textBrowser->append(Players[i].Name);
        ui->textBrowser->insertPlainText(" ");
        ui->textBrowser->insertPlainText(QString::number(Players[i].Money));
        if (Players[i].Bet != 0) {
            ui->textBrowser->insertPlainText("     Bet: ");
            ui->textBrowser->insertPlainText(QString::number(Players[i].Bet));
        }
        if (Players[i].Check == 1) ui->textBrowser->insertPlainText("  CHECK  ");
        if (Players[i].Fold == 1) ui->textBrowser->insertPlainText("  FOLD  ");
        if (Players[i].Out == 1) ui->textBrowser->insertPlainText("  OUT  ");
        ui->textBrowser->append("\n");
    }
    ui->PlayerInfo->setText("");
    ui->PlayerInfo->append(Players[0].Name);
    ui->PlayerInfo->append("Money: "); ui->PlayerInfo->insertPlainText(QString::number(Players[0].Money));
    ui->PlayerInfo->append(QString::number(Players[0].Bet)); ui->PlayerInfo->insertPlainText("/"); ui->PlayerInfo->insertPlainText(QString::number(Bet));
    if (Players[0].Check == 1) ui->PlayerInfo->append("CHECK");
    if (Players[0].Fold == 1) ui->PlayerInfo->append("FOLD");
    ui->PlayerInfo->append("\n\n");
    ui->PlayerInfo->append("Bank: "); ui->PlayerInfo->insertPlainText(QString::number(Bank));
    ui->PlayerInfo->append("Small Blind: "); ui->PlayerInfo->insertPlainText(QString::number(Blind));
    ui->PlayerInfo->append("Dealer: "); ui->PlayerInfo->insertPlainText(Players[Dealer].Name);
    QPixmap Jacket("H:/Prog-QT/Kurs/Jacket.jpg");
    QPixmap H2("H:/Prog-QT/Kurs/2H.jpg");
    QPixmap H3("H:/Prog-QT/Kurs/3H.jpg");
    QPixmap H4("H:/Prog-QT/Kurs/4H.jpg");
    QPixmap H5("H:/Prog-QT/Kurs/5H.jpg");
    QPixmap H6("H:/Prog-QT/Kurs/6H.jpg");
    QPixmap H7("H:/Prog-QT/Kurs/7H.jpg");
    QPixmap H8("H:/Prog-QT/Kurs/8H.jpg");
    QPixmap H9("H:/Prog-QT/Kurs/9H.jpg");
    QPixmap H10("H:/Prog-QT/Kurs/10H.jpg");
    QPixmap HJ("H:/Prog-QT/Kurs/JH.jpg");
    QPixmap HQ("H:/Prog-QT/Kurs/QH.jpg");
    QPixmap HK("H:/Prog-QT/Kurs/KH.jpg");
    QPixmap HA("H:/Prog-QT/Kurs/AH.jpg");
    QPixmap B2("H:/Prog-QT/Kurs/2B.jpg");
    QPixmap B3("H:/Prog-QT/Kurs/3B.jpg");
    QPixmap B4("H:/Prog-QT/Kurs/4B.jpg");
    QPixmap B5("H:/Prog-QT/Kurs/5B.jpg");
    QPixmap B6("H:/Prog-QT/Kurs/6B.jpg");
    QPixmap B7("H:/Prog-QT/Kurs/7B.jpg");
    QPixmap B8("H:/Prog-QT/Kurs/8B.jpg");
    QPixmap B9("H:/Prog-QT/Kurs/9B.jpg");
    QPixmap B10("H:/Prog-QT/Kurs/10B.jpg");
    QPixmap BJ("H:/Prog-QT/Kurs/JB.jpg");
    QPixmap BQ("H:/Prog-QT/Kurs/QB.jpg");
    QPixmap BK("H:/Prog-QT/Kurs/KB.jpg");
    QPixmap BA("H:/Prog-QT/Kurs/AB.jpg");
    QPixmap P2("H:/Prog-QT/Kurs/2P.jpg");
    QPixmap P3("H:/Prog-QT/Kurs/3P.jpg");
    QPixmap P4("H:/Prog-QT/Kurs/4P.jpg");
    QPixmap P5("H:/Prog-QT/Kurs/5P.jpg");
    QPixmap P6("H:/Prog-QT/Kurs/6P.jpg");
    QPixmap P7("H:/Prog-QT/Kurs/7P.jpg");
    QPixmap P8("H:/Prog-QT/Kurs/8P.jpg");
    QPixmap P9("H:/Prog-QT/Kurs/9P.jpg");
    QPixmap P10("H:/Prog-QT/Kurs/10P.jpg");
    QPixmap PJ("H:/Prog-QT/Kurs/JP.jpg");
    QPixmap PQ("H:/Prog-QT/Kurs/QP.jpg");
    QPixmap PK("H:/Prog-QT/Kurs/KP.jpg");
    QPixmap PA("H:/Prog-QT/Kurs/AP.jpg");
    QPixmap T2("H:/Prog-QT/Kurs/2T.jpg");
    QPixmap T3("H:/Prog-QT/Kurs/3T.jpg");
    QPixmap T4("H:/Prog-QT/Kurs/4T.jpg");
    QPixmap T5("H:/Prog-QT/Kurs/5T.jpg");
    QPixmap T6("H:/Prog-QT/Kurs/6T.jpg");
    QPixmap T7("H:/Prog-QT/Kurs/7T.jpg");
    QPixmap T8("H:/Prog-QT/Kurs/8T.jpg");
    QPixmap T9("H:/Prog-QT/Kurs/9T.jpg");
    QPixmap T10("H:/Prog-QT/Kurs/10T.jpg");
    QPixmap TJ("H:/Prog-QT/Kurs/JT.jpg");
    QPixmap TQ("H:/Prog-QT/Kurs/QT.jpg");
    QPixmap TK("H:/Prog-QT/Kurs/KT.jpg");
    QPixmap TA("H:/Prog-QT/Kurs/AT.jpg");
    ui->Card1->setPixmap(Jacket);
    ui->Card2->setPixmap(Jacket);
    ui->Card3->setPixmap(Jacket);
    ui->Card4->setPixmap(Jacket);
    ui->Card5->setPixmap(Jacket);
    switch(Stage) {
    case 5:
        //ui->Stage->setText("Pre-Flop");
        switch(Desk[4].Suit) {
        case 0: switch(Desk[4].Level) {
            case 2: ui->Card5->setPixmap(H2); break;
                case 3: ui->Card5->setPixmap(H3); break;
                case 4: ui->Card5->setPixmap(H4); break;
                case 5: ui->Card5->setPixmap(H5); break;
                case 6: ui->Card5->setPixmap(H6); break;
                case 7: ui->Card5->setPixmap(H7); break;
                case 8: ui->Card5->setPixmap(H8); break;
                case 9: ui->Card5->setPixmap(H9); break;
                case 10: ui->Card5->setPixmap(H10); break;
                case 11: ui->Card5->setPixmap(HJ); break;
                case 12: ui->Card5->setPixmap(HQ); break;
                case 13: ui->Card5->setPixmap(HK); break;
                case 14: ui->Card5->setPixmap(HA); break;
            }
            break;
        case 1: switch(Desk[4].Level) {
            case 2: ui->Card5->setPixmap(B2); break;
                case 3: ui->Card5->setPixmap(B3); break;
                case 4: ui->Card5->setPixmap(B4); break;
                case 5: ui->Card5->setPixmap(B5); break;
                case 6: ui->Card5->setPixmap(B6); break;
                case 7: ui->Card5->setPixmap(B7); break;
                case 8: ui->Card5->setPixmap(B8); break;
                case 9: ui->Card5->setPixmap(B9); break;
                case 10: ui->Card5->setPixmap(B10); break;
                case 11: ui->Card5->setPixmap(BJ); break;
                case 12: ui->Card5->setPixmap(BQ); break;
                case 13: ui->Card5->setPixmap(BK); break;
                case 14: ui->Card5->setPixmap(BA); break;
            }
            break;
        case 2: switch(Desk[4].Level) {
            case 2: ui->Card5->setPixmap(P2); break;
                case 3: ui->Card5->setPixmap(P3); break;
                case 4: ui->Card5->setPixmap(P4); break;
                case 5: ui->Card5->setPixmap(P5); break;
                case 6: ui->Card5->setPixmap(P6); break;
                case 7: ui->Card5->setPixmap(P7); break;
                case 8: ui->Card5->setPixmap(P8); break;
                case 9: ui->Card5->setPixmap(P9); break;
                case 10: ui->Card5->setPixmap(P10); break;
                case 11: ui->Card5->setPixmap(PJ); break;
                case 12: ui->Card5->setPixmap(PQ); break;
                case 13: ui->Card5->setPixmap(PK); break;
                case 14: ui->Card5->setPixmap(PA); break;
            }
            break;
        case 3: switch(Desk[4].Level) {
            case 2: ui->Card5->setPixmap(T2); break;
                case 3: ui->Card5->setPixmap(T3); break;
                case 4: ui->Card5->setPixmap(T4); break;
                case 5: ui->Card5->setPixmap(T5); break;
                case 6: ui->Card5->setPixmap(T6); break;
                case 7: ui->Card5->setPixmap(T7); break;
                case 8: ui->Card5->setPixmap(T8); break;
                case 9: ui->Card5->setPixmap(T9); break;
                case 10: ui->Card5->setPixmap(T10); break;
                case 11: ui->Card5->setPixmap(TJ); break;
                case 12: ui->Card5->setPixmap(TQ); break;
                case 13: ui->Card5->setPixmap(TK); break;
                case 14: ui->Card5->setPixmap(TA); break;
            }
            break;
        }
    case 4:
        switch(Desk[3].Suit) {
        case 0: switch(Desk[3].Level) {
            case 2: ui->Card4->setPixmap(H2); break;
                case 3: ui->Card4->setPixmap(H3); break;
                case 4: ui->Card4->setPixmap(H4); break;
                case 5: ui->Card4->setPixmap(H5); break;
                case 6: ui->Card4->setPixmap(H6); break;
                case 7: ui->Card4->setPixmap(H7); break;
                case 8: ui->Card4->setPixmap(H8); break;
                case 9: ui->Card4->setPixmap(H9); break;
                case 10: ui->Card4->setPixmap(H10); break;
                case 11: ui->Card4->setPixmap(HJ); break;
                case 12: ui->Card4->setPixmap(HQ); break;
                case 13: ui->Card4->setPixmap(HK); break;
                case 14: ui->Card4->setPixmap(HA); break;
            }
            break;
        case 1: switch(Desk[3].Level) {
            case 2: ui->Card4->setPixmap(B2); break;
                case 3: ui->Card4->setPixmap(B3); break;
                case 4: ui->Card4->setPixmap(B4); break;
                case 5: ui->Card4->setPixmap(B5); break;
                case 6: ui->Card4->setPixmap(B6); break;
                case 7: ui->Card4->setPixmap(B7); break;
                case 8: ui->Card4->setPixmap(B8); break;
                case 9: ui->Card4->setPixmap(B9); break;
                case 10: ui->Card4->setPixmap(B10); break;
                case 11: ui->Card4->setPixmap(BJ); break;
                case 12: ui->Card4->setPixmap(BQ); break;
                case 13: ui->Card4->setPixmap(BK); break;
                case 14: ui->Card4->setPixmap(BA); break;
            }
            break;
        case 2: switch(Desk[3].Level) {
            case 2: ui->Card4->setPixmap(P2); break;
                case 3: ui->Card4->setPixmap(P3); break;
                case 4: ui->Card4->setPixmap(P4); break;
                case 5: ui->Card4->setPixmap(P5); break;
                case 6: ui->Card4->setPixmap(P6); break;
                case 7: ui->Card4->setPixmap(P7); break;
                case 8: ui->Card4->setPixmap(P8); break;
                case 9: ui->Card4->setPixmap(P9); break;
                case 10: ui->Card4->setPixmap(P10); break;
                case 11: ui->Card4->setPixmap(PJ); break;
                case 12: ui->Card4->setPixmap(PQ); break;
                case 13: ui->Card4->setPixmap(PK); break;
                case 14: ui->Card4->setPixmap(PA); break;
            }
            break;
        case 3: switch(Desk[3].Level) {
            case 2: ui->Card4->setPixmap(T2); break;
                case 3: ui->Card4->setPixmap(T3); break;
                case 4: ui->Card4->setPixmap(T4); break;
                case 5: ui->Card4->setPixmap(T5); break;
                case 6: ui->Card4->setPixmap(T6); break;
                case 7: ui->Card4->setPixmap(T7); break;
                case 8: ui->Card4->setPixmap(T8); break;
                case 9: ui->Card4->setPixmap(T9); break;
                case 10: ui->Card4->setPixmap(T10); break;
                case 11: ui->Card4->setPixmap(TJ); break;
                case 12: ui->Card4->setPixmap(TQ); break;
                case 13: ui->Card4->setPixmap(TK); break;
                case 14: ui->Card4->setPixmap(TA); break;
            }
            break;
        }
    case 3:
        switch(Desk[2].Suit) {
        case 0: switch(Desk[2].Level) {
            case 2: ui->Card3->setPixmap(H2); break;
                case 3: ui->Card3->setPixmap(H3); break;
                case 4: ui->Card3->setPixmap(H4); break;
                case 5: ui->Card3->setPixmap(H5); break;
                case 6: ui->Card3->setPixmap(H6); break;
                case 7: ui->Card3->setPixmap(H7); break;
                case 8: ui->Card3->setPixmap(H8); break;
                case 9: ui->Card3->setPixmap(H9); break;
                case 10: ui->Card3->setPixmap(H10); break;
                case 11: ui->Card3->setPixmap(HJ); break;
                case 12: ui->Card3->setPixmap(HQ); break;
                case 13: ui->Card3->setPixmap(HK); break;
                case 14: ui->Card3->setPixmap(HA); break;
            }
            break;
        case 1: switch(Desk[2].Level) {
            case 2: ui->Card3->setPixmap(B2); break;
                case 3: ui->Card3->setPixmap(B3); break;
                case 4: ui->Card3->setPixmap(B4); break;
                case 5: ui->Card3->setPixmap(B5); break;
                case 6: ui->Card3->setPixmap(B6); break;
                case 7: ui->Card3->setPixmap(B7); break;
                case 8: ui->Card3->setPixmap(B8); break;
                case 9: ui->Card3->setPixmap(B9); break;
                case 10: ui->Card3->setPixmap(B10); break;
                case 11: ui->Card3->setPixmap(BJ); break;
                case 12: ui->Card3->setPixmap(BQ); break;
                case 13: ui->Card3->setPixmap(BK); break;
                case 14: ui->Card3->setPixmap(BA); break;
            }
            break;
        case 2: switch(Desk[2].Level) {
            case 2: ui->Card3->setPixmap(P2); break;
                case 3: ui->Card3->setPixmap(P3); break;
                case 4: ui->Card3->setPixmap(P4); break;
                case 5: ui->Card3->setPixmap(P5); break;
                case 6: ui->Card3->setPixmap(P6); break;
                case 7: ui->Card3->setPixmap(P7); break;
                case 8: ui->Card3->setPixmap(P8); break;
                case 9: ui->Card3->setPixmap(P9); break;
                case 10: ui->Card3->setPixmap(P10); break;
                case 11: ui->Card3->setPixmap(PJ); break;
                case 12: ui->Card3->setPixmap(PQ); break;
                case 13: ui->Card3->setPixmap(PK); break;
                case 14: ui->Card3->setPixmap(PA); break;
            }
            break;
        case 3: switch(Desk[2].Level) {
            case 2: ui->Card3->setPixmap(T2); break;
                case 3: ui->Card3->setPixmap(T3); break;
                case 4: ui->Card3->setPixmap(T4); break;
                case 5: ui->Card3->setPixmap(T5); break;
                case 6: ui->Card3->setPixmap(T6); break;
                case 7: ui->Card3->setPixmap(T7); break;
                case 8: ui->Card3->setPixmap(T8); break;
                case 9: ui->Card3->setPixmap(T9); break;
                case 10: ui->Card3->setPixmap(T10); break;
                case 11: ui->Card3->setPixmap(TJ); break;
                case 12: ui->Card3->setPixmap(TQ); break;
                case 13: ui->Card3->setPixmap(TK); break;
                case 14: ui->Card3->setPixmap(TA); break;
            }
            break;
        }
        switch(Desk[1].Suit) {
        case 0: switch(Desk[1].Level) {
            case 2: ui->Card2->setPixmap(H2); break;
                case 3: ui->Card2->setPixmap(H3); break;
                case 4: ui->Card2->setPixmap(H4); break;
                case 5: ui->Card2->setPixmap(H5); break;
                case 6: ui->Card2->setPixmap(H6); break;
                case 7: ui->Card2->setPixmap(H7); break;
                case 8: ui->Card2->setPixmap(H8); break;
                case 9: ui->Card2->setPixmap(H9); break;
                case 10: ui->Card2->setPixmap(H10); break;
                case 11: ui->Card2->setPixmap(HJ); break;
                case 12: ui->Card2->setPixmap(HQ); break;
                case 13: ui->Card2->setPixmap(HK); break;
                case 14: ui->Card2->setPixmap(HA); break;
            }
            break;
        case 1: switch(Desk[1].Level) {
            case 2: ui->Card2->setPixmap(B2); break;
                case 3: ui->Card2->setPixmap(B3); break;
                case 4: ui->Card2->setPixmap(B4); break;
                case 5: ui->Card2->setPixmap(B5); break;
                case 6: ui->Card2->setPixmap(B6); break;
                case 7: ui->Card2->setPixmap(B7); break;
                case 8: ui->Card2->setPixmap(B8); break;
                case 9: ui->Card2->setPixmap(B9); break;
                case 10: ui->Card2->setPixmap(B10); break;
                case 11: ui->Card2->setPixmap(BJ); break;
                case 12: ui->Card2->setPixmap(BQ); break;
                case 13: ui->Card2->setPixmap(BK); break;
                case 14: ui->Card2->setPixmap(BA); break;
            }
            break;
        case 2: switch(Desk[1].Level) {
            case 2: ui->Card2->setPixmap(P2); break;
                case 3: ui->Card2->setPixmap(P3); break;
                case 4: ui->Card2->setPixmap(P4); break;
                case 5: ui->Card2->setPixmap(P5); break;
                case 6: ui->Card2->setPixmap(P6); break;
                case 7: ui->Card2->setPixmap(P7); break;
                case 8: ui->Card2->setPixmap(P8); break;
                case 9: ui->Card2->setPixmap(P9); break;
                case 10: ui->Card2->setPixmap(P10); break;
                case 11: ui->Card2->setPixmap(PJ); break;
                case 12: ui->Card2->setPixmap(PQ); break;
                case 13: ui->Card2->setPixmap(PK); break;
                case 14: ui->Card2->setPixmap(PA); break;
            }
            break;
        case 3: switch(Desk[1].Level) {
            case 2: ui->Card2->setPixmap(T2); break;
                case 3: ui->Card2->setPixmap(T3); break;
                case 4: ui->Card2->setPixmap(T4); break;
                case 5: ui->Card2->setPixmap(T5); break;
                case 6: ui->Card2->setPixmap(T6); break;
                case 7: ui->Card2->setPixmap(T7); break;
                case 8: ui->Card2->setPixmap(T8); break;
                case 9: ui->Card2->setPixmap(T9); break;
                case 10: ui->Card2->setPixmap(T10); break;
                case 11: ui->Card2->setPixmap(TJ); break;
                case 12: ui->Card2->setPixmap(TQ); break;
                case 13: ui->Card2->setPixmap(TK); break;
                case 14: ui->Card2->setPixmap(TA); break;
            }
            break;
        }
        switch(Desk[0].Suit) {
        case 0: switch(Desk[0].Level) {
            case 2: ui->Card1->setPixmap(H2); break;
                case 3: ui->Card1->setPixmap(H3); break;
                case 4: ui->Card1->setPixmap(H4); break;
                case 5: ui->Card1->setPixmap(H5); break;
                case 6: ui->Card1->setPixmap(H6); break;
                case 7: ui->Card1->setPixmap(H7); break;
                case 8: ui->Card1->setPixmap(H8); break;
                case 9: ui->Card1->setPixmap(H9); break;
                case 10: ui->Card1->setPixmap(H10); break;
                case 11: ui->Card1->setPixmap(HJ); break;
                case 12: ui->Card1->setPixmap(HQ); break;
                case 13: ui->Card1->setPixmap(HK); break;
                case 14: ui->Card1->setPixmap(HA); break;
            }
            break;
        case 1: switch(Desk[0].Level) {
            case 2: ui->Card1->setPixmap(B2); break;
                case 3: ui->Card1->setPixmap(B3); break;
                case 4: ui->Card1->setPixmap(B4); break;
                case 5: ui->Card1->setPixmap(B5); break;
                case 6: ui->Card1->setPixmap(B6); break;
                case 7: ui->Card1->setPixmap(B7); break;
                case 8: ui->Card1->setPixmap(B8); break;
                case 9: ui->Card1->setPixmap(B9); break;
                case 10: ui->Card1->setPixmap(B10); break;
                case 11: ui->Card1->setPixmap(BJ); break;
                case 12: ui->Card1->setPixmap(BQ); break;
                case 13: ui->Card1->setPixmap(BK); break;
                case 14: ui->Card1->setPixmap(BA); break;
            }
            break;
        case 2: switch(Desk[0].Level) {
            case 2: ui->Card1->setPixmap(P2); break;
                case 3: ui->Card1->setPixmap(P3); break;
                case 4: ui->Card1->setPixmap(P4); break;
                case 5: ui->Card1->setPixmap(P5); break;
                case 6: ui->Card1->setPixmap(P6); break;
                case 7: ui->Card1->setPixmap(P7); break;
                case 8: ui->Card1->setPixmap(P8); break;
                case 9: ui->Card1->setPixmap(P9); break;
                case 10: ui->Card1->setPixmap(P10); break;
                case 11: ui->Card1->setPixmap(PJ); break;
                case 12: ui->Card1->setPixmap(PQ); break;
                case 13: ui->Card1->setPixmap(PK); break;
                case 14: ui->Card1->setPixmap(PA); break;
            }
            break;
        case 3: switch(Desk[0].Level) {
            case 2: ui->Card1->setPixmap(T2); break;
                case 3: ui->Card1->setPixmap(T3); break;
                case 4: ui->Card1->setPixmap(T4); break;
                case 5: ui->Card1->setPixmap(T5); break;
                case 6: ui->Card1->setPixmap(T6); break;
                case 7: ui->Card1->setPixmap(T7); break;
                case 8: ui->Card1->setPixmap(T8); break;
                case 9: ui->Card1->setPixmap(T9); break;
                case 10: ui->Card1->setPixmap(T10); break;
                case 11: ui->Card1->setPixmap(TJ); break;
                case 12: ui->Card1->setPixmap(TQ); break;
                case 13: ui->Card1->setPixmap(TK); break;
                case 14: ui->Card5->setPixmap(TA); break;
            }
            break;
        }
    }
    switch(Players[0].Cards[0].Suit) {
    case 0: switch(Players[0].Cards[0].Level) {
        case 2: ui->PCard1->setPixmap(H2); break;
            case 3: ui->PCard1->setPixmap(H3); break;
            case 4: ui->PCard1->setPixmap(H4); break;
            case 5: ui->PCard1->setPixmap(H5); break;
            case 6: ui->PCard1->setPixmap(H6); break;
            case 7: ui->PCard1->setPixmap(H7); break;
            case 8: ui->PCard1->setPixmap(H8); break;
            case 9: ui->PCard1->setPixmap(H9); break;
            case 10: ui->PCard1->setPixmap(H10); break;
            case 11: ui->PCard1->setPixmap(HJ); break;
            case 12: ui->PCard1->setPixmap(HQ); break;
            case 13: ui->PCard1->setPixmap(HK); break;
            case 14: ui->PCard1->setPixmap(HA); break;
        }
        break;
    case 1: switch(Players[0].Cards[0].Level) {
        case 2: ui->PCard1->setPixmap(B2); break;
            case 3: ui->PCard1->setPixmap(B3); break;
            case 4: ui->PCard1->setPixmap(B4); break;
            case 5: ui->PCard1->setPixmap(B5); break;
            case 6: ui->PCard1->setPixmap(B6); break;
            case 7: ui->PCard1->setPixmap(B7); break;
            case 8: ui->PCard1->setPixmap(B8); break;
            case 9: ui->PCard1->setPixmap(B9); break;
            case 10: ui->PCard1->setPixmap(B10); break;
            case 11: ui->PCard1->setPixmap(BJ); break;
            case 12: ui->PCard1->setPixmap(BQ); break;
            case 13: ui->PCard1->setPixmap(BK); break;
            case 14: ui->PCard1->setPixmap(BA); break;
        }
        break;
    case 2: switch(Players[0].Cards[0].Level) {
        case 2: ui->PCard1->setPixmap(P2); break;
            case 3: ui->PCard1->setPixmap(P3); break;
            case 4: ui->PCard1->setPixmap(P4); break;
            case 5: ui->PCard1->setPixmap(P5); break;
            case 6: ui->PCard1->setPixmap(P6); break;
            case 7: ui->PCard1->setPixmap(P7); break;
            case 8: ui->PCard1->setPixmap(P8); break;
            case 9: ui->PCard1->setPixmap(P9); break;
            case 10: ui->PCard1->setPixmap(P10); break;
            case 11: ui->PCard1->setPixmap(PJ); break;
            case 12: ui->PCard1->setPixmap(PQ); break;
            case 13: ui->PCard1->setPixmap(PK); break;
            case 14: ui->PCard1->setPixmap(PA); break;
        }
        break;
    case 3: switch(Players[0].Cards[0].Level) {
        case 2: ui->PCard1->setPixmap(T2); break;
            case 3: ui->PCard1->setPixmap(T3); break;
            case 4: ui->PCard1->setPixmap(T4); break;
            case 5: ui->PCard1->setPixmap(T5); break;
            case 6: ui->PCard1->setPixmap(T6); break;
            case 7: ui->PCard1->setPixmap(T7); break;
            case 8: ui->PCard1->setPixmap(T8); break;
            case 9: ui->PCard1->setPixmap(T9); break;
            case 10: ui->PCard1->setPixmap(T10); break;
            case 11: ui->PCard1->setPixmap(TJ); break;
            case 12: ui->PCard1->setPixmap(TQ); break;
            case 13: ui->PCard1->setPixmap(TK); break;
            case 14: ui->PCard1->setPixmap(TA); break;
        }
        break;
    }
    switch(Players[0].Cards[1].Suit) {
    case 0: switch(Players[0].Cards[1].Level) {
        case 2: ui->PCard2->setPixmap(H2); break;
            case 3: ui->PCard2->setPixmap(H3); break;
            case 4: ui->PCard2->setPixmap(H4); break;
            case 5: ui->PCard2->setPixmap(H5); break;
            case 6: ui->PCard2->setPixmap(H6); break;
            case 7: ui->PCard2->setPixmap(H7); break;
            case 8: ui->PCard2->setPixmap(H8); break;
            case 9: ui->PCard2->setPixmap(H9); break;
            case 10: ui->PCard2->setPixmap(H10); break;
            case 11: ui->PCard2->setPixmap(HJ); break;
            case 12: ui->PCard2->setPixmap(HQ); break;
            case 13: ui->PCard2->setPixmap(HK); break;
            case 14: ui->PCard2->setPixmap(HA); break;
        }
        break;
    case 1: switch(Players[0].Cards[1].Level) {
        case 2: ui->PCard2->setPixmap(B2); break;
            case 3: ui->PCard2->setPixmap(B3); break;
            case 4: ui->PCard2->setPixmap(B4); break;
            case 5: ui->PCard2->setPixmap(B5); break;
            case 6: ui->PCard2->setPixmap(B6); break;
            case 7: ui->PCard2->setPixmap(B7); break;
            case 8: ui->PCard2->setPixmap(B8); break;
            case 9: ui->PCard2->setPixmap(B9); break;
            case 10: ui->PCard2->setPixmap(B10); break;
            case 11: ui->PCard2->setPixmap(BJ); break;
            case 12: ui->PCard2->setPixmap(BQ); break;
            case 13: ui->PCard2->setPixmap(BK); break;
            case 14: ui->PCard2->setPixmap(BA); break;
        }
        break;
    case 2: switch(Players[0].Cards[1].Level) {
        case 2: ui->PCard2->setPixmap(P2); break;
            case 3: ui->PCard2->setPixmap(P3); break;
            case 4: ui->PCard2->setPixmap(P4); break;
            case 5: ui->PCard2->setPixmap(P5); break;
            case 6: ui->PCard2->setPixmap(P6); break;
            case 7: ui->PCard2->setPixmap(P7); break;
            case 8: ui->PCard2->setPixmap(P8); break;
            case 9: ui->PCard2->setPixmap(P9); break;
            case 10: ui->PCard2->setPixmap(P10); break;
            case 11: ui->PCard2->setPixmap(PJ); break;
            case 12: ui->PCard2->setPixmap(PQ); break;
            case 13: ui->PCard2->setPixmap(PK); break;
            case 14: ui->PCard2->setPixmap(PA); break;
        }
        break;
    case 3: switch(Players[0].Cards[1].Level) {
        case 2: ui->PCard2->setPixmap(T2); break;
            case 3: ui->PCard2->setPixmap(T3); break;
            case 4: ui->PCard2->setPixmap(T4); break;
            case 5: ui->PCard2->setPixmap(T5); break;
            case 6: ui->PCard2->setPixmap(T6); break;
            case 7: ui->PCard2->setPixmap(T7); break;
            case 8: ui->PCard2->setPixmap(T8); break;
            case 9: ui->PCard2->setPixmap(T9); break;
            case 10: ui->PCard2->setPixmap(T10); break;
            case 11: ui->PCard2->setPixmap(TJ); break;
            case 12: ui->PCard2->setPixmap(TQ); break;
            case 13: ui->PCard2->setPixmap(TK); break;
            case 14: ui->PCard2->setPixmap(TA); break;
        }
        break;
    }
    switch(Stage) {
        case 0: ui->Stage->setText("Pre-Flop"); break;
        case 3: ui->Stage->setText("Flop"); break;
        case 4: ui->Stage->setText("Turn"); break;
        case 5: ui->Stage->setText("River"); break;
    }
    //emit Signal3();
}

void MainWindow::Raise() {
    if (Players[0].UnableRaise == 0) {
                                                    Players[0].Bet = ui->spinBox_2->value() * Blind;
                                                    Bet = Players[0].Bet;
                                                    Players[0].Check = 0;
                                                    Players[0].UnableCheck = 0;
                                                    PlayerBetEnd = 1;
                                                    if ((NPlayer + 1) == NPlayers) NPlayer = 0;
                                                    else ++NPlayer;
                                                    emit Signal3();
    }
}

void MainWindow::Call() {
    if (Bet > 0) {
                                            if (Players[0].UnableCall == 0) {
                                                Players[0].Bet = Bet;
                                                Players[0].Check = 0;
                                                PlayerBetEnd = 1;
                                                if ((NPlayer + 1) == NPlayers) NPlayer = 0;
                                                else ++NPlayer;
                                                emit Signal3();
                                            }
                                            else {
                                                Players[0].Bet = Players[0].Money;
                                                Players[0].Check = 0;
                                                Players[0].UnableCheck = 1;
                                                PlayerBetEnd = 1;
                                                if ((NPlayer + 1) == NPlayers) NPlayer = 0;
                                                else ++NPlayer;
                                                emit Signal3();
                                            }
                                        }
}

void MainWindow::Check() {
    if (Players[0].UnableCheck == 0) {
                                            Players[0].Check = 1;
                                            PlayerBetEnd = 1;
                                            if ((NPlayer + 1) == NPlayers) NPlayer = 0;
                                            else ++NPlayer;
                                            emit Signal3();
                                        }
}

void MainWindow::Fold() {
    Players[0].Fold = 1;
                                        Players[0].Check = 0;
                                        PlayerBetEnd = 1;
                                        if ((NPlayer + 1) == NPlayers) NPlayer = 0;
                                        else ++NPlayer;
                                        emit Signal3();

}

void MainWindow::StartPoker() {
    ui->GMenu->hide();
    ui->Game->show();
    Players[0].Name = ui->lineEdit->text();
    NPlayers = ui->spinBox->value();
    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
                Names[0] = "Bob";
                Names[1] = "Michael";
                Names[2] = "Vladimir";
                Names[3] = "Dick";
                Names[4] = "Alex";
                Names[5] = "Mary";
                Names[6] = "Mark";
                Names[7] = "Robert";
                Names[8] = "John";
                Names[9] = "Ann";
                Names[10] = "Steve";
                Names[11] = "Ben";
                Names[12] = "Jane";
                Names[13] = "Gabe";
                Names[14] = "George";

                Winner = -1;
                Blind = 50;
                for (i = 1; i < NPlayers; i++) {
                    k = rand() % NNames;
                    while (Names[k] == "N") k = qrand() % NNames;
                    Players[i].Name = Names[k];
                    Names[k] = "N";
                }
                for (j = 0; j < NPlayers; j++) {
                    Players[j].Money = 1000;
                    Players[j].Out = 0;
                }
                Dealer = qrand() % NPlayers;
    emit Signal1();
}

void MainWindow::RoundStart() {
    Stage = 0;
                    Bank = 0;
                    NCard = 0;
                    for (i = 0; i < 3; i++) BankWinner.R[i] = -1;
                    for (i = 0; i < NCards; i++) Deck[i].Level = 0;
                    for (i = 0; i < NSuits; i++) {
                        for (j = 2; j <= CMaxLvel; j++) {
                            k = qrand() % NCards;
                            while (Deck[k].Level != 0) k = qrand() % NCards;
                            Deck[k].Level = j;
                            Deck[k].Suit = i;
                        }
                    }
                    for (j = 0; j < NPlayers; j++) {
                        Players[j].Fold = 0;
                        Players[j].Bet = 0;
                        Players[j].Check = 0;
                        Players[j].ShowCards = 0;
                        Players[j].UnableCall = 0;
                        Players[j].UnableRaise = 0;
                        Players[j].UnableCheck = 0;
                    }
                    for (i = 0; i < 2; i++) for (j = 0; j < NPlayers; j++) {
                        Players[j].Cards[i] = Deck[NCard];
                        ++NCard;
                    }
                    ++NCard;
                    for (i = 0; i < NDesk; i++) {
                        Desk[i] = Deck[NCard];
                        if (i == 2 || i == 3) NCard += 2;
                        else ++NCard;
                    }
                    if ((Dealer + 1) == NPlayers) SBlind = 0;
                    else SBlind = Dealer + 1;
                    while (Players[SBlind].Out == 1) {
                        if ((SBlind + 1) == NPlayers) SBlind = 0;
                        else ++SBlind;
                    }
                    if (Players[SBlind].Money < Blind) Players[SBlind].Bet = Players[SBlind].Money;
                    else Players[SBlind].Bet = Blind;
                    if ((SBlind + 1) == NPlayers) BBlind = 0;
                    else BBlind = SBlind + 1;
                    while (Players[BBlind].Out == 1) {
                        if ((BBlind + 1) == NPlayers) BBlind = 0;
                        else ++BBlind;
                    }
                    if (Players[BBlind].Money < Blind * 2) Players[BBlind].Bet = Players[BBlind].Money;
                    else Players[BBlind].Bet = Blind * 2;
                    if ((BBlind + 1) == NPlayers) NPlayer = 0;
                    else NPlayer = BBlind + 1;
                    Bet = Blind * 2;
                    if (Bet > Players[0].Bet) Players[0].UnableCheck = 1;
                    if (Bet > Players[0].Money) {
                        Players[0].UnableCall = 1;
                        Players[0].UnableRaise = 1;
                    }
    emit Signal5();

}

void MainWindow::RoundF() {
if (Stage >= 6) emit Signal6();
                        if (Stage != 0) {
                            Bet = 0;
                            for (i = 0; i < NPlayers; i++) {
                                Players[i].Bet = 0;
                                Players[i].Check = 0;
                                Players[i].UnableCheck = 0;
                                Players[i].UnableCall = 0;
                            }
                            if ((Dealer + 1) == NPlayers) NPlayer = 0;
                            else NPlayer = Dealer + 1;
                        }
                        emit Signal3();
}

void MainWindow::Round() {
                        BetEnd = 0;

                            while (NPlayer != 0 && BetEnd == 0) {
                            k = ((Bet / Blind) - 2) * 3;
                            if (Players[NPlayer].Fold == 0 && Players[NPlayer].Out == 0 && NPlayer != 0) {
                                switch (Stage) {
                                case 0:
                                    if (CountHand(Players[NPlayer], Dealer, NPlayer, NPlayers) < (25 + k) && (NPlayer != BBlind || (NPlayer == BBlind && k > 0))) Players[NPlayer].Fold = 1;
                                    else if (CountHand(Players[NPlayer], Dealer, NPlayer, NPlayers) < (33 + k)) {
                                        if (Players[NPlayer].Money < Bet) Players[NPlayer].Bet = Players[NPlayer].Money;
                                        else Players[NPlayer].Bet = Bet;
                                    }
                                    else if (CountHand(Players[NPlayer], Dealer, NPlayer, NPlayers) < (40 + k)) {
                                        if (Players[NPlayer].Money < Bet + Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                        else {
                                            Players[NPlayer].Bet = Bet + Blind;
                                            Bet += Blind;
                                        }
                                    }
                                    else if (CountHand(Players[NPlayer], Dealer, NPlayer, NPlayers) > (39 + k)) {
                                        if (Players[NPlayer].Money < Bet + Blind * 2) Players[NPlayer].Bet = Players[NPlayer].Money;
                                        else {
                                            Players[NPlayer].Bet = Bet + Blind * 2;
                                            Bet += Blind * 2;
                                        }
                                    }
                                    break;
                                case 3:
                                    if (CountPWinFactor(Players[NPlayer], Desk, Stage) < CountRWinFactor(Desk, Stage) + k && Bet > 0) {
                                        Players[NPlayer].Fold = 1;
                                        Players[NPlayer].Check = 0;
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) < CountRWinFactor(Desk, Stage) + k && Bet == 0) Players[NPlayer].Check = 1;
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 2) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 2;
                                                Bet = Blind * 2;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else Players[NPlayer].Bet = Bet;
                                        }
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= 2 * CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 3) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 3;
                                                Bet = Blind * 3;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet + Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Bet + Blind;
                                                Bet += Blind;
                                            }
                                        }
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= 5 * CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 5) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 5;
                                                Bet = Blind * 5;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet + 3 * Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Bet + 3 * Blind;
                                                Bet += Blind;
                                            }
                                        }
                                    }
                                    break;
                                case 4:
                                    if (CountPWinFactor(Players[NPlayer], Desk, Stage) < CountRWinFactor(Desk, Stage) + k && Bet > 0) {
                                        Players[NPlayer].Fold = 1;
                                        Players[NPlayer].Check = 0;
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) < CountRWinFactor(Desk, Stage) + k && Bet == 0) Players[NPlayer].Check = 1;
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 2) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 2;
                                                Bet = Blind * 2;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else Players[NPlayer].Bet = Bet;
                                        }
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= 2 * CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 3) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 3;
                                                Bet = Blind * 3;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet + Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Bet + Blind;
                                                Bet += Blind;
                                            }
                                        }
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= 5 * CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 5) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 5;
                                                Bet = Blind * 5;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet + 3 * Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Bet + 3 * Blind;
                                                Bet += Blind;
                                            }
                                        }
                                    }
                                    break;
                                case 5:
                                    if (CountPWinFactor(Players[NPlayer], Desk, Stage) < CountRWinFactor(Desk, Stage) + k && Bet > 0) {
                                        Players[NPlayer].Fold = 1;
                                        Players[NPlayer].Check = 0;
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) < CountRWinFactor(Desk, Stage) + k && Bet == 0) Players[NPlayer].Check = 1;
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 2) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 2;
                                                Bet = Blind * 2;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else Players[NPlayer].Bet = Bet;
                                        }
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= 2 * CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 3) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 3;
                                                Bet = Blind * 3;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet + Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Bet + Blind;
                                                Bet += Blind;
                                            }
                                        }
                                    }
                                    else if (CountPWinFactor(Players[NPlayer], Desk, Stage) >= 5 * CountRWinFactor(Desk, Stage) + k) {
                                        if (Bet == 0) {
                                            if (Players[NPlayer].Money < Blind * 5) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Blind * 5;
                                                Bet = Blind * 5;
                                            }
                                        }
                                        if (Bet != 0) {
                                            if (Players[NPlayer].Money < Bet + 3 * Blind) Players[NPlayer].Bet = Players[NPlayer].Money;
                                            else {
                                                Players[NPlayer].Bet = Bet + 3 * Blind;
                                                Bet += Blind;
                                            }
                                        }
                                    }
                                    break;
                                }
                            }
                            if ((NPlayer + 1) == NPlayers) NPlayer = 0;
                            else ++NPlayer;
                            BetEnd = 1;
                                for (i = 0; i < NPlayers; i++) if (Players[i].Fold == 0 && Players[i].Out == 0) if ((Players[i].Bet != Bet && Players[i].Bet != Players[i].Money) || (Bet == 0 && Players[i].Check == 0)) {
                                    BetEnd = 0;
                                    break;
                                }
                                j = 0;
                                if (Bet > Players[0].Bet) Players[0].UnableCheck = 1;
                                if (Bet > Players[0].Money) {
                                    Players[0].UnableCall = 1;
                                    Players[0].UnableRaise = 1;
                                }
                        }
                            if (BetEnd == 0) emit Signal2();
              if (BetEnd == 1) emit Signal4();

}

void MainWindow::RoundEnd() {
    for (i = 0; i < NPlayers; i++) {
        Bank += Players[i].Bet;
        Players[i].Money -= Players[i].Bet;
    }
    if (Stage == 0) Stage = 3;
    else ++Stage;
    emit Signal5();
}

void MainWindow::RoundE() {
    BankWinner = WinnerCheck(Players, NPlayers, Desk, Stage - 1);
                        j = 0;
                        for (i = 0; i < 3; i++) if (BankWinner.R[j] != -1) ++j;
                        for (i = 0; i < NPlayers; i++) if (Players[i].Fold == 0 && Players[i].Out == 0) Players[i].ShowCards = 1;
                        for (i = 0; i < j; i++) Players[BankWinner.R[i]].Money += (Bank / j);
                        ui->Winners->insertPlainText("Winners: ");
                        for (i = 0; i < j; i++) {
                            ui->Winners->insertPlainText(Players[BankWinner.R[i]].Name);
                            ui->Winners->insertPlainText(" ");
                        }
                        if (Dealer == NPlayers - 1) Dealer = 0;
                                        else ++Dealer;
                                        while (Players[Dealer].Out == 1) {
                                            if ((Dealer + 1) == NPlayers) Dealer = 0;
                                            else ++Dealer;
                                        }
    emit Signal1();
}

void MainWindow::PokerExit() {
    ui->Game->hide();
    ui->GMenu->show();
}
