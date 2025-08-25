#ifndef TRIPINFOCONTROL_H
#define TRIPINFOCONTROL_H

#include "./Model/model.h"

class tripInfoControl
{
public:
    tripInfoControl();

    static auto startEndTrip() -> tripState;
    static void updateData() ;

    static auto getFuelCons() -> int;
    static auto getAvgSpeed() -> int;
    static auto getMaxSpeed() -> int;
    static auto getDistance() -> double;

};

#endif // TRIPINFOCONTROL_H
