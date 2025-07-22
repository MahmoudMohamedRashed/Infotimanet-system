#ifndef SIGNALLIGHTCONTROL_H
#define SIGNALLIGHTCONTROL_H

#include "./Model/model.h"

class signalLightControl
{
public:
    signalLightControl();

    static signalState leftArrowClicked() ;
    static signalState rightArrowClicked();
    static signalState hazardClicked() ;
};

#endif // SIGNALLIGHTCONTROL_H
