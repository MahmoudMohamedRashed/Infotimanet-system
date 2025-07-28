#ifndef SEATBELTCONTROL_H
#define SEATBELTCONTROL_H

#include "./Model/model.h"

class seatBeltControl
{
public:
    seatBeltControl();

    static void lock() ;
    static void unLock() ;
    static auto isLock() -> beltState;
};

#endif // SEATBELTCONTROL_H
