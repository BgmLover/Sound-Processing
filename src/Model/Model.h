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
 void changeFreq(const QString &path, const double &freq);
 void changeTone(const QString &path, const QString &tone);

private:
 vector<QString> Paths;

 };


#endif
