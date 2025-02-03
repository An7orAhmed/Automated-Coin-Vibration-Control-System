# Automated Coin Vibration Control System

## Description  
This project implements a vibration control system using ultrasonic sensors to detect proximity and trigger coin-sized vibration modules. Designed for Arduino-compatible boards, it dynamically adjusts activation thresholds for two independent channels based on analog input values. The system reads distance data from HC-SR04 ultrasonic sensors (via the NewPing library) and controls vibration motors when objects exceed user-defined range limits.

## Features
- Dual-channel ultrasonic ranging (0-100cm range)
- Analog threshold configuration via potentiometers
- Real-time distance monitoring through serial output
- Independent control of vibration modules
- Customizable detection ranges through ADC mapping

## Hardware Pin Configuration  
| Component       | Pin  | Function               |
|-----------------|------|------------------------|
| Vibration Motor 1 | D2   | Digital output control |
| Vibration Motor 2 | D3   | Digital output control |
| Sensor 1 Trigger | D4   | HC-SR04 trigger        |
| Sensor 1 Echo    | D5   | HC-SR04 echo           |
| Sensor 2 Trigger | D6   | HC-SR04 trigger        |
| Sensor 2 Echo    | D7   | HC-SR04 echo           |
| Threshold Pot 1  | A0   | Analog input           |
| Threshold Pot 2  | A1   | Analog input           |

*Note: Physical implementation may require circuit diagram adjustments. Verify connections before powering.*

## Dependencies
- Arduino IDE 1.8.x or newer
- NewPing Library (v1.9.1+)
- HC-SR04 Ultrasonic Sensors
- 5V Vibration Motors
- 10kΩ Potentiometers (for threshold adjustment)

## Setup & Usage
1. Connect hardware as per pin configuration
2. Install NewPing library through Arduino Library Manager
3. Upload `Coin_sonar.ino` to Arduino board
4. Monitor serial output at 9600 baud for real-time data
5. Adjust potentiometers to set activation thresholds:
   - Full CCW: 0cm activation range
   - Full CW: 100cm activation range

## Operation
- System polls both sensors alternately at 500ms intervals
- Vibration motors activate when measured distance exceeds threshold
- Threshold values are mapped from analog inputs (0-1023) to 0-100cm range
- Serial monitor displays real-time configuration and measurements:
  ```
  Sonar 1 set dis: 45
  Ping 1: 32cm
  
  Sonar 2 set dis: 68
  Ping 2: 72cm
  ```

## Included Files
- `Coin_sonar.ino`: Main control firmware
- Ultrasonic sensor interface logic
- Analog-Digital conversion handlers
- Vibration module control routines

*Hardware diagrams are conceptual - verify connections against actual component specifications.*
