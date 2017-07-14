#ifndef ADDMUSICCOMMAND
#define ADDMUSICCOMMAND
#include"src/Common/BaseCommand.h"
#include <QFileDialog>
#include <QFileInfo>
class ViewModel;
class AddToListCommand: public BaseCommand
{
public:

    virtual void exec()
    {
        pViewModel->AddMusicToList(params.getpath());

    }

};
#endif
