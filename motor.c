


void setup() {
  Kumanda_Baslat();
  MPU6050_BASLAT();
  Motor_BASLAT();
  
}

  
void loop() {
  struct Kumanda Oku_Kumanda = Yaz_Kumanda();  
  struct Mpu6050 Oku_MPU6050 = Yaz_MPU6050();
  
  if(Oku_MPU6050.Error || Oku_Kumanda.Throttle < 10){
    Motor_DURDUR();
    Reset_PID();
    return;
  }


 if(Oku_MPU6050.YeniVeri){
  
  struct Motor motor = PID(Oku_Kumanda,Oku_MPU6050);
  Motor_DONDUR(motor);

 
  
 }
 }
