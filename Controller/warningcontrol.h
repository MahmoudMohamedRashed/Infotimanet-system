#ifndef WARNINGCONTROL_H
#define WARNINGCONTROL_H

#include <iostream>

class warningControl
{
public:
    warningControl();

    static void updateWarnings(std::string_view warnings) ;
    static auto newWarning() -> bool;
};

#endif // WARNINGCONTROL_H
