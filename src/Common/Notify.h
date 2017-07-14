#ifndef NOTIFY
#define NOTIFY
class Notify
{
public:
    int gettype(){return this->type;}
    void settype(const int &type){this->type=type;}
private:
    int type;
};
#endif
