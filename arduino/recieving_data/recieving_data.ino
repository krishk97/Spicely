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

  servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(0);
}


// the loop function runs over and over again forever
void loop() {
  /* moves 90degrees clockwise
    servo1.write(50);
    delay(210);
    servo1.write(91);
    delay(1000); */

    int isAvailable = Serial.available();

    while (isAvailable) {
      int rotation_state = (int)Serial.read(); 
      Serial.write("Received\n");
      Serial.write(rotation_state);
      servo1.write(rotation_state);
      Serial.write("Sending Rotation state to nodejs\n");
      Serial.write(rotation_state);
    }
    delay(200);
    
}
