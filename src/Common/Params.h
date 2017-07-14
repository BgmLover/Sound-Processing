#ifndef PARAMS
#define PARAMS

#include<QString>
#include<vector>
#include<memory>

using namespace std;

class Params
{
public:

    //   int getvolume(){return volume;}
    //   void setvolume(const int &volume){this->volume=volume;}
    //   qint64 getposition(){return position;}
    //   void setposition(const qint64 &position){this->position=position;}
       int getindex(){return currentindex;}
       void setcurrentindex(const int &index){this->currentindex=index;}
       vector<QString>getpath(){return path;}
       void setstring(const vector<QString> &string){path=string;}
       void settone(const QString &s){this->tone=s;}
       QString gettone(){return tone;}
       void setfrequency(const double &d){frequency=d;}
       double getfrequency(){return frequency;}

    //private:
       int currentindex;   //列表中的顺序
       vector<QString> path;
       QString tone;
       double frequency;
    };

#endif
