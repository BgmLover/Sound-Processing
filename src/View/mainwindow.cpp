#include "src/View/mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include<QDebug>
#include<QTime>
#include<strstream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    playList = shared_ptr<QMediaPlaylist>(new QMediaPlaylist);
    player = shared_ptr<QMediaPlayer>(new QMediaPlayer);
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
             qDebug() <<"现在歌单已有音乐数量"<<playList->mediaCount();

             ui->listWidget->clear();
             for(int i=0;i<playList->mediaCount();i++)
             {

                 QString path=QDir::toNativeSeparators(playList->media(i).canonicalUrl().toLocalFile());
                 if(!path.isEmpty())
                 {
                     QString filename=path.split("\\").last();
                     QString index;
                     index=index.number(i+1);
                     index=index+".   ";
                     index=index+filename;
                     ui->listWidget->addItem(index);
                 }
             }
             break;
         }
    case Notifys::failed:
         {
             qDebug()<<"error!";
         }
    }

}

void MainWindow::playerinit()
{
    player->setPlaylist(playList.get());//把播放器和歌单绑定起来
    playList->setPlaybackMode(QMediaPlaylist::Loop);//循环播放
    connect(player.get(),player->positionChanged,this,slot_positionChanged);//滑块的位置随着歌曲进度改变
    connect(player.get(),player->durationChanged,this,slot_rangechanged);//滑块的范围随着歌曲改变而改变
    connect(playList.get(),playList->currentIndexChanged,this,slot_updateList);
}

void MainWindow::on_PlayButton_clicked()
{
       playList->setCurrentIndex(ui->listWidget->currentRow());
       player->play();
       //qDebug()<<player->mediaStream()->readAll().size();

       //显示当前播放歌曲
       QString f=QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
       f=f.split("\\").last();
       ui->MusicName->setText(f);
}
void MainWindow::on_PauseButton_clicked()
{
    player->pause();
}
void MainWindow::on_stopButton_clicked()
{
    player->stop();
}

//打开文件（可同时打开多个）
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

//滑块调整进度
void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    player->setPosition(value);
}
//歌曲改变后，滑块的范围也发生改变
void MainWindow::slot_rangechanged(qint64 duration)
{
   ui->horizontalSlider->setRange(0,duration);
}
//滑块的值随着歌曲的进度而改变，并且显示当前时间
void MainWindow::slot_positionChanged(qint64 position)
{

    QTime duration(0,position/60000,qRound((position%60000)/1000.0));
    ui->PositionLable->setText(duration.toString(tr("mm:ss")));
    ui->horizontalSlider->setValue(position);

   // qDebug()<<position;
}



void MainWindow::on_NextButton_clicked()
{
    int currentIndex=playList->currentIndex();
    if(++currentIndex==playList->mediaCount())currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    player->play();
    QString f=QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
    f=f.split("\\").last();
    ui->MusicName->setText(f);
}

void MainWindow::on_LastButton_clicked()
{
    int currentIndex=playList->currentIndex();
    if(--currentIndex==-1)currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    player->play();
    QString f=QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
    f=f.split("\\").last();
    ui->MusicName->setText(f);
}

void MainWindow::slot_updateList(int value)
{
    ui->listWidget->setCurrentRow(value);
    ui->listWidget->currentItem()->setSelected(true);
    qDebug()<<"设置当前序号"<<ui->listWidget->currentIndex().row();
    qDebug()<<"当前参数value"<<value;
    qDebug()<<"列表项目数量"<<ui->listWidget->count();
    qDebug()<<"列表当前项目序号"<<ui->listWidget->currentRow();
    qDebug()<<"列表当前项目序号"<<ui->listWidget->currentIndex().row();
    qDebug()<<"歌单当前序号"<<playList->currentIndex();

    //item->setSelected(true);
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    ui->MusicName->setText(ui->listWidget->currentItem()->text());
    playList->setCurrentIndex(ui->listWidget->currentRow());
    player->play();
}
