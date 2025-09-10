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
    static auto hazardStatus() -> signalState ;
    static auto getHazardStatus() -> onOffHazard ;
    static void toggleHazardStatus() ;

   private:
    static void setHazardStatus() ;
};

#endif // SIGNALLIGHTCONTROL_H
