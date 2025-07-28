#include "fancontrol.h"

fanControl::fanControl() = default;

void fanControl::setFanSpeed(const int speed){
    fanModel::setFanSpeed(speed) ;
}

auto fanControl::getFanSpeed() -> int{
    return fanModel::getFanSpeed() ;
}

void fanControl::setFanDirection(const fanDirState state){
    fanModel::setFanDirection(state) ;
}

auto fanControl::getFanDirection() -> fanDirState{
    return fanModel::getFanDirection() ;
}
