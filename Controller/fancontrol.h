#ifndef FANCONTROL_H
#define FANCONTROL_H

#include "./Model/model.h"

class fanControl
{
public:
    fanControl();

    static auto getFanSpeed() -> int;
    static void setFanSpeed(int speed) ;
    static auto getFanDirection() -> fanDirState;
    static void setFanDirection(fanDirState state) ;
};

#endif // FANCONTROL_H
