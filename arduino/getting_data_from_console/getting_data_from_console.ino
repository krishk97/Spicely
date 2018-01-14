#include<Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

bool is_open = true;
int teaspoons = 5; 



void setup() {
  Serial.begin(9600);
  

  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(10);

  while(! Serial);
  Serial.println("Serial Ready");
}


// the loop function runs over and over again forever
void loop() {

  /* moves 90degrees clockwise
    servo1.write(50); 
    delay(210);
    servo1.write(91);
    delay(1000); */
    delay(1000);
    for (int i = 0 ; i < 10; i++) {
      
      Serial.flush();

      servo1.write(90);
      delay(300);
      servo1.write(0);
      delay(300);
    }
    
}
