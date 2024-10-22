#include <Servo.h>

Servo ESC;

void setup() {
    Serial.begin(9600);
    Serial.println("Start ...");
    Serial1.begin(9600);
    ESC.attach(9,1000,2000);
}

void loop() {
    while(Serial1.available()>0) {
        int value = Serial1.read();

//        if (value > 127){
//          value = value - 255;
//        }
        Serial.println(value);
        
        ESC.write(30);
    }
}

//void send_motor_command(char *command){
//    Serial.print("Send command : ");
//    Serial.println(command);
//    Serial1.println(command);
//    delay(1000);
//    while (Serial1.available()) {
//        delay(5); //delay to allow buffer to fill
//        if (Serial1.available() >0) {
//            char c = Serial1.read(); //gets one byte from serial buffer
//            Serial.print(c); //makes the string readString
//        }
//    }
//}
