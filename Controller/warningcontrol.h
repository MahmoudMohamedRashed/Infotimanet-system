#ifndef WARNINGCONTROL_H
#define WARNINGCONTROL_H

#include <iostream>

class warningControl
{
public:
    warningControl();

    static void updateWarnings(std::string_view warnings) ;
    static auto newWarning() -> bool;
    static void warningOn() ;
    static void warningOff() ;
};

#endif // WARNINGCONTROL_H
