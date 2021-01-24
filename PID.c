double Roll_lasterror=0;
double Roll_kontrol;
double Roll_proportional,Roll_integral=0,Roll_derivative;
double Roll_error;

double Pitch_lasterror=0;
double Pitch_kontrol;
double Pitch_proportional,Pitch_integral=0,Pitch_derivative;
double Pitch_error;


struct Motor PID(struct Kumanda kumanda,struct Mpu6050 mpu6050){
  Roll_error = kumanda.Roll-mpu6050.Roll;
  Pitch_error = kumanda.Pitch-mpu6050.Pitch;
  
  Roll_proportional=Roll_error;
  Roll_integral+=(Roll_error)*(mpu6050.Deltatime);
  Roll_derivative=((Roll_error-Roll_lasterror)/mpu6050.Deltatime);

  Pitch_proportional=Pitch_error;
  Pitch_integral+=(Pitch_error)*(mpu6050.Deltatime);
  Pitch_derivative=((Pitch_error-Pitch_lasterror)/mpu6050.Deltatime);
  
  Roll_kontrol=(KP_RP*Roll_proportional)+(KI_RP*Roll_integral)+(KD_RP*Roll_derivative);
  Pitch_kontrol=(KP_RP*Pitch_proportional)+(KI_RP*Pitch_integral)+(KD_RP*Pitch_derivative);

  Roll_lasterror=Roll_error;
  Pitch_lasterror=Pitch_error;
  
  struct Motor motor;
  motor.SolOnMotorPower = kumanda.Throttle+Roll_kontrol+Pitch_kontrol;
  motor.SagOnMotorPower = kumanda.Throttle-Roll_kontrol+Pitch_kontrol;
  motor.SolArkaMotorPower = kumanda.Throttle+Roll_kontrol-Pitch_kontrol;
  motor.SagArkaMotorPower = kumanda.Throttle-Roll_kontrol-Pitch_kontrol;
  return motor;
}

void Reset_PID(){
  Roll_lasterror=0;
  Roll_integral=0;
  Pitch_lasterror=0;
  Pitch_integral=0;
}
