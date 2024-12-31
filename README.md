# Autonomous Obstacle Avoidance Robot

Designed and built a robot that navigates autonomously by detecting and avoiding obstacles in real-time using ultrasonic sensors and an Arduino microcontroller. The project demonstrates skills in robotics, sensor integration, and embedded systems programming for dynamic path adjustment.

## Features
- Real-time obstacle detection using Ultrasonic/IR sensors.
- Automated navigation and path adjustment.
- Integration of motors and a motor driver for precise movement.

## Components Used
- **Hardware**:
  - Arduino UNO
  - Jumper Wires
  - Ultrasonic & IR Sensors
  - DC & Servo Motors
  - L298D Motor Driver
- **Software**:
  - Arduino IDE

## Project Design
1. **Theory**:
   - *Arduino UNO*: Programmable circuit board with 14 digital I/O pins, 6 analog inputs, and a USB connection. Supports Serial, I2C, and SPI communication protocols.
   - *Sensors*: Convert physical characteristics into electrical signals.
     - Ultrasonic sensor: Detects distance.
     - IR sensor: Detects obstacles.
   - *Actuators*: Convert electrical signals into physical movements.
     - DC motor & Servo motor: Enable responsive navigation.

2. **Connections**:
   - Ultrasonic/IR sensors connected to the input pins of the Arduino UNO.
   - Motors connected via the L298D motor driver.

3. **Code**:
   - The Arduino code facilitates sensor data reading and motor control. Refer to the [Code](./Code/) directory for the full implementation.

## Installation and Setup
1. Clone the repository:
   ```bash
   git clone https://github.com/aritro98/Autonomous-Obstacle-Avoidance-Robot.git
   ```
2. Open the `.ino` file in the Arduino IDE.
3. Connect the Arduino UNO to your system and upload the code.
4. Assemble the robot using the provided circuit design.

## Results
The robot successfully avoids obstacles using sensor data and adjusts its movement dynamically, showcasing its potential in robotics and automation.

## Future Work
- Integration with AI/ML for smarter navigation.
- Enhancing the design for larger-scale applications.
