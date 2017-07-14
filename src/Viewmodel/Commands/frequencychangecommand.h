#ifndef FREQUENCYCHANGECOMMAND_H
#define FREQUENCYCHANGECOMMAND_H
#include"src/Common/BaseCommand.h"
#include <QFileDialog>
#include <QFileInfo>
class ViewModel;
class FrequencyChangeCommand:public BaseCommand
{
public:
    virtual void exec()
    {
        qDebug() << "now is in freq's exec.\n";
        qDebug() << "params.path[0]:" << params.path[0] << endl << "params.frequency:" <<params.frequency
                 << endl;
        qDebug()<<"The use of pModel in frechangCommand";

        pViewModel->changeFreq(params.path[0],params.frequency);
    }
};

#endif // FREQUENCYCHANGECOMMAND_H
