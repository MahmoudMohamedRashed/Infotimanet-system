#include "doorlockcontrol.h"

void doorLockControl::lock(){
    doorLockModel::setDoorFlag(doorState::DOORLOCKED) ;
}

void doorLockControl::unLock(){
    doorLockModel::setDoorFlag(doorState::DOORUNLOCKED) ;
}

auto doorLockControl::isLock()->doorState{
    return doorLockModel::getDoorFlag() ;
}
