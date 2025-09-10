#include "warningcontrol.h"
#include "../Model/model.h"

warningControl::warningControl() = default;

auto warningControl::newWarning() -> bool {
  return warningModel::getWarning() ;
}

void warningControl::warningOn(){
  warningModel::setWarning() ;
}

void warningControl::warningOff(){
  warningModel::clearWarning() ;
}
