#ifndef VIEWMODEL
#define VIEWMODEL
#include"src/Common/Observer.h"
#include"src/Model/Model.h"
#include"src/Common/BaseCommand.h"
#include<memory>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<vector>
#include<QString>
class ViewModel:public Observable,public Observer
{
public:
    ViewModel();
    virtual void update(Notify noti);
    void AddMusicToList(const vector<QString> p);
    void changeTone(const QString &path, const QString &tone);
    void changeFreq(const QString &path, const double &freq);

    void setmodel(const shared_ptr<Model> &m)
    { pModel = m;
      if(pModel) qDebug()<<pModel.get();
      qDebug()<<"The use of pModel in setModel"<<pModel.use_count();
    }

    shared_ptr<BaseCommand>getAddMusicToListCommand() { return addMusicToListCommand; }
    shared_ptr<BaseCommand>getToneChangeCommand() { return toneChangeCommand; }
    shared_ptr<BaseCommand>getFrequencyChangeCommand() { return frequencyChangeCommand; }

    shared_ptr<QMediaPlaylist> getplayList(){return playList;}
    shared_ptr<Model>pModel;
private:
    shared_ptr<BaseCommand> addMusicToListCommand,toneChangeCommand,frequencyChangeCommand;

    shared_ptr<QMediaPlaylist>playList;


};

#endif

