#include "model.h"

int cabinTemp {} ;

void cabinTempModel::setCabinTemp(const int temp){
    cabinTemp = temp ;
}

auto cabinTempModel::getCabinTemp() ->int {
    return cabinTemp ;
}


doorState doorFlag {doorState::DOORLOCKED} ;

void doorLockModel::setDoorFlag(const doorState flag){
    doorFlag = flag ;
}

auto doorLockModel::getDoorFlag() -> doorState{
    return doorFlag ;
}


int fanSpeed {} ;
fanDirState fanState {fanDirState::ALLOFF} ;

void fanModel::setFanSpeed(const int speed){
    fanSpeed = speed ;
}

auto fanModel::getFanSpeed() ->int {
    return fanSpeed ;
}

void fanModel::setFanDirection(const fanDirState state){
    fanState = state ;
}

auto fanModel::getFanDirection() -> fanDirState{
    return fanState ;
}


int speedGauge{} ;
float RPMGauge{} ;
float fuelGauge{} ;

void gaugeModel::setSpeedGauge(const int speed){
    speedGauge = speed ;
}

void gaugeModel::setRPMGauge(const float rpm){
    RPMGauge = rpm ;
}

void gaugeModel::setFuelGauge(const float fuel){
    fuelGauge = fuel ;
}

auto gaugeModel::getSpeedGauge() -> int{
    return speedGauge ;
}

auto gaugeModel::getRPMGauge() -> float{
    return RPMGauge ;
}

auto gaugeModel::getFuelGauge() -> float{
    return fuelGauge ;
}


lightState lightFlag {lightState::LIGHTOFF} ;

auto lightModel::lightToggle() -> lightState {
    lightFlag = lightFlag == lightState::LIGHTOFF ? lightState::LIGHTON : lightState::LIGHTOFF ;
    return lightFlag;
}


int motorTemp {} ;

void motorTempModel::setMotorTemp(const int temp){
    motorTemp = temp;
}

auto motorTempModel::getMotorTemp() -> int{
    return motorTemp;
}


beltState beltFlag{beltState::BELTUNLOCKED};

void beltModel::setBeltState(const beltState state){
    beltFlag = state;
}

auto beltModel::getBeltState() -> beltState{
    return beltFlag;
}


signalState leftFlag {signalState::LEFTOFF};
signalState rightFlag {signalState::RIGHTOFF};
signalState hazardFlag{signalState::HAZARDOFF};

auto signalModel::leftArrowClicked() -> signalState{
    hazardFlag = signalState::HAZARDOFF ;
    rightFlag = signalState::RIGHTOFF ;
    leftFlag = leftFlag == signalState::LEFTOFF ? signalState::LEFTON : signalState::LEFTOFF;
    return leftFlag;
}

auto signalModel::rightArrowClicked() -> signalState{
    hazardFlag = signalState::HAZARDOFF ;
    leftFlag = signalState::LEFTOFF ;
    rightFlag = rightFlag == signalState::RIGHTOFF ? signalState::RIGHTON : signalState::RIGHTOFF;
    return rightFlag;
}

auto signalModel::hazardClicked() -> signalState{
    leftFlag = signalState::LEFTOFF ;
    rightFlag = signalState::RIGHTOFF ;
    hazardFlag = hazardFlag == signalState::HAZARDOFF ? signalState::HAZARDON : signalState::HAZARDOFF;
    return hazardFlag;
}


tripState tripFlag {tripState::ENDTRIP} ;
int avgSpeed {} ;
int maxSpeed {} ;
int fuelCons {} ;
int distance {} ;

auto tripInfoModel::startEndTrip() -> tripState{
    if(tripFlag == tripState::STARTTRIP){
        tripFlag = tripState::ENDTRIP ;
        /***************************************/
    }
    else{
        tripFlag = tripState::STARTTRIP ;
        avgSpeed = 0 ;
        maxSpeed = 0 ;
        distance = 0 ;
        fuelCons = 0 ;
    }
    return tripFlag ;
}

auto tripInfoModel::getAvgSpeed() -> int{
    return avgSpeed ;
}

auto tripInfoModel::getMaxSpeed() -> int{
    return maxSpeed ;
}

auto tripInfoModel::getDistance() -> int{
    return distance ;
}

auto tripInfoModel::getFuelCons() -> int{
    return fuelCons ;
}

void tripInfoModel::updateData(){
    if(tripFlag == tripState::STARTTRIP){
        /********************************************/
    }
}
