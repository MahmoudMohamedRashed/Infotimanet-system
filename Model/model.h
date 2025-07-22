#ifndef MODEL_H
#define MODEL_H


enum class doorState : char{
    DOORLOCKED, DOORUNLOCKED
};

enum class lightState : char{
    LIGHTON, LIGHTOFF
};

enum class beltState : char{
    BELTLOCKED, BELTUNLOCKED
};

enum class fanDirState : char{
    ALLOFF , FACEONLY , FEETONLY , FACEFEET
};

enum class signalState : char{
    LEFTON, LEFTOFF, RIGHTON, RIGHTOFF, HAZARDON, HAZARDOFF
};

enum class tripState : char{
    STARTTRIP, ENDTRIP
};

extern int cabinTemp ;

namespace cabinTempModel {
void setCabinTemp(const int temp) ;
int getCabinTemp() ;
}


extern doorState doorFlag ;

namespace doorLockModel {
void setDoorFlag(const doorState flag) ;
doorState getDoorFlag() ;
}

extern int fanSpeed ;
extern fanDirState fanState ;


namespace fanModel {
int getFanSpeed() ;
void setFanSpeed(const int speed) ;
fanDirState getFanDirection() ;
void setFanDirection(const fanDirState state) ;
}

extern int speedGauge ;
extern float RPMGauge ;
extern float fuelGauge ;

namespace gaugeModel {
void setSpeedGauge(const int speed) ;
int getSpeedGauge() ;

void setRPMGauge(const float rpm) ;
float getRPMGauge() ;

void setFuelGauge(const float fuel) ;
float getFuelGauge() ;
}


extern lightState lightFlag ;

namespace lightModel{
lightState lightToggle() ;
}

extern int motorTemp ;

namespace motorTempModel{
void setMotorTemp(const int temp) ;
int getMotorTemp() ;
}

extern beltState beltFlag ;

namespace beltModel{
void setBeltState(const beltState state);
beltState getBeltState();
}

extern signalState leftFlag ;
extern signalState rightFlag ;
extern signalState hazardFlag ;

namespace signalModel{
signalState leftArrowClicked() ;
signalState rightArrowClicked();
signalState hazardClicked() ;
}


extern tripState tripFlag ;
extern int avgSpeed ;
extern int maxSpeed ;
extern int fuelCons ;
extern int distance ;

namespace tripInfoModel {
tripState startEndTrip() ;

void updateData() ;

int getFuelCons() ;
int getAvgSpeed() ;
int getMaxSpeed() ;
int getDistance() ;
}


#endif // MODEL_H
