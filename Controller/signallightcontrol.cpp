#include "signallightcontrol.h"

signalLightControl::signalLightControl() = default;

auto signalLightControl::leftArrowClicked() -> signalState{
    return signalModel::leftArrowClicked() ;
}

auto signalLightControl::rightArrowClicked() -> signalState{
    return signalModel::rightArrowClicked() ;
}

auto signalLightControl::hazardClicked() -> signalState{
    return signalModel::hazardClicked() ;
}
