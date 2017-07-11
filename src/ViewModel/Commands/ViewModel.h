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
    void setmodel(const shared_ptr<Model> &m) { pModel = m; }

    shared_ptr<BaseCommand>getAddMusicToListCommand() { return addMusicToListCommand; }
    shared_ptr<QMediaPlaylist> getplayList(){return playList;}

private:
    shared_ptr<BaseCommand> addMusicToListCommand;
    shared_ptr<Model>pModel;
    shared_ptr<QMediaPlaylist>playList;


};

#endif
