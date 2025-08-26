#include "signallightcontrol.h"

signalLightControl::signalLightControl() = default;

auto signalLightControl::leftArrowClicked() -> signalState{
    return signalModel::leftArrowClicked() ;
}

auto signalLightControl::rightArrowClicked() -> signalState{
    return signalModel::rightArrowClicked() ;
}

auto signalLightControl::hazardClicked() -> signalState{
  signalLightControl::setHazardStatus() ;
    return signalModel::hazardClicked() ;
}

auto signalLightControl::getHazardStatus() -> onOffHazard{
  return signalModel::getHazardStatus() ;
}

void signalLightControl::toggleHazardStatus(){
  signalModel::toggleHazardStatus() ;
}

void signalLightControl::setHazardStatus(){
  signalModel::setHazardStatus() ;
}

auto signalLightControl::hazardStatus() ->signalState{
  return signalModel::hazardStatus() ;
}
