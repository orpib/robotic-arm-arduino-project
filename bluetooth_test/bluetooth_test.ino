#include <SoftwareSerial.h>
#include <Servo.h>

int servoPin = 9;
int bluetoothTx = 10;
int bluetoothRx = 11;

Servo servo;
//SoftwareSerial bluetoothControl(bluetoothRx, bluetoothTx);  // RX, TX
String wholeData = "" ;
void setup() {
  // put your setup code here, to run once:
  //servo.attach(servoPin);
  //bluetoothControl.begin(9600);
  Serial.begin(9600);
}

void loop() {

  if(Serial.available() >= 10){

    int command = Serial.read();
    int servoPosition = command;


    if(servoPosition)


  }

 
  Serial.println("Serial");

  Serial.println(Serial.available());

  while (Serial.available() > 0) {
    char data = Serial.read();
    wholeData += data; 

    
  }

  Serial.println(wholeData);
  wholeData = "";

  Serial.println("TEST");
  // if (bluetoothControl.available() > 0) /* If data is available on serial port */
  // {
  //   Serial.write(bluetoothControl.read()); /* Print character received on to the serial monitor */
  // } else {
  //   Serial.println("Kaj hoi nai");
  delay(500);
  // }
}

bool isBaseCommand(int servoPosition){

  return servoPosition >= 40 && servoPosition < 100

}
