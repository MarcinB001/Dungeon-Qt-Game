#include "Score.h"

#include <QFont>

Score::Score()
{
        score =0;

        setPlainText(QString("Score: ")+QString::number(score));
        setPos(800,300);
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));

}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

void Score::reset()
{
    score=0;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getscore()
{
    return score;
}

