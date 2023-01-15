#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

//klasa Score - wynik gracza

class Score: public QGraphicsTextItem
{
public:
    Score(); // kontruktor ustawiajacy wynik gracza, jego pozycje, kolor oraz czcionke
    void increase(); //metoda inkrementujaca wynik
    void reset(); //metoda resetujaca wynik
    int getscore(); //metoda zwacajaca wynik
private:
    int score; // wynik gracza
};

#endif // SCORE_H
