#include<Servo.h>

Servo s;
int angle = 10;

void setup() {
  s.attach(8);
  s.write(angle);

}

void loop() {
  for(angle=10 ; angle<180 ; angle++)
  {
      s.write(angle);
      delay(50);
  }
  for(angle=180 ; angle>10 ; angle--)
  {
      s.write(angle);
      delay(50);
  }

}
