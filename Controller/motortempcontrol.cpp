#include "motortempcontrol.h"
#include "./Model/model.h"

motorTempControl::motorTempControl() {}

void motorTempControl::setMotorTemp(const int temp){
    motorTempModel::setMotorTemp(temp) ;
}

int motorTempControl::getMotorTemp(){
    return motorTempModel::getMotorTemp() ;
}
