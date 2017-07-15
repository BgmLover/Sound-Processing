#include "src/View/mainwindow.h"
#include <QFileDialog>
#include <QFileInfo>
#include<QDebug>
#include<QTimer>
#include<QDateTime>
#include<strstream>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#include<QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    playList = shared_ptr<QMediaPlaylist>(new QMediaPlaylist);
    player = shared_ptr<QMediaPlayer>(new QMediaPlayer);
    result = FMOD_System_Create(&system);
    result = FMOD_System_Init(system, 32, FMOD_INIT_NORMAL, 0);
    sound = 0;
    channel = 0;
    wav.resize(2048);
    ui->ploter=new CurvePlot();
    ui->ploterAll=new CurvePlot();
    ui->ploter->setAdjustVal(0.5);
    ui->ploter->Pen = QPen(QBrush(QColor(89, 172, 255)), 1);
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

                // QString path=QDir::toNativeSeparators(playList->media(i).canonicalUrl().toLocalFile());
                 QString path=playList->media(i).canonicalUrl().toLocalFile();
                 if(!path.isEmpty())
                 {
                     QString filename=path.split("/").last();
                     //qDebug()<<filename;
                     QString index;
                     index=index.number(i+1);
                     index=index+".   ";
                     index=index+filename;
                     ui->listWidget->addItem(index);
                     QFont f;
                     f.setPointSize(15);
                     ui->listWidget->setFont(f);
                 }
             }
             break;
         }
       case Notifys::ChangeFreq:
          {
              qDebug()<<"Frequency has changed in view!";
              break;
          }
       case Notifys::ChangeTone:
          {
              qDebug()<<"Tone has changed in view!";
              break;
          }
       case Notifys::failed:
         {
             qDebug()<<"error!";
             break;
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
    QFont ft;
    ft.setPointSize(20);
    ui->PositionLable->setFont(ft);
}
void MainWindow::mainwindowinit()
{
    connect(ui->actionTone,SIGNAL(triggered()),this,SLOT(cmdTone()));
    connect(&tone,SIGNAL(toneReturn(QString)),this,SLOT(getTone(QString)));
    connect(ui->actionFrequency,SIGNAL(triggered()),this,SLOT(cmdFrequency()));
    connect(&frequency,SIGNAL(frequencyReturn(double)),this,SLOT(getFrequency(double)));
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimer()));
    connect(ui->actionAdd,SIGNAL(triggered()),this,SLOT(cmdAdd()));
    connect(ui->actionPause,SIGNAL(triggered()),this,SLOT(cmdPause()));
    connect(ui->actionPlay,SIGNAL(triggered()),this,SLOT(cmdPlay()));
    connect(ui->actionStop,SIGNAL(triggered()),this,SLOT(cmdStop()));
    connect(ui->actionLast,SIGNAL(triggered()),this,SLOT(cmdLast()));
    connect(ui->actionNext,SIGNAL(triggered()),this,SLOT(cmdNext()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(ui->actionAboutThis,SIGNAL(triggered()),this,SLOT(cmdAboutThis()));
}
void MainWindow::cmdAboutThis()
{
    QMessageBox::about(this, tr("关于本产品"), tr("<h2>MiniAudio 1.0"));
}

void MainWindow::cmdAdd()
{
    qDebug()<<"hhhhh";
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
void MainWindow::cmdLast()
{
    int currentIndex=playList->currentIndex();
    if(--currentIndex==-1)currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    cmdPlay();
}
void MainWindow::cmdNext()
{
    int currentIndex=playList->currentIndex();
    if(++currentIndex==playList->mediaCount())currentIndex=0;
    playList->setCurrentIndex(currentIndex);
    cmdPlay();
}
void MainWindow::cmdPlay(){
    qDebug()<<"我要放歌啦！";
     player->play();
   //  player->setVolume(0);
     QString strFile = QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
     qDebug()<<strFile;
     plotAllWav(strFile.toLocal8Bit().data());
     //显示当前播放歌曲
     QString f=QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
     f=f.split("\\").last();
     ui->MusicName->setText(f);
     QFont ft;
     ft.setPointSize(20);
     ui->MusicName->setFont(ft);

     timer.start(400);
}
void MainWindow::cmdPause()
{
    player->pause();
    timer.stop();
}
void MainWindow::cmdStop()
{
        player->stop();
        timer.stop();
}
void MainWindow::cmdTone()
{
      tone.exec();
}
void MainWindow::cmdFrequency()
{
    frequency.exec();
}
//获得频率值，执行命令
void MainWindow::getFrequency(double freValue)
{
    qDebug()<<"显示获得的频率值"<<freValue;
    QString path=QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
    vector<QString>paths;
    paths.push_back(path);
    Params param;
    param.setfrequency(freValue);
    param.setstring(paths);
    //qDebug() << "mainwindow's param.path[0]:" << param.path[0] << endl;
    frequencyChangeCommand->setParams(param);
    qDebug() << "显示中呵呵哒。"<< endl;
    frequencyChangeCommand->exec();
    qDebug() << "显示完毕呵呵哒。"<< endl;
}
//获得音调值，执行命令
void MainWindow::getTone(QString tonevalue)
{
    qDebug()<<"显示获得的音调值"<<tonevalue;
    QString path=QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
    vector<QString>paths;
    paths.push_back(path);
    Params param;
    param.setstring(paths);
    param.settone(tonevalue);
    toneChangeCommand->setParams(param);
    toneChangeCommand->exec();
}


void MainWindow::plotAllWav(char *fileName)
{
    FMOD_System_CreateSound(system, fileName, FMOD_2D | FMOD_SOFTWARE | FMOD_CREATESAMPLE, 0, &sound);
    uint bytes, len1, len2;
    void *ptr1, *ptr2;
    FMOD_Sound_GetLength(sound, &bytes, FMOD_TIMEUNIT_PCMBYTES);
    FMOD_Sound_Lock(sound, 0, bytes, &ptr1, &ptr2, &len1, &len2);

    bytes /= 2;
    int step= 1, len= bytes;
    if (bytes > 10000)
    {
        len = 10000;
        step= (int)(bytes / len);
    }
    QVector<float>wavAll(10000);
    short* ps = (short*)ptr1;
    for (int i= 0, n = 0; n< len; i+= step, n++)
        wavAll[n] = ps[i];
    FMOD_Sound_Unlock(sound, ptr1, ptr2, len1, len2);
    FMOD_Sound_Release(sound);
    ui->ploterAll->outPut(wavAll);
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
    QFont ft;
    ft.setPointSize(20);
    ui->PositionLable->setFont(ft);

   // qDebug()<<position;
}

void MainWindow::slot_updateList(int value)
{
    ui->listWidget->setCurrentRow(value);
    ui->listWidget->currentItem()->setSelected(true);
   /* qDebug()<<"设置当前序号"<<ui->listWidget->currentIndex().row();
    qDebug()<<"当前参数value"<<value;
    qDebug()<<"列表项目数量"<<ui->listWidget->count();
    qDebug()<<"列表当前项目序号"<<ui->listWidget->currentRow();
    qDebug()<<"列表当前项目序号"<<ui->listWidget->currentIndex().row();
    qDebug()<<"歌单当前序号"<<playList->currentIndex();*/

    //item->setSelected(true);
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    ui->MusicName->setText(ui->listWidget->currentItem()->text());
    playList->setCurrentIndex(ui->listWidget->currentRow());
    cmdPlay();
}
void MainWindow::onTimer()
{
    /*float *dat = new float[16384];
    FMOD_System_GetWaveData(system, dat, 16384, 0);
    //FMOD_System_GetSpectrum(system, dat, 8192, 1, FMOD_DSP_FFT_WINDOW_RECT); 频谱
    for (int i = 0, n = 0; i < 16384; i+= 8, n++)
        wav[n] = dat[i];
    ui->ploter->outPut(wav);
    delete [] dat;*/
    QString strFile = QDir::toNativeSeparators(playList->currentMedia().canonicalUrl().toLocalFile());
    FMOD_System_CreateSound(system, strFile.toLocal8Bit().data(), FMOD_2D | FMOD_SOFTWARE | FMOD_CREATESAMPLE, 0, &sound);
    uint bytes, len1, len2;
    void *ptr1, *ptr2;
    FMOD_Sound_GetLength(sound, &bytes, FMOD_TIMEUNIT_PCMBYTES);
    FMOD_Sound_Lock(sound, 0, bytes, &ptr1, &ptr2, &len1, &len2);

    bytes /= 2;
    int step= 1, len= bytes;

    printf("%d",(int)bytes);
    if (bytes > 10000)
    {
        len = 10000;
        step= (int)(bytes / len);
    }
    double rate=1.0*player->position()/player->duration();
              qDebug()<<"这首歌的长度"<<player->duration();
              qDebug()<<"这首歌现在的进度"<<player->position();
             // qDebug()<<rate<<"  "<<"   "<<len;
    int bu=rate*len;
    qDebug()<<"现在的段数"<<bu;
    QVector<float>wave(500);
    short* ps = (short*)ptr1;
    for (int i= bu, n = 0; n< 500; i+= step, n++)
        wave[n] = ps[i];
    FMOD_Sound_Unlock(sound, ptr1, ptr2, len1, len2);
    FMOD_Sound_Release(sound);
    ui->ploter->outPut(wave);
}
