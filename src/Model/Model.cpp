#include"src/Model/Model.h"
#include "src/Common/soundTouch/change.hpp"
#include <QDebug>
#include<QString>
#include<QStringList>
void Model::addPath(const vector<QString> path)
{
    for (size_t i = 0; i < path.size(); i++)
    {
        QString temp = path.at(i);
        Paths.push_back(temp);
    }
    Notify noti;
    noti.settype(Notifys::AddMusicToList);
    notify(noti);
}

void Model::changeFreq(const QString &path, const double &freq)
{
    qDebug() << "Model changing freq..." << endl;
    const QString tone = "A6";
    const string addr = path.toStdString();
    qDebug()<<path;
    const string temp = tone.toStdString();
    QString tem=change_once(addr, temp, freq);
    qDebug() << "Freq is changed" << endl;
    vector<QString>tems;
    tems.push_back(tem);
    addPath(tems);
    Notify noti;
    noti.settype(Notifys::ChangeFreq);
    notify(noti);
}

void Model::changeTone(const QString &path, const QString &tone)
{
    const double freq = 1.0;
    const string addr = path.toStdString();
    const string temp = tone.toStdString();

    QString tem=change_once(addr, temp, freq);
    qDebug() << "Tone is changed" << endl;
    vector<QString>tems;
    tems.push_back(tem);
    addPath(tems);
    Notify noti;
    noti.settype(Notifys::ChangeTone);
    notify(noti);
}

vector<QString> Model::getPaths()
{
    return Paths;
}
