#ifndef TRIPINFOCONTROL_H
#define TRIPINFOCONTROL_H

#include "./Model/model.h"

class tripInfoControl
{
public:
    tripInfoControl();

    static tripState startEndTrip() ;
    static void updateData() ;

    static int getFuelCons() ;
    static int getAvgSpeed() ;
    static int getMaxSpeed() ;
    static int getDistance() ;

};

#endif // TRIPINFOCONTROL_H
