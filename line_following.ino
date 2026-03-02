// Arduino Line Following Robot
#define LEFT_SENSOR A0
#define RIGHT_SENSOR A1
#define MOTOR_LEFT 9
#define MOTOR_RIGHT 10

void setup() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);
  pinMode(MOTOR_LEFT, OUTPUT);
  pinMode(MOTOR_RIGHT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int left = analogRead(LEFT_SENSOR);   // Read left sensor
  int right = analogRead(RIGHT_SENSOR); // Read right sensor

  // Debug prints
  Serial.print("Left: "); Serial.print(left);
  Serial.print(" | Right: "); Serial.println(right);

  // Both sensors on line
  if (left < 500 && right < 500) {
    analogWrite(MOTOR_LEFT, 200);
    analogWrite(MOTOR_RIGHT, 200);
  } 
  // Only left sensor on line → turn left
  else if (left < 500) {
    analogWrite(MOTOR_LEFT, 100);
    analogWrite(MOTOR_RIGHT, 200);
  } 
  // Only right sensor on line → turn right
  else if (right < 500) {
    analogWrite(MOTOR_LEFT, 200);
    analogWrite(MOTOR_RIGHT, 100);
  } 
  // Both sensors off line → stop
  else {
    analogWrite(MOTOR_LEFT, 0);
    analogWrite(MOTOR_RIGHT, 0);
  }

  delay(50); // Small delay for stability
}

