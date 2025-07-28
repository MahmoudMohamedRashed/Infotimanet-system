#ifndef CABINTEMPCONTROL_H
#define CABINTEMPCONTROL_H

class cabinTempControl
{
public:
    cabinTempControl();

    static auto getCabinTempControl() -> int;
    static void setCabinTempControl(int temp) ;
};

#endif // CABINTEMPCONTROL_H
