#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>

//klasa Wall - sciana ktorej gracz musi unikac

class Wall : public QGraphicsRectItem
{
public:
    Wall(); // konstruktor ustawiajacy rozmiary oraz kolor sciany
};

#endif // WALL_H
