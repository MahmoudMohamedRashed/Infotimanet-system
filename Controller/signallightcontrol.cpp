#include "signallightcontrol.h"

signalLightControl::signalLightControl() {}

signalState signalLightControl::leftArrowClicked(){
    return signalModel::leftArrowClicked() ;
}

signalState signalLightControl::rightArrowClicked(){
    return signalModel::rightArrowClicked() ;
}

signalState signalLightControl::hazardClicked(){
    return signalModel::hazardClicked() ;
}
