#include "src/View/mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    playList = shared_ptr<QMediaPlaylist>(new QMediaPlaylist);
    player = shared_ptr<QMediaPlayer>(new QMediaPlayer);
//	player->setPlaylist(playList.get());

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(Notify noti)
{
    switch(noti.gettype())
    {
    case Notifys::AddToListFinished :
         {
             qDebug() << "Add music successfully!";
             break;
         }
    }
}


void MainWindow::on_PlayButton_clicked()
{
    player->setPlaylist(playList.get());
    qDebug() << playList->isEmpty()<<"   "<< playList->mediaCount();

       player->play();
}



void MainWindow::on_AddMuiscButton_clicked()
{
    QString initialName=QDir::homePath();
    QStringList pathList=QFileDialog::getOpenFileNames(this, tr("选择文件"), initialName, tr("*.wav *mp3"));
    vector<QString>temp;
    for(int i=0; i<pathList.size(); ++i)
    {
        QString path=QDir::toNativeSeparators(pathList.at(i));
        temp.push_back(path);
     }
    Params param;

    param.setstring(temp);
    addMusicToListCommand->setParams(param);
    addMusicToListCommand->exec();
}

