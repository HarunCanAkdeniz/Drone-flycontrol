#define INTERRUPT_PIN 2
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
MPU6050 mpu;

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint8_t fifoBuffer[64]; // FIFO storage buffer

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
  mpuInterrupt = true;
}

void MPU6050_BASLAT() {
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
  Wire.setClock(400000);
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);

  devStatus = mpu.dmpInitialize();

  mpu.setXAccelOffset(-5518);
  mpu.setYAccelOffset(-681);
  mpu.setZAccelOffset(1058);    ///-5518,    -681,    1058,    -477,     -44,     -37
  mpu.setXGyroOffset(-477);
  mpu.setYGyroOffset(-44);
  mpu.setZGyroOffset(-37);

  if (devStatus == 0) {
    mpu.setDMPEnabled(true);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;
    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    Serial.print(F("DMP Initialization failed (code "));
  }
}
double lasttime=0;
struct Mpu6050 Yaz_MPU6050(){
  struct Mpu6050 o;
  o.YeniVeri=false;
  if (!dmpReady) 
    return o;

    
 
  double zaman = millis();
  double delta_time = zaman - lasttime;
  
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) {
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);

    
    o.Yaw = ypr[0] * 180 / M_PI;
    o.Pitch = ypr[2] * 180 / M_PI;
    o.Roll = ypr[1] * 180 / M_PI;
    o.Error = false;
    o.YeniVeri = true;
    o.Deltatime = delta_time;
    
    if (lasttime == 0){
      lasttime = zaman;
      o.Error = true;
      return o;
   }
      lasttime = zaman;
   }
  
      if(delta_time > 200){
      o.Error = true;  }
      else{
      o.Error = false;
    }
     
  return o;
  }
