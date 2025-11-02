<h1 align="center">Distance-Based Alarm System with Turn Signal Indicators</h1>

<h3 align="center">This Arduino-based project uses an ultrasonic sensor to measure the distance to an object. If the object is too close (below a set threshold), an alarm is triggered. The system also includes left and right turn signal indicators, which are activated by switches.</h3>

# Features

- Distance Measurement: Uses an ultrasonic sensor to calculate the distance to nearby objects in centimeters.
- Turn Signal Indicators: Simulates right and left turn signal indicators using LEDs.
- Distance-Based Alarm: Triggers an alarm when the distance to an object is below a certain threshold (150 cm by default).
- Switch Control: Left and right switches are used to activate the corresponding turn signal indicators.

# Components Needed

- Arduino UNO: A microcontroller board that controls the entire system.
- Ultrasonic Sensor (HC-SR04):
  - Trig Pin → Pin 12 on Arduino
  - Echo Pin → Pin 11 on Arduino
  - VCC → 5V
  - GND → GND
- Buzzer (for alarm):
  - Positive Pin → Pin 13 on Arduino
  - Negative Pin → GND

- LEDs (for turn signal indicators):
  - Right Turn Signal → Pin 3 on Arduino
  - Left Turn Signal → Pin 4 on Arduino

- Switches:
  - Left Switch → Pin 6 on Arduino
  - Right Switch → Pin 7 on Arduino

- Resistors: To limit current to LEDs (1kΩ).
- Breadboard: For easy prototyping and connections.


# Component Connections:

<p align="center">
  <img src="https://pomf2.lain.la/f/n528u8lj.png" width="500"><br>
  Made with <a href="https://wokwi.com" target="_blank">Wokwi</a><br>
</p>

# Overview:

- Distance Measurement: The code uses an ultrasonic sensor to measure the distance to an object. It sends a pulse and calculates the time it takes for the pulse to return, which is then used to compute the distance in centimeters.
  
- Turn Signal Simulation: The left and right switches control the corresponding LEDs, simulating a turn signal indicator. The LEDs blink when a switch is pressed, mimicking the action of a turn signal.
  
- Distance Alarm: If an object is too close (e.g., below 150 cm or whatever you define), a buzzer is activated as an alarm, around 2.5kHz and 5kHz, which is intentionally irritating, enough to wake someone up.

# Functions:

- getDistance(): Measures the distance using the ultrasonic sensor.
- handleTurnSignals(): Handles the turn signal logic based on switch input (left or right).
- triggerAlarm(): Triggers the alarm by activating the buzzer when the distance threshold is crossed.
