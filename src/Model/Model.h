#ifndef MODEL
#define MODEL
#include"src/Common/Observable.h"
#include"src/Common/Types.h"
#include"src/Common/Notify.h"
#include<QString>
class Model :public Observable
 {
 public:
  vector<QString>getPaths();
// void setPaths(const shared_ptr<vector<QString>>&paths);
 void addPath(const vector<QString> path);


private:
 vector<QString> Paths;

 };


#endif
