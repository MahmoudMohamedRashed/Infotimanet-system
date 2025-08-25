#include "speedholdercontroller.h"
#include "../Model/model.h"

speedHolderController::speedHolderController() {}

auto speedHolderController::speedIsHold() ->bool {
  return speedHold::getSpeedHolder() ;
}

void speedHolderController::speedHolderOn(){
  speedHold::setSpeedHolder() ;
}

void speedHolderController::speedHolderOff(){
  speedHold::clearSpeedHolder() ;
}
