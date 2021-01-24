
void Motor_BASLAT(){
  SolOnmotor.attach(4,1000,2000);
  SagOnmotor.attach(5,1000,2000);
  SolArkamotor.attach(6,1000,2000);
  SagArkamotor.attach(7,1000,2000);
  SolOnmotor.write(0);
  SagOnmotor.write(0);
  SolArkamotor.write(0);
  SagArkamotor.write(0);
}

void Motor_DONDUR(struct Motor motor){
  SolOnmotor.write(motor.SolOnMotorPower);
  SagOnmotor.write(motor.SagOnMotorPower);
  SolArkamotor.write(motor.SolArkaMotorPower);
  SagArkamotor.write(motor.SagArkaMotorPower);
}

void Motor_DURDUR(){
  SolOnmotor.write(0);
  SagOnmotor.write(0);
  SolArkamotor.write(0);
  SagArkamotor.write(0);
}
