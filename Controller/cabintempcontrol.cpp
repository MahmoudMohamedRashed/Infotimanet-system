#include "cabintempcontrol.h"
#include "./Model/model.h"

cabinTempControl::cabinTempControl() = default;

void cabinTempControl::setCabinTempControl(const int temp){
    cabinTempModel::setCabinTemp(temp) ;
}

auto cabinTempControl::getCabinTempControl()->int{
    return cabinTempModel::getCabinTemp() ;
}
