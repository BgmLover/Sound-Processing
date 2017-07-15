#include"src/Viewmodel/ViewModel.h"
#include"src/Viewmodel/Commands/AddMuiscToListCommand.h"
#include"src/Viewmodel/Commands/frequencychangecommand.h"
#include"src/Viewmodel/Commands/tonechangecommand.h"
#include<QUrl>
#include<QString>
#include<QMediaPlayer>
#include<QMediaPlaylist>
ViewModel::ViewModel()
{
    addMusicToListCommand = static_pointer_cast<BaseCommand, AddToListCommand>(shared_ptr<AddToListCommand>(new AddToListCommand));
    toneChangeCommand=static_pointer_cast<BaseCommand,ToneChangeCommand>(shared_ptr<ToneChangeCommand>(new ToneChangeCommand));
    frequencyChangeCommand=static_pointer_cast<BaseCommand,FrequencyChangeCommand>(shared_ptr<FrequencyChangeCommand>(new FrequencyChangeCommand));
    pModel=shared_ptr<Model>(new Model);
    if(pModel) qDebug()<<pModel.get();
    qDebug()<<"The use of pModel in constructor"<<pModel.use_count();
    addMusicToListCommand->setViewModel(this);
    toneChangeCommand->setViewModel(this);
    frequencyChangeCommand->setViewModel(this);
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
         qDebug()<<"The use of pModel after cmd addtolist"<<pModel.use_count();
         break;


        }
        case Notifys::ChangeFreq:
        {
         qDebug()<<"Frequency has changed in viewModel!";
         playList->clear();
         vector<QString> s = pModel->getPaths();
         size_t m = s.size();
         for (i = 0; i<m; i++)
            {
                 QString path = pModel->getPaths().at(i);
                 playList->addMedia(QUrl::fromLocalFile(path));
            }
         Notify noti;
         noti.settype(Notifys::ChangeFreq);
         notify(noti);
         break;
        }
     }
 }
 void ViewModel::AddMusicToList(const vector<QString>p)
 {
     pModel->addPath(p);
 }

 void ViewModel::changeTone(const QString &path, const QString &tone)
 {
    pModel->changeTone(path,tone);
 }

 void ViewModel::changeFreq(const QString &path, const double &freq)
 {
    qDebug() << "viewModel is changing...";
   // qDebug()<<pModel.use_count();
    if(pModel.get()!=nullptr)
        qDebug() << "pModel exists!\n";
    pModel->changeFreq(path,freq);
 }
