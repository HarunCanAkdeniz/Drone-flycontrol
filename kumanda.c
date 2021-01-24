




#include <FlySkyIBus.h>


void Kumanda_Baslat(){ 
  IBus.begin(Serial1);
  
}


struct Kumanda Yaz_Kumanda(){
  struct Kumanda k;
 
  
  IBus.loop();
  k.Roll = map(IBus.readChannel(0), 1000, 2000, -30, 30);
  k.Pitch = map(IBus.readChannel(1), 1000, 2000, -30, 30);
  k.Throttle =map(IBus.readChannel(2), 1000, 2000, 0, 180);
  k.Yaw = map(IBus.readChannel(3), 1000, 2000, -30, 30);
  
 
  return k;
}
