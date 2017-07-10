#ifndef BASECOMMAND
#define BASECOMMAND
#include"src/Common/Params.h"
#include"src/Model/Model.h"
class BaseCommand
{
public:
    BaseCommand(const shared_ptr<Model> &pModel): pModel(pModel){}
    void setParams(const Params &params){BaseCommand::params=params;}
    virtual void exec()=0;
    bool send=false;
    shared_ptr<Model> pModel;
    Params params;


};

#endif
