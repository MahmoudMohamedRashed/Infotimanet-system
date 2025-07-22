#include "model.h"

int cabinTemp {} ;

void cabinTempModel::setCabinTemp(const int temp){
    cabinTemp = temp ;
}

int cabinTempModel::getCabinTemp(){
    return cabinTemp ;
}


doorState doorFlag {doorState::DOORLOCKED} ;

void doorLockModel::setDoorFlag(const doorState flag){
    doorFlag = flag ;
}

doorState doorLockModel::getDoorFlag(){
    return doorFlag ;
}


int fanSpeed {} ;
fanDirState fanState {fanDirState::ALLOFF} ;

void fanModel::setFanSpeed(const int speed){
    fanSpeed = speed ;
}

int fanModel::getFanSpeed(){
    return fanSpeed ;
}

void fanModel::setFanDirection(const fanDirState state){
    fanState = state ;
}

fanDirState fanModel::getFanDirection(){
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

int gaugeModel::getSpeedGauge(){
    return speedGauge ;
}

float gaugeModel::getRPMGauge(){
    return RPMGauge ;
}

float gaugeModel::getFuelGauge(){
    return fuelGauge ;
}


lightState lightFlag {lightState::LIGHTOFF} ;

lightState lightModel::lightToggle(){
    lightFlag = lightFlag == lightState::LIGHTOFF ? lightState::LIGHTON : lightState::LIGHTOFF ;
    return lightFlag;
}


int motorTemp {} ;

void motorTempModel::setMotorTemp(const int temp){
    motorTemp = temp;
}

int motorTempModel::getMotorTemp(){
    return motorTemp;
}


beltState beltFlag{beltState::BELTUNLOCKED};

void beltModel::setBeltState(const beltState state){
    beltFlag = state;
}

beltState beltModel::getBeltState(){
    return beltFlag;
}


signalState leftFlag {signalState::LEFTOFF};
signalState rightFlag {signalState::RIGHTOFF};
signalState hazardFlag{signalState::HAZARDOFF};

signalState signalModel::leftArrowClicked(){
    hazardFlag = signalState::HAZARDOFF ;
    rightFlag = signalState::RIGHTOFF ;
    leftFlag = leftFlag == signalState::LEFTOFF ? signalState::LEFTON : signalState::LEFTOFF;
    return leftFlag;
}

signalState signalModel::rightArrowClicked(){
    hazardFlag = signalState::HAZARDOFF ;
    leftFlag = signalState::LEFTOFF ;
    rightFlag = rightFlag == signalState::RIGHTOFF ? signalState::RIGHTON : signalState::RIGHTOFF;
    return rightFlag;
}

signalState signalModel::hazardClicked(){
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

tripState tripInfoModel::startEndTrip(){
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

int tripInfoModel::getAvgSpeed(){
    return avgSpeed ;
}

int tripInfoModel::getMaxSpeed(){
    return maxSpeed ;
}

int tripInfoModel::getDistance(){
    return distance ;
}

int tripInfoModel::getFuelCons(){
    return fuelCons ;
}

void tripInfoModel::updateData(){
    if(tripFlag == tripState::STARTTRIP){
        /********************************************/
    }
}
