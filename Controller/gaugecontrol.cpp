#include "gaugecontrol.h"
#include "./Model/model.h"

gaugeControl::gaugeControl() = default;

void gaugeControl::setSpeedGauge(const int speed){
    gaugeModel::setSpeedGauge(speed) ;
}

auto gaugeControl::getSpeedGauge() -> int{
    return gaugeModel::getSpeedGauge() ;
}

void gaugeControl::setFuelGauge(const float fuel){
    gaugeModel::setFuelGauge(fuel) ;
}

auto gaugeControl::getFuelGauge() -> float{
    return gaugeModel::getFuelGauge() ;
}

void gaugeControl::setRPMGauge(const float rpm){
    gaugeModel::setRPMGauge(rpm) ;
}

auto gaugeControl::getRPMGauge() -> float{
    return gaugeModel::getRPMGauge() ;
}

