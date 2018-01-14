#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

bool is_open = true;
int teaspoons = 5; 



void setup() {
  Serial.begin(9600);
  Serial.print("FOO");

  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);
}

// the loop function runs over and over again forever
void loop() {
  /* moves 90degrees clockwise
    servo1.write(50);
    delay(210);
    servo1.write(91);
    delay(1000); */

    while (is_open) {
    for (int i = 0; i < 2; i ++) {
      is_open = false;
      servo1.write(0); //Move to the zero position, can use to calibrate too
      delay(1000);
      servo1.write(90); //Move to the 180 position
      delay(1000);
      Serial.write(teaspoons);
    }
   
    }
    
    
    
//  servo1.write(0); //Move to the zero position, can use to calibrate too
//  delay(1000);
//  servo1.write(90); //Move to the 180 position
//  delay(1000);
}
