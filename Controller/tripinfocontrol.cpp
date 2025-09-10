#include "tripinfocontrol.h"

tripInfoControl::tripInfoControl() = default;

auto tripInfoControl::startEndTrip() ->tripState{
  return tripInfoModel::startEndTrip() ;
}

void tripInfoControl::updateData(){
  tripInfoModel::updateData() ;
}

auto tripInfoControl::getAvgSpeed() ->int{
  return tripInfoModel::getAvgSpeed() ;
}

auto tripInfoControl::getDistance() ->double{
  return tripInfoModel::getDistance() ;
}

auto tripInfoControl::getFuelCons() ->int{
  return tripInfoModel::getFuelCons() ;
}

auto tripInfoControl::getMaxSpeed() -> int{
  return tripInfoModel::getMaxSpeed() ;
}
