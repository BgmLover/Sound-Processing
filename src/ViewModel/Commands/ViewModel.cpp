#include"src/Viewmodel/ViewModel.h"
#include"src/Viewmodel/Commands/AddMuiscToListCommand.h"
#include<QUrl>
#include<QString>
#include<QMediaPlayer>
#include<QMediaPlaylist>
ViewModel::ViewModel()
{
    addMusicToListCommand = static_pointer_cast<BaseCommand, AddToListCommand>(shared_ptr<AddToListCommand>(new AddToListCommand));
    addMusicToListCommand->setViewModel(this);
    playList = shared_ptr<QMediaPlaylist>(new QMediaPlaylist);

}

 void ViewModel::update(Notify noti)
 {
     size_t i = 0;
     switch(noti.gettype())
     {
       case Notifys::AddMusicToList:
       {
         playList->clear();
         vector<QString> s = pModel->getPaths();
         size_t m = s.size();
         for (i = 0; i<m; i++)
            {
                 QString path = pModel->getPaths().at(i);
                 playList->addMedia(QUrl::fromLocalFile(path));
            }

         Notify noti;
         if (i > 0) noti.settype(Notifys::AddToListFinished);
         else       noti.settype(Notifys::failed);

         notify(noti);
         break;
        }
     }
 }
 void ViewModel::AddMusicToList(const vector<QString>p)
 {
     pModel->addPath(p);
 }
