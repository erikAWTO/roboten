#include <ServoTimer2.h>

ServoTimer2 rightArm;
ServoTimer2 leftArm;

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int pos = 0;

void setup() {
  // put your setup code here, to run once:
  rightArm.attach(6);
  leftArm.attach(11);
  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);

  setSpeedLeft(108);
  setSpeedRight(100);
}

void loop() {
  delay(1000);
  
  forward(2000);
  turnRight(750);
  backward(1000);
  turnLeft(750);
  
  //leftArm.write(2000);
}

void forward(int ms)
{
  delay(500);
  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(ms);
  stopCar(500);
}

void backward(int ms)
{
  delay(500);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(ms);
  stopCar(500);
}

void turnLeft(int ms)
{
  delay(500);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  delay(ms);
  stopCar(500);
  
}

void turnRight(int ms)
{
  delay(500);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  delay(ms);
  stopCar(500);
  
}

void stopCar(int ms)
{
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

  delay(ms);
}

void setSpeedLeft(int spd)
{
   analogWrite(10, spd);
}

void setSpeedRight(int spd)
{
    analogWrite(9, spd);
}
