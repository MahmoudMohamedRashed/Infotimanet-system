#ifndef GAUGECONTROL_H
#define GAUGECONTROL_H

class gaugeControl
{
public:
    gaugeControl();

    static void setSpeedGauge(const int speed) ;
    static int getSpeedGauge() ;

    static void setRPMGauge(const float rpm) ;
    static float getRPMGauge() ;

    static void setFuelGauge(const float fuel) ;
    static float getFuelGauge() ;
};

#endif // GAUGECONTROL_H
