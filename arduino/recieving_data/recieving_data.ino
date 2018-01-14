#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

bool is_open = true;
int teaspoons = 5; 



void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  

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
    Serial.flush(); //flush all previous received and transmitted data
    while(!Serial.available());
    
    int rotation_state = Serial.parseInt(); 
    
    servo1.write(rotation_state);
}
