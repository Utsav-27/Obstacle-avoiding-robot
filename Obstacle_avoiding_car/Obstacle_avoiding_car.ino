#include <NewPing.h>
#include<Servo.h>
Servo a;
int angle = 0;

#define TRIG_PIN A0 
#define ECHO_PIN A1 
#define MAX_DISTANCE 200 
int m1=5;
int m2=6;
int m3=7;
int m4=8;
int en1=3;
int en2=5;

int distance = 100;
int setspeed = 0;
int readPing();



NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  a.attach(9);
  a.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);

}
void moveStop()
{
  analogWrite(en1, 127);
 analogWrite(en2, 127);
 digitalWrite(m1, LOW);
 digitalWrite(m2, LOW);       
 digitalWrite(m3, LOW);
 digitalWrite(m4, LOW);
}

void moveForward()
{
  analogWrite(en1, 127);
  analogWrite(en2, 127);
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);       
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
  
}
void moveBackward()
{
  analogWrite(en1, 90);
 analogWrite(en2, 90);
 digitalWrite(m1, LOW);
 digitalWrite(m2, HIGH);      
 digitalWrite(m3, LOW);
 digitalWrite(m4, HIGH);

 
}

void turnRight()
{
analogWrite(en1, 127);
 analogWrite(en2, 127);
 digitalWrite(m1, LOW);
 digitalWrite(m2, LOW);       
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
 delay(500);
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);
}

void turnLeft()
{
  analogWrite(en1, 127);
 analogWrite(en2, 127);
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);       
 digitalWrite(m3, LOW);
 digitalWrite(m4, LOW);
 delay(500);
 digitalWrite(m1, HIGH);
 digitalWrite(m2, LOW);
 digitalWrite(m3, HIGH);
 digitalWrite(m4, LOW);


}
void loop() {
  // put your main code here, to run repeatedly:
int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=15)
 {
   moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);
 }

  if(distanceR>=distanceL)
  {
    turnRight();
    moveStop();
  }
  else if(distanceR<distanceL)
  {
    turnLeft();
    moveStop();
  }
  else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    a.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    a.write(115); 
    return distance;
}

int lookLeft()
{
    a.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    a.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}
