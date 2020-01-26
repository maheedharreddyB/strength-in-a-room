#include<math.h>
int irpin = 4;
int irpinout = 6;
int ledpin = 5;
int state1,state2;
int last1 = LOW;
int last2 = LOW;
unsigned int count = 0;
int person = 5;
int temp1 = 0;
int temp2=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(irpin,INPUT);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
state1 = digitalRead(irpin);
state2 = digitalRead(irpinout);
if (state1 != last1){
    count = count+1;
    if (temp1 != ceil(count/2)){
      temp1 = ceil(count/2);
      if (temp1<=5){
      Serial.print(temp1);
      Serial.println(" person are inside the room");
      for (int i=1; i<=temp1;i++){
      analogWrite(ledpin,51*temp1);
      if (temp1>5){
        temp1 = 0;
        }
      }
      }
      else{
        Serial.println("The Room is full!!!");
        digitalWrite(ledpin,HIGH);
        }
    }
  }
  if (state2 != last2){
  count=count-1;
  if (temp2!= ceil(count/2)){
    temp2=ceil(count/2);
    if(temp2>0 && temp2<=5){
      Serial.print(temp2);
      Serial.println(" person are inside the room");
      for (int i=1; i<=temp2;i++){
      analogWrite(ledpin,51*temp2);
      if (temp2<=0){
        temp2 = 0;
      }
    }
    }
    else{
      Serial.println("The Room is empty!!!");
      digitalWrite(ledpin,LOW);
    }
  }
}
  last1 = state1;
  last2 = state2;
  delay(0);  
}
