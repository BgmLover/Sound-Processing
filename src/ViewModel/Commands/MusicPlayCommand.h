#ifndef MUSICPLAYCOMMAND
#define MUSICPLAYCOMMAND
#include"src/Common/BaseCommand.h"

class MusicPlayCommand: public BaseCommand
{
public:
    MusicPlayCommand(const shared_ptr<Model> &pModel) : BaseCommand(pModel) {}
    virtual void exec(){
    }

};

#endif
