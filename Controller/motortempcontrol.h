#ifndef MOTORTEMPCONTROL_H
#define MOTORTEMPCONTROL_H

class motorTempControl
{
public:
    motorTempControl();

    static void setMotorTemp(const int temp) ;
    static int getMotorTemp() ;

};

#endif // MOTORTEMPCONTROL_H
