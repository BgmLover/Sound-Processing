#ifndef OBSERVER
#define OBSERVER
#include "Params.h"
#include"src/Common/Notify.h"
class Observer
{
public:
    virtual void update(Notify noti)=0;
};

#endif
