#include<Servo.h>

Servo s;
int angle = 10;
const int sigPin = 9;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  s.attach(8);
  s.write(angle);

}

void loop() {
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delay(2);
  digitalWrite(sigPin, HIGH);
  delay(10);
  digitalWrite(sigPin, LOW);
  pinMode(sigPin, INPUT);
  duration = pulseIn(sigPin, HIGH);
  distance = (duration*0.034)/2;

  if(distance < 20){
    for(angle=0 ; angle<90 ; angle++)
    {
      s.write(angle);
      delay(25);
    }
  }

  else if(distance >= 20){
    for(angle=90 ; angle<180 ; angle++)
    {
      s.write(angle);
      delay(25);
    }
  }
  
  Serial.print("Distance(cm): ");
  Serial.println(distance);
  delay(1000);
}
