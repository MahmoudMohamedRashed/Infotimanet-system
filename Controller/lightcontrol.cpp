#include "lightcontrol.h"

lightControl::lightControl() = default;

auto lightControl ::lightToggle() -> lightState{
    return lightModel::lightToggle() ;
}
