#ifndef TONECHANGECOMMAND_H
#define TONECHANGECOMMAND_H
#include"src/Common/BaseCommand.h"
#include <QFileDialog>
#include <QFileInfo>
class ViewModel;

class ToneChangeCommand:public BaseCommand
{
public:
    virtual void exec()
    {
        pViewModel->changeTone(params.path[0],params.tone);
    }
};
#endif // TONECHANGECOMMAND_H
