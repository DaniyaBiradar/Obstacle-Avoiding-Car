float distance;

// left motor
int leftMotorSpeedPin = 6;
int leftMotorForwardPin = 5;
int leftMotorBackwardPin = 7;

// right motor
int rightMotorSpeedPin = 3;
int rightMotorForwardPin = 2;
int rightMotorBackwardPin = 4;

//hcsro4
int trigPin = 9;    // Trigger
int echoPin = 10;    //echo
long duration;


void setup() {
    pinMode(leftMotorSpeedPin, OUTPUT);
    pinMode(leftMotorForwardPin, OUTPUT);
    pinMode(leftMotorBackwardPin, OUTPUT);
    pinMode(rightMotorSpeedPin, OUTPUT);
    pinMode(rightMotorForwardPin, OUTPUT);
    pinMode(rightMotorBackwardPin, OUTPUT);

    Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(leftMotorSpeedPin, HIGH);
  digitalWrite(rightMotorSpeedPin, HIGH);
   
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;
  Serial.println(distance);

  if (distance > -1 && distance < 200) {
    stop();
    delay(100);
    goBackward();
    delay(300);
    stop();
    delay(1000);
    
    if(random(0, 2) == 0) {
      goLeft();
    } else {
      goRight();
    }
    
    delay(500);
    stop();
    delay(700);
  } else {
    goForward();
  }


}

void goForward() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
  digitalWrite(leftMotorSpeedPin, 100);
  digitalWrite(rightMotorSpeedPin, 100);
  delay(1500);
}

void goBackward() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, HIGH);
  digitalWrite(leftMotorSpeedPin, 100);
  digitalWrite(rightMotorSpeedPin, 100);
  delay(1500);
}

void stop() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
  digitalWrite(leftMotorSpeedPin, 100);
  digitalWrite(rightMotorSpeedPin, 100);
  delay(1500);
}

void goRight() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorBackwardPin, LOW);
  digitalWrite(leftMotorSpeedPin, 100);
  digitalWrite(rightMotorSpeedPin, 100);
  delay(1500);
}

void goLeft() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorBackwardPin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorBackwardPin, LOW);
  digitalWrite(leftMotorSpeedPin, 100);
  digitalWrite(rightMotorSpeedPin, 100);
  delay(1500);
}
