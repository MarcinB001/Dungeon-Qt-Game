
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>

#include <QGraphicsRectItem>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QAbstractButton>
#include <QGraphicsItem>


//generowanie pseudo-losowych liczb za pomoca Mersenna

std::vector <int> Ypositions(2,0);

std::vector <std::vector<int>> positions(10,Ypositions);

std::vector <int> PlayerPosition(2,0);
std::vector <int> GemPosition(2,0);


std::random_device rd{};
    // Use Mersenne twister engine to generate pseudo-random numbers.
std::mt19937 engine{ rd() };

    // "Filter" MT engine's output to generate pseudo-random double values,
    // **uniformly distributed** on the closed interval [0, 1].
    // (Note that the range is [inclusive, inclusive].)
std::uniform_int_distribution<int> dist{0, 6};

    // Generate pseudo-random number.



MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    player = new Player();
    gem = new Gem();
    score = new Score();

    wall1 = new Wall();
    wall2 = new Wall();
    wall3 = new Wall();
    wall4 = new Wall();
    wall5 = new Wall();
    wall6 = new Wall();
    wall7 = new Wall();
    wall8 = new Wall();
    wall9 = new Wall();
    wall10 = new Wall();

    border = new Border();

    scene->addItem(border);



    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(1000,1000);
    ui->graphicsView->setSceneRect(0,0,900,900);


    scene->addItem(score);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateWalls()
{



    scene->addItem(wall1);
    scene->addItem(wall2);
    scene->addItem(wall3);
    scene->addItem(wall4);
    scene->addItem(wall5);
    scene->addItem(wall6);
    scene->addItem(wall7);
    scene->addItem(wall8);
    scene->addItem(wall9);
    scene->addItem(wall10);



    for(int i =0; i<positions.size();++i){
        for(int j=0;j<positions[0].size();++j){
          positions[i][j]=dist(engine)*100;
        }
    }



    for(int i =0; i<positions.size();++i){
        for(int j=0;j<positions.size();++j){
            if(i!=j){
                while(positions[i][0]==positions[j][0] && positions[i][1]==positions[j][1]){
                    positions[i][0]=dist(engine)*100;
                    positions[i][1]=dist(engine)*100;
                }
            }
        }
    }

    wall1->setPos(positions[0][0],positions[0][1]);
    wall2->setPos(positions[1][0],positions[1][1]);
    wall3->setPos(positions[2][0],positions[2][1]);
    wall4->setPos(positions[3][0],positions[3][1]);
    wall5->setPos(positions[4][0],positions[4][1]);
    wall6->setPos(positions[5][0],positions[5][1]);
    wall7->setPos(positions[6][0],positions[6][1]);
    wall8->setPos(positions[7][0],positions[7][1]);
    wall9->setPos(positions[8][0],positions[8][1]);
    wall10->setPos(positions[9][0],positions[9][1]);
}

void MainWindow::GemSetPosition()
{
    GemPosition[0] = dist(engine)*100;
    GemPosition[1] = dist(engine)*100;

    for(int i = 0;i<positions.size();++i){
        while( (GemPosition[0] == positions[i][0] && GemPosition[1] == positions[i][1]) ){
            i=0;
            GemPosition[0] = dist(engine)*100;
            GemPosition[1] = dist(engine)*100;
        }
    }
    gem->setPos(GemPosition[0],GemPosition[1]);
}

void MainWindow::PlayerSetPosition()
{
    PlayerPosition[0] = dist(engine)*100;
    PlayerPosition[1] = dist(engine)*100;


    for(int i = 0;i<positions.size();++i){
        while((PlayerPosition[0] == positions[i][0] && PlayerPosition[1] == positions[i][1]) || (PlayerPosition[0]==GemPosition[0] && PlayerPosition[1]==GemPosition[1])){
            i=0;
            PlayerPosition[0] = dist(engine)*100;
            PlayerPosition[1] = dist(engine)*100;
        }
    }

    PlayerPosition[0]++;
    PlayerPosition[1]++;

    player->setPos(PlayerPosition[0],PlayerPosition[1]);
}

void MainWindow::increaseScore()
{
    score->increase();

    MainWindow::on_pushButton_clicked();

}

void MainWindow::resetScore()
{
    score->reset();
}



void MainWindow::on_pushButton_clicked()
{
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();



    MainWindow::generateWalls();
    scene->addItem(gem);
    scene->addItem(player);

    MainWindow::GemSetPosition();
    MainWindow::PlayerSetPosition();
}

