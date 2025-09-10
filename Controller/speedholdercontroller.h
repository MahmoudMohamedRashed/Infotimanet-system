#ifndef SPEEDHOLDERCONTROLLER_H
#define SPEEDHOLDERCONTROLLER_H

class speedHolderController {
 public:
  speedHolderController();
  static auto speedIsHold() ->bool ;
  static void speedHolderOn() ;
  static void speedHolderOff() ;
};

#endif  // SPEEDHOLDERCONTROLLER_H
