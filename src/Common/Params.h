#ifndef PARAMS
#define PARAMS

#include<QString>
#include<vector>
#include<memory>
#include<string>
using namespace std;

class Params
{
public:

   int getvolume(){return volume;}
   void setvolume(const int &volume){this->volume=volume;}
   qint64 getposition(){return position;}
   void setposition(const qint64 &position){this->position=position;}
   int getindex(){return currentindex;}
   void setcurrentindex(const int &index){this->currentindex=index;}
   QString getpath(){return path;}
   void setstring(const QString &string){this->path=string;}
   //int gettype(){return type;}
  // void settype(const int &type){this->type=type;}
private:
    int volume=100;
    qint64 position=0;  //milliseconds
    int currentindex;   //列表中的顺序
    QString path;
};

#endif
