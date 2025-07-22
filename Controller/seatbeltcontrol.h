#ifndef SEATBELTCONTROL_H
#define SEATBELTCONTROL_H

#include "./Model/model.h"

class seatBeltControl
{
public:
    seatBeltControl();

    static void lock() ;
    static void unLock() ;
    static beltState isLock() ;
};

#endif // SEATBELTCONTROL_H
