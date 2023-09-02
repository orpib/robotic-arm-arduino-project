#include <Servo.h>
Servo servo;
int servoPin = 9;
void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1500);
  servo.write(0);
  delay(2000);

  //positionTest();
}

void positionTest() {
  for (int i = 0; i <= 180; i += 1) {
    servo.write(i);
    delay(15);
  }

  for (int i = 180; i > 0; i -= 1) {
    servo.write(i);
    delay(15);
  }
}
