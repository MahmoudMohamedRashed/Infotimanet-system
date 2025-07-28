#include "seatbeltcontrol.h"

seatBeltControl::seatBeltControl() = default;


void seatBeltControl::lock(){
    beltModel::setBeltState(beltState::BELTLOCKED) ;
}

void seatBeltControl::unLock(){
    beltModel::setBeltState(beltState::BELTUNLOCKED) ;
}

auto seatBeltControl::isLock() -> beltState{
    return beltModel::getBeltState() ;
}
