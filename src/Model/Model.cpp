#include"src/Model/Model.h"
void Model::setPaths(const vector<QString>&paths)
{
    Model::Paths=paths;
    //Params params;
    //params.settype(Notify::AddMusicToList);
    //notify(params);
    Notify noti;
    noti.settype(Notifys::AddMusicToList);
    notify(noti);
}

void Model::addPath(const QString &path)
{
    Model::Paths.push_back(path);
   // Params params;
   // params.settype(Notify::AddMusicToList);
   // notify(params);
    Notify noti;
    noti.settype(Notifys::AddMusicToList);
    notify(noti);
}
vector<QString>* Model::getPaths()
{
    return &Paths;
}
