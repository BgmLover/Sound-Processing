#ifndef MODEL
#define MODEL
#include"src/Common/Observable.h"
#include"src/Common/Types.h"
#include"src/Common/Notify.h"
#include<QString>
 class Model :public Observable
 {
 public:
 vector<QString>* getPaths();
 void setPaths(const vector<QString>&paths);
 void addPath(const QString &path);


private:
 vector<QString> Paths;

 };



#endif
