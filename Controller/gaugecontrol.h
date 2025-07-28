#ifndef GAUGECONTROL_H
#define GAUGECONTROL_H

class gaugeControl
{
public:
    gaugeControl();

    static void setSpeedGauge(int speed) ;
    static auto getSpeedGauge() -> int;

    static void setRPMGauge(float rpm) ;
    static auto getRPMGauge() -> float;

    static void setFuelGauge(float fuel) ;
    static auto getFuelGauge() -> float;
};

#endif // GAUGECONTROL_H
