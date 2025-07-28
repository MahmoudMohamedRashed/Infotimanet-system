#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include "./Model/model.h"

class lightControl
{
public:
    lightControl();

    static auto lightToggle() -> lightState;

};

#endif // LIGHTCONTROL_H
