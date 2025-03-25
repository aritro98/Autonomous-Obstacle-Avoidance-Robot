#include <Servo.h> // Include the Servo library as it is required for servo motor control
// Define the pins for the ultrasonic sensor, IR sensors, motor driver, and servo motor
#define trigPin 4
#define echoPin 5
#define irSensorPin1 A0
#define irSensorPin2 A1
#define motorPin1 9
#define motorPin2 10
#define motorPin3 11
#define motorPin4 12
#define servoPin 6
// Create an instance of the Servo class to control the servo motor
Servo myServo;
// Declare global variables to store ultrasonic sensor readings
long duration;
int distance;

void setup(){
    // Initialize the pins for input and output
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(irSensorPin1, INPUT);
    pinMode(irSensorPin2, INPUT);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    myServo.attach(servoPin); // Attach the servo to its pin
    Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop(){
    // Measure distance using ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Calculate the distance based on the duration of the pulse
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    // Print the distance to the serial monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    // Read the values from the IR sensors
    int irValue1 = analogRead(irSensorPin1);
    int irValue2 = analogRead(irSensorPin2);
    // Check for obstacles and adjust the robot's movement accordingly
    if (distance <= 20 || irValue1 < 500 || irValue2 < 500){
        // Stop motors if obstacle is detected or IR sensors detect an object
        stopMotors();
        delay(1000);
        // Reverse or turn based on IR sensor readings
        if (irValue1 < 500){
            turnRight(); // Turn right if the left IR sensor detects an obstacle
            delay(1000);
        }
        else if (irValue2 < 500){
            turnLeft(); // Turn left if the right IR sensor detects an obstacle
            delay(1000);
        } 
        else{
            reverse(); // Reverse if both sensors detect obstacles
            delay(1000);
        }
    } 
    else{
        moveForward(); // Move forward if no obstacles are detected
    }
}
// Function to move forward
void moveForward(){
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 255);
    analogWrite(motorPin3, 255);
    analogWrite(motorPin4, 255);
}
// Function to stop all motors
void stopMotors(){
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
}
// Function to turn right
void turnRight(){
    analogWrite(motorPin1, 255);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 255);
}
// Function to turn left
void turnLeft(){
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 255);
    analogWrite(motorPin3, 255);
    analogWrite(motorPin4, 0);
}
// Function to reverse
void reverse(){
    analogWrite(motorPin1, -255);
    analogWrite(motorPin2, -255);
    analogWrite(motorPin3, -255);
    analogWrite(motorPin4, -255);
}
