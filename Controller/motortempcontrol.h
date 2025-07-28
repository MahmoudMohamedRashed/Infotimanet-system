#ifndef MOTORTEMPCONTROL_H
#define MOTORTEMPCONTROL_H

class motorTempControl
{
public:
    motorTempControl();

    static void setMotorTemp(int temp) ;
    static auto getMotorTemp() -> int;

};

#endif // MOTORTEMPCONTROL_H
