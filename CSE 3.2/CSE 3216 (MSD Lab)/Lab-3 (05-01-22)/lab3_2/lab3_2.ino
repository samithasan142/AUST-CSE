const int sigPin = 9;
long duration;
int distance;
void setup() {
  Serial.begin(9600);
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
  
  Serial.print("Distance(cm): ");
  Serial.println(distance);
  delay(1000);
}
