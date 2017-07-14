#ifndef BASECOMMAND
#define BASECOMMAND
#include"src/Common/Params.h"
#include<memory>


class ViewModel;
class BaseCommand
{
public:
    void setParams(const Params &p){params=p;}
    void setViewModel( ViewModel *pvm) { pViewModel = pvm; }
    virtual void exec()=0;

protected:
    Params params;
    ViewModel *pViewModel;

};
#endif
