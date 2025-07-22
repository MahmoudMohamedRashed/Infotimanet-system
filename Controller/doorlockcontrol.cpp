#include "doorlockcontrol.h"

void doorLockControl::lock(){
    doorLockModel::setDoorFlag(doorState::DOORLOCKED) ;
}

void doorLockControl::unLock(){
    doorLockModel::setDoorFlag(doorState::DOORUNLOCKED) ;
}

doorState doorLockControl::isLock(){
    return doorLockModel::getDoorFlag() ;
}
