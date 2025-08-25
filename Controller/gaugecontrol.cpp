#include "gaugecontrol.h"
#include "./Model/model.h"
#include <math.h>

gaugeControl::gaugeControl() = default;

void gaugeControl::setSpeedGauge(int speed){
  if(speed >= 250) {
    speed = 250 ;
  }
  else if (speed <= 0){
      speed = 0 ;
  }
  float rpm = speed ;
  while(rpm > 50) rpm -= 50 ;
  gaugeModel::setSpeedGauge(speed) ;
  gaugeModel::setRPMGauge(rpm / 10.0 + 1) ;
}

auto gaugeControl::getSpeedGauge() -> int{
    return gaugeModel::getSpeedGauge() ;
}

void gaugeControl::setFuelGauge(const float fuel){
  if(fuel <= 0){
    gaugeModel::setFuelGauge(7) ;
  }
  else{
    gaugeModel::setFuelGauge(fuel) ;
  }
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

