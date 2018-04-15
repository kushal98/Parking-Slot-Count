#define trigPin1 3
#define echoPin1 2
#define trigPin2 4
#define echoPin2 5
#define trigPin3 7
#define echoPin3 8

#define BLYNK_PRINT SwSerial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleStream.h>

char auth[] = "c05a4ba70926468c95a412b8f170bafe";

BlynkTimer timer;

WidgetLED led1(V1);
WidgetLED led2(V2);
 
long duration, distance, RightSensor,BackSensor,FrontSensor,LeftSensor;
 
void setup()
{
  SwSerial.begin(9600);
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);


Blynk.begin(Serial, auth);
timer.setInterval(1000L,Test);

}
 
void loop() {

Blynk.run();
timer.run();

}
 

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
 
}

void Test(){

SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;
SonarSensor(trigPin3, echoPin3);
FrontSensor = distance;
 

Serial.print("FrontSensor");
Serial.println(FrontSensor);
if(FrontSensor >=30){
  led1.on();
}
else if(FrontSensor <30){
  led1.off();
}
Serial.println();
Serial.print("RightSensor");
Serial.println(RightSensor);
if(RightSensor >=30){
  led2.on();
}
else if(RightSensor <30){
  led2.off();
}

}




