still developing -----
has some running tests in another folder

# Line Following Robot

This project is for a **Line Following Robot** controlled using two sensors to detect and follow a line. The robot uses two motors to move forward, left, or right, depending on the sensor input. If both sensors lose the line, the robot stops.

## Components
- **Microcontroller**: Arduino
- **Motors**: 2 DC motors (with motor driver)
- **Sensors**: 2 IR sensors or photoresistors
- **Motor Driver Module**: L298N or equivalent
- **Power Supply**: Suitable power for motors and Arduino
- **Chassis**: Robot frame (optional, based on design)

## Pin Configuration
- **mot1 (Pin 9)**: Left motor forward
- **mot2 (Pin 6)**: Left motor backward
- **mot3 (Pin 5)**: Right motor forward
- **mot4 (Pin 3)**: Right motor backward
- **leftSensor (Pin 13)**: Left IR sensor input
- **rightSensor (Pin 12)**: Right IR sensor input

## Functionality
- **FORWARD**: When both sensors detect the line.
- **LEFT**: When the left sensor detects the line but the right sensor does not.
- **RIGHT**: When the right sensor detects the line but the left sensor does not.
- **STOP**: When both sensors are off the line.

## How It Works
1. **FORWARD**: When both sensors detect the line, the robot moves forward.
2. **LEFT**: If the left sensor detects the line but the right sensor does not, the robot turns left.
3. **RIGHT**: If the right sensor detects the line but the left sensor does not, the robot turns right.
4. **STOP**: If both sensors do not detect the line, the robot stops.

## Circuit Diagram
- Connect the motors to the motor driver (L298N or equivalent).
- Connect the left motor to `mot1` and `mot2` (pins 9 and 6 on the Arduino).
- Connect the right motor to `mot3` and `mot4` (pins 5 and 3 on the Arduino).
- Connect the left sensor to `leftSensor` (pin 13).
- Connect the right sensor to `rightSensor` (pin 12).

## Code Explanation
The robot reads the state of two line sensors:
- If both sensors detect the line, the robot moves forward.
- If the left sensor detects the line but the right sensor does not, it turns left.
- If the right sensor detects the line but the left sensor does not, it turns right.
- If both sensors are off the line, the robot stops.

The `LEFT`, `RIGHT`, `FORWARD`, and `STOP` functions control the motors accordingly by using `analogWrite` to vary motor speed and direction.

## How to Use
1. Assemble the robot and connect the sensors and motors as described.
2. Upload the provided Arduino code (`line_follower_robot.ino`) to the microcontroller.
3. Place the robot on a surface with a line for it to follow.
4. The robot will automatically follow the line based on sensor inputs.

## License
This project is licensed under the MIT License. See the `LICENSE` file for more details.
