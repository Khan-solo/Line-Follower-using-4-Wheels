#include<AFMotor.h>

AF_DCMotor front_left(1);
AF_DCMotor front_right(4);
AF_DCMotor back_left(2);
AF_DCMotor back_right(3);
void setup() {
  // put your setup code here, to run once:

  front_left.setSpeed(200);
  front_right.setSpeed(200);
  back_left.setSpeed(200);
  back_right.setSpeed(200);
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A4, INPUT);
}

void loop() {
  Serial.print("Left IRSensorip");
  Serial.println(digitalRead(A0));

  if ((digitalRead(A0) == 0) && (digitalRead(A4) == 0)){
    front_left.run(FORWARD);
    front_right.run(FORWARD);
    back_left.run(FORWARD);
    back_right.run(FORWARD);
  }
  else if ((digitalRead(A0) == 1) && (digitalRead(A4) == 0)){
    front_left.run(BACKWARD);
    front_right.run(FORWARD);
    back_left.run(BACKWARD);
    back_right.run(FORWARD);
    
  }
  else if ((digitalRead(A0) == 0) && (digitalRead(A4) == 1)){
    front_left.run(FORWARD);
    front_right.run(BACKWARD);
    back_left.run(FORWARD);
    back_right.run(BACKWARD);
   }
  else  {
    front_left.run(RELEASE);
    front_right.run(RELEASE);
    back_left.run(RELEASE);
    back_right.run(RELEASE);
   }
}
