//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
int uzunluk;
void setup()
{ //initializeIMU();
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
char text[32] ;
int k=0,u=0,p=0;
void loop()
{
 // struct mpu6050 o = oku();
  
  String xekseni=(String)k;
  String yekseni=(String)u;
  String zekseni=(String)p;
  String toplamveri=xekseni+"*"+yekseni+"*"+zekseni;
  for(int i=0;i<toplamveri.length();i++){
    text[i]=toplamveri[i];
  }
  
  radio.write(&text, sizeof(text));
  
  delay(1000);
}
