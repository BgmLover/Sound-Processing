#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"src/Common/Observer.h"
#include"src/Common/BaseCommand.h"
#include "ui_mainwindow.h"
#include<memory>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<vector>
#include<string>
#include<QString>
#include"src/Viewmodel/ViewModel.h"
#include"src/View/tone.h"
#include"src/View/frequency.h"
#include<QObject>
#include"src/View/Plot/fmod.h"
#include"src/View/Plot/fmod_errors.h"
#include"src/View/Plot/curveplot.h"
#include<QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual void update(Notify noti);
    void setplaylist(shared_ptr<QMediaPlaylist> playList1){playList=playList1;}
    void setaddMusicToListCommand(shared_ptr<BaseCommand> add){addMusicToListCommand=add;}
    void settoneChangeCommand(shared_ptr<BaseCommand>tone){toneChangeCommand=tone;}
    void setfrequencyChangeCommand(shared_ptr<BaseCommand>fre){frequencyChangeCommand=fre;}
    void playerinit();
    void mainwindowinit();
    void slot_positionChanged(qint64 position);
    void slot_rangechanged(qint64 duration);
    void slot_updateList(int value);
    ~MainWindow();

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void cmdTone();
    void cmdFrequency();
    void cmdAdd();
    void cmdPause();
    void cmdStop();
    void cmdLast();
    void cmdNext();
    void cmdPlay();
    void cmdAboutThis();
    void getTone(QString tonevalue);
    void getFrequency(double freValue);
    void plotAllWav(char *fileName);
    void on_listWidget_doubleClicked(const QModelIndex &index);

public slots:
    void onTimer();

private:
    Ui::MainWindow *ui;
    shared_ptr<QMediaPlayer> player;
    shared_ptr<QMediaPlaylist>playList;
    shared_ptr<BaseCommand> addMusicToListCommand,toneChangeCommand,frequencyChangeCommand;
    Tone tone;
    Frequency frequency;

    QTimer timer;
    QVector<float>wav;
    FMOD_SYSTEM *system;
    FMOD_SOUND *sound;
    FMOD_CHANNEL *channel;
    FMOD_RESULT result;
};

#endif // MAINWINDOW_H
