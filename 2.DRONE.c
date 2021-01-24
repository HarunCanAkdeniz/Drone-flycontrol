


#include <Servo.h>
Servo SolOnmotor,SagOnmotor,SolArkamotor,SagArkamotor;


double KI_RP= 0;
double KP_RP= 1;
double KD_RP =0;

struct Kumanda {
  int Yaw;
  int Roll;
  int Pitch;
  int Throttle;
  
};

struct Mpu6050 {
  double Yaw;
  double Pitch;
  double Roll;
  bool Error;
  bool YeniVeri;
  double Deltatime;
};

struct Motor{
int  SolOnMotorPower;
int  SagOnMotorPower;
int  SolArkaMotorPower;
int  SagArkaMotorPower;
};
