#ifndef ADDMUSICCOMMAND
#define ADDMUSICCOMMAND
#include"src/Common/BaseCommand.h"

class AddMusicToListCommand: public BaseCommand
{
public:
    AddMusicToListCommand(const shared_ptr<Model> &pModel) : BaseCommand(pModel) {}
    void exec(){
        QString path=params.getpath();
        this->pModel->addPath(path);
    }

};

#endif
