# Smart Street Light System

## Overview

This project is an Arduino-based Smart Street Light System that automatically controls street lights based on ambient light and vehicle detection.

The system uses an LDR sensor to detect day and night conditions and an HC-SR04 ultrasonic sensor to detect vehicles. A 16x2 LCD displays the system status.

---

## Features

- Automatic Day/Night Detection
- Vehicle Detection using HC-SR04
- Smart Street Light Control
- 5 LED Road Simulation
- 3-Second Hold Delay after Vehicle Passes
- LCD Status Monitoring

---

## Components Used

- Arduino Uno
- LDR Module
- HC-SR04 Ultrasonic Sensor
- 16x2 LCD
- 5 LEDs
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Working Logic

### Day Mode
- All street lights OFF

### Night Mode
- End lights ON
- Middle lights OFF

### Vehicle Detected
- All lights ON

### Vehicle Leaves
- Lights remain ON for 3 seconds
- System returns to Night Mode

---

## Technologies Used

- Arduino IDE
- Embedded C/C++
- Sensor Interfacing
- LCD Interfacing
- Automation Logic

---

## Future Improvements

- Solar Power Integration
- IoT Monitoring using ESP32
- Energy Consumption Monitoring
- Wireless Control

---

## Author

Ved Kale
Electronics Engineering Student
Walchand College of Engineering, Sangli
