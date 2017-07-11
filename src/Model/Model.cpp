#include"src/Model/Model.h"
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
vector<QString> Model::getPaths()
{
    return Paths;
}
