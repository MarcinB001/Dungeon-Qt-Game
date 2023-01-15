#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

//klasa Player - gracz szukajacy klejnotu i omijajacy sciany

class Player : public QGraphicsRectItem
{
public:
    Player(); // konstruktor zawierajacy wymiar oraz kolor gracza
    void keyPressEvent(QKeyEvent * event); // metoda poruszajaca graczem po kliknieciu strzalkami oraz spprawdzajaca czy gracz wszedl w kljnot lub sciane
};

#endif // MYRECT_H
