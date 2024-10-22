#include <Servo.h>

Servo ESC;


void setup() {
  // put your setup code here, to run once:
  ESC.attach(9,1000,2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  ESC.write(70);

}
