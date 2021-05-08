#include<Servo.h>
Servo myservo;
const int trigPin=13;
const int echoPin=12; 
int red=5;
int green=6;
long tmeduration;
int distance;

float cf = 19.5; // caliberation factor

int ffs1 = A0; // FlexiForce sensor is connected analog pin A0 of arduino or mega. 

int ffsdata = 0; 
float vout; 

void setup() {

  myservo.attach(11);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
   pinMode(ffs1, INPUT); 
  Serial.begin(9600);
  
  

}

void loop() {
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
  
tmeduration=pulseIn(echoPin,HIGH);
distance=(0.034*tmeduration)/2;

 ffsdata = analogRead(ffs1);
vout = (ffsdata * 5.0) / 1023.0; 
vout = vout * cf ; 
if((distance<=20)&& (vout<=12)) 
{
  
  myservo.write(90);
  digitalWrite(green,HIGH);
  digitalWrite(red,LOW);
  }
  else{
    myservo.write(0);
    digitalWrite(red,HIGH);
   digitalWrite(green,LOW);
    }
  
  Serial.print("distance:");
    Serial.println(distance);
  
    delay(1);
  

}
