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
    pinMode(irSensorPin, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    Serial.begin(9600);
}
