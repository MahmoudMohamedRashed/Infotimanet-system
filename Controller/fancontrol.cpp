#include "fancontrol.h"

fanControl::fanControl() {}

void fanControl::setFanSpeed(const int speed){
    fanModel::setFanSpeed(speed) ;
}

int fanControl::getFanSpeed(){
    return fanModel::getFanSpeed() ;
}

void fanControl::setFanDirection(const fanDirState state){
    fanModel::setFanDirection(state) ;
}

fanDirState fanControl::getFanDirection(){
    return fanModel::getFanDirection() ;
}
