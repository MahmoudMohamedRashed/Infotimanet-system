#ifndef DOORLOCKCONTROL_H
#define DOORLOCKCONTROL_H

#include "./Model/model.h"

class doorLockControl
{
public:
    doorLockControl() = default ;

    static void lock() ;
    static void unLock() ;
    static auto isLock()-> doorState;
};

#endif // DOORLOCKCONTROL_H
