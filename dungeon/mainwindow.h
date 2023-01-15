#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <vector>
#include <random>
#include "Wall.h"
#include "Player.h"
#include "Gem.h"
#include "Score.h"
#include "Border.h"


//klasa MainWindow - okno gry

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(); //konstruktor
    ~MainWindow(); //destruktor
    void generateWalls(); //metoda generujaca losowo sciany
    void GemSetPosition(); //metoda generujaca losowo pozycje klejnotu z zabepieczeniem przed wylosowaniem tego samego miejsca co sciana
    void PlayerSetPosition(); //metoda generujaca losowo pozycje gracza z zabepieczeniem przed wylosowaniem tego samego miejsca co sciana lub klejnot
    void increaseScore(); //meotda inkrementujaca wynik gracza
    void resetScore(); //metoda resetujaca wynik gracza


private slots:
    void on_pushButton_clicked(); //metoda obslugujaca klikniecie przycisku "START"

private:

    //deklaracja zmiennych: sceny, gracza, klejnotu, granicy planszy oraz scian

    Ui::MainWindow *ui;
    QGraphicsScene * scene;
    Player * player;
    Gem * gem;
    Score * score;
    Border * border;
    Wall * wall1;
    Wall * wall2;
    Wall * wall3;
    Wall * wall4;
    Wall * wall5;
    Wall * wall6;
    Wall * wall7;
    Wall * wall8;
    Wall * wall9;
    Wall * wall10;
};
#endif // MAINWINDOW_H
