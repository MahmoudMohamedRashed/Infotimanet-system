#include "cabintempcontrol.h"
#include "./Model/model.h"

cabinTempControl::cabinTempControl() {}

void cabinTempControl::setCabinTempControl(const int temp){
    cabinTempModel::setCabinTemp(temp) ;
}

int cabinTempControl::getCabinTempControl(){
    return cabinTempModel::getCabinTemp() ;
}
