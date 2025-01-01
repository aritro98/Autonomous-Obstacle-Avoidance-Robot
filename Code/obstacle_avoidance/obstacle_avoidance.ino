#define trigPin 4
#define echoPin 5
#define irSensorPin A0
#define motorPin1 9
#define motorPin2 10
long duration;
int distance;
void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  int irValue = analogRead(irSensorPin);
  if (distance <= 20 && irValue < 500){
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    delay(1000);
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);
    delay(500);
  }
  else{
    analogWrite(motorPin1, 150);
    analogWrite(motorPin2, 150);
  }
}
