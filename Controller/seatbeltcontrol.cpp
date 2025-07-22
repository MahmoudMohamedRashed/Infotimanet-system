#include "seatbeltcontrol.h"

seatBeltControl::seatBeltControl() {}


void seatBeltControl::lock(){
    beltModel::setBeltState(beltState::BELTLOCKED) ;
}

void seatBeltControl::unLock(){
    beltModel::setBeltState(beltState::BELTUNLOCKED) ;
}

beltState seatBeltControl::isLock(){
    return beltModel::getBeltState() ;
}
