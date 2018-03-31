#include <AFMotor.h>

AF_DCMotor motor1(1); // Rear motor currently
AF_DCMotor motor2(2);//, MOTOR12_64KHZ); Front motor
int counter = 2;
int irDistSensorPin = A0;
int onTable = HIGH; // HIGH means it sees the edge of the table

void setup() {
  //motor1.setSpeed(195); 
  //motor2.setSpeed (255);
  motor1.setSpeed(110); 
  motor2.setSpeed (90);
  pinMode(irDistSensorPin, INPUT);
}

void loop() {
  onTable = digitalRead(irDistSensorPin);
  if((counter > 0) && (onTable == HIGH)){
    driveBackward();
    delay(500);
    turnRight180();
    driveForward();
    counter--;
  }else if((counter > 0) && (onTable == LOW)){
    driveForward();  
  }else{
    stopMotors();  
  }   
}

void driveForward(){
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
}

void driveBackward(){
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
}

void turnRight90(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(369);  
}

void turnRight180(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(900);  
}

void stopMotors(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
