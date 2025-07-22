#include "gaugecontrol.h"
#include "./Model/model.h"

gaugeControl::gaugeControl() {}

void gaugeControl::setSpeedGauge(const int speed){
    gaugeModel::setSpeedGauge(speed) ;
}

int gaugeControl::getSpeedGauge(){
    return gaugeModel::getSpeedGauge() ;
}

void gaugeControl::setFuelGauge(const float fuel){
    gaugeModel::setFuelGauge(fuel) ;
}

float gaugeControl::getFuelGauge(){
    return gaugeModel::getFuelGauge() ;
}

void gaugeControl::setRPMGauge(const float rpm){
    gaugeModel::setRPMGauge(rpm) ;
}

float gaugeControl::getRPMGauge(){
    return gaugeModel::getRPMGauge() ;
}

