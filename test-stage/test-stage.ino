#include <SoftwareSerial.h>
#include <Servo.h>

int basePin = 9;
int bodyPin = 10;
int clawPin = 11;

Servo baseServo, bodyServo, clawServo;

int basePos, bodyPos, clawPos;


void setup() {
  baseServo.attach(basePin);
  bodyServo.attach(bodyPin);
  clawServo.attach(clawPin);

  Serial.begin(9600);
}

void loop() {
 //Serial.println("START");
  if (Serial.available() >= 10) {

    int command = Serial.read();
    int servoPosition = command;


    if (isBaseCommand(servoPosition)) {
      int position = getMappedBasePosition(servoPosition);
      baseServo.write(position);
      Serial.print("Base Rotate -> ");
      Serial.println(position);

      delay(15);
    }

    if (isBodyCommand(servoPosition)) {
      int position = getMappedBodyPosition(servoPosition);
      bodyServo.write(position);

      Serial.print("Body Rotate -> ");
      Serial.println(position);

      delay(15);
    }

    if (isClawCommand(servoPosition)) {
      int position = getMappedClawPosition(servoPosition);
      clawServo.write(position);

      Serial.print("claw Rotate -> ");
      Serial.println(position);
      delay(15);
    }
  }
  Serial.println("Ended");
  //delay(1000);
}

bool isBaseCommand(int servoPosition) {

  return servoPosition >= 40 && servoPosition < 100;
}

int getMappedBasePosition(int value) {
  return map(value, 40, 100, 0, 90);
}

bool isBodyCommand(int servoPosition) {
  return servoPosition >= 102 && servoPosition < 200;
}

int getMappedBodyPosition(int value) {
  return map(value, 102, 200, 0, 90);
}

bool isClawCommand(int servoPosition) {
  return servoPosition >= 202 && servoPosition < 250;
}

int getMappedClawPosition(int value) {
  return map(value, 202, 220, 0, 60);
}


void rotateServo(int pos, Servo servo) {
}
