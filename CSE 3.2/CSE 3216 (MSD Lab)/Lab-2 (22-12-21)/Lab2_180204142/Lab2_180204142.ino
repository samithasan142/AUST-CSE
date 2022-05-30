#include<Keypad.h>
const byte r = 4;
const byte c = 4;
int buzzer = 10;
int a=0,b=0,flag=0;
char sign='n';

char keys[r][c] ={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowpins [r] = {2,3,4,5};
byte colpins [c] = {6,7,8,9};
Keypad kpd = Keypad(makeKeymap(keys),rowpins,colpins,r,c);

void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  char key = kpd.getKey();
  if(key == 'C')
  {
    tone(buzzer,1000);
    delay(1000);
  }
  if(key == 'D')
  {
    noTone(buzzer);
    delay(1000);
  }
  else if(key >= '0' && key<='9' && flag==0)
  {
   a= key - '0';
   Serial.println(key);
   flag =1;
  }
  else if(key >= '0' && key<='9' && flag==1)
  {
    b= key - '0';
    Serial.println(key);
    flag =0;
  }
  if(key=='A' || key=='B')
  {
    sign = key;
    if(key=='A')
    Serial.println("*");
    else
    Serial.println("/");


    //Serial.println(key);
  }
  if(key=='#')
  {
    flag=0;
    if(sign == 'A')
    Serial.println(a*b);
    /*else{
      if(b!=0)
      Serial.println(a/b);
      else
      Serial.println("B is zero");
    }*/
    if(sign == 'B' && b!=0)
    Serial.println(a/b);
    if(sign == 'B' && b==0)
    Serial.println("B is zero");
  }
}
