#ifndef SIGNALLIGHTCONTROL_H
#define SIGNALLIGHTCONTROL_H

#include "./Model/model.h"

class signalLightControl
{
public:
    signalLightControl();

    static auto leftArrowClicked() -> signalState;
    static auto rightArrowClicked() -> signalState;
    static auto hazardClicked() -> signalState;
};

#endif // SIGNALLIGHTCONTROL_H
