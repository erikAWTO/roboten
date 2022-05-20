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
}

void loop() {
  forward(3000,200);
  turnRight(500,100);
  backward(2000,100);
  turnLeft(500,100);
  
  delay(1000);
  sweepRightServo();
  delay(1000);
  sweepLeftServo();
}

void forward(int ms, int spd)
{
  delay(500);
  analogWrite(9, spd);
  analogWrite(10, spd);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(ms);
  stopCar(500);
}

void backward(int ms, int spd)
{
  delay(500);
  analogWrite(9, spd);
  analogWrite(10, spd);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(ms);
  stopCar(500);
}

void turnLeft(int ms, int spd)
{
  delay(500);
  analogWrite(9, spd);
  analogWrite(10, spd);
  
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  delay(ms);
  stopCar(500);
  
}

void turnRight(int ms, int spd)
{
  delay(500);
  analogWrite(9, spd);
  analogWrite(10, spd);
  
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

void sweepRightServo()
{
  for (int pos = 0; pos <= 1500; pos += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightArm.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 1500; pos >= 0; pos -= 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    rightArm.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void sweepLeftServo()
{
  for (int pos = 0; pos <= 1500; pos += 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftArm.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (int pos = 1500; pos >= 0; pos -= 10) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    leftArm.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
