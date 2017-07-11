#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"src/Common/Observer.h"
#include"src/Common/BaseCommand.h"
#include<memory>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<vector>
#include<string>
#include<QString>
#include"src/Viewmodel/ViewModel.h"
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

    ~MainWindow();

private slots:
    void on_PlayButton_clicked();

    void on_AddMuiscButton_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<QMediaPlayer> player;
    shared_ptr<QMediaPlaylist>playList;
    shared_ptr<BaseCommand> addMusicToListCommand,musicPlayCommand;
};

#endif // MAINWINDOW_H
