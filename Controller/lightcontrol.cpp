#include "lightcontrol.h"

lightControl::lightControl() {}

lightState lightControl ::lightToggle(){
    return lightModel::lightToggle() ;
}
