#ifndef FANCONTROL_H
#define FANCONTROL_H

#include "./Model/model.h"

class fanControl
{
public:
    fanControl();

    static int getFanSpeed() ;
    static void setFanSpeed(const int speed) ;
    static fanDirState getFanDirection() ;
    static void setFanDirection(const fanDirState state) ;
};

#endif // FANCONTROL_H
