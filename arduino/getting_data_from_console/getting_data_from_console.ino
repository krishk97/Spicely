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
    
    for (int spiceId = 0 ; spiceId < 4; spiceId++) {
      Serial.flush();

      String spiceIdString = String(spiceId);
      String messageId = "Please input how much spice you need for spice id: " + spiceIdString;
      while(!Serial.available()){};
      Serial.println(messageId);
      int angle = Serial.parseInt();
      servo1.write(angle);
      Serial.println("Input angle for spice id: " + spiceIdString + " is " +  String(angle));
    }
    
}
