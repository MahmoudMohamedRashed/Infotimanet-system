#include "motortempcontrol.h"
#include "./Model/model.h"

motorTempControl::motorTempControl() = default;

void motorTempControl::setMotorTemp(const int temp){
    motorTempModel::setMotorTemp(temp) ;
}

auto motorTempControl::getMotorTemp() -> int{
    return motorTempModel::getMotorTemp() ;
}
