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
void setCabinTemp(int temp) ;
auto getCabinTemp() ->int ;
}


extern doorState doorFlag ;

namespace doorLockModel {
void setDoorFlag(doorState flag) ;
auto getDoorFlag() -> doorState ;
}

extern int fanSpeed ;
extern fanDirState fanState ;


namespace fanModel {
auto getFanSpeed() -> int ;
void setFanSpeed(int speed) ;
auto getFanDirection() -> fanDirState ;
void setFanDirection(fanDirState state) ;
}

extern int speedGauge ;
extern float RPMGauge ;
extern float fuelGauge ;

namespace gaugeModel {
void setSpeedGauge(int speed) ;
auto getSpeedGauge() -> int ;

void setRPMGauge(float rpm) ;
auto getRPMGauge() -> float ;

void setFuelGauge(float fuel) ;
auto getFuelGauge() -> float;
}


extern lightState lightFlag ;

namespace lightModel{
auto lightToggle() -> lightState ;
}

extern int motorTemp ;

namespace motorTempModel{
void setMotorTemp(int temp) ;
auto getMotorTemp() -> int ;
}

extern beltState beltFlag ;

namespace beltModel{
void setBeltState(beltState state);
auto getBeltState() -> beltState;
}

extern signalState leftFlag ;
extern signalState rightFlag ;
extern signalState hazardFlag ;

namespace signalModel{
auto leftArrowClicked() -> signalState;
auto rightArrowClicked() -> signalState;
auto hazardClicked() -> signalState;
}


extern tripState tripFlag ;
extern int avgSpeed ;
extern int maxSpeed ;
extern int fuelCons ;
extern int distance ;

namespace tripInfoModel {
auto startEndTrip() -> tripState;

void updateData() ;

auto getFuelCons() -> int ;
auto getAvgSpeed() -> int ;
auto getMaxSpeed() -> int ;
auto getDistance() -> int ;
}


#endif // MODEL_H
