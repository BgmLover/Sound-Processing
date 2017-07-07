#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QUrl>
#include<QString>
#include<QSoundEffect>
#include<QSound>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString n="ifyou.mp3";
    ui->setupUi(this);


   QMediaPlayer *player=new QMediaPlayer;
   connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));

    player->setMedia(QUrl::fromLocalFile("D:\CloudMusic/ifyou.wav"));
    player->setVolume(100);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}
