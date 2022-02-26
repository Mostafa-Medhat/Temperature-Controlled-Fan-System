# Temperature Control System
- [Description](#description)
- [Features](#features)
- [Schematic Capture](#Schematic-Capture)
   - [Main Components](#Main-Components)
   - [Drivers](#Drivers)
   - [Tools](#Tools)
- [Demo](#Demo)
## Description
An automatic temperature control system using ATmega16 microcontroller, in which the fan state is automatically changed (ON/OFF) and its speed changes according to the temperature.
## Features
- The project was designed and implemented based on the layered architecture model as follow:
<p align="center">
  <img src="https://github.com/Mostafa-Medhat/Temperature-Controlled-Fan-System/blob/main/docs/layered%20model.png?raw=true">
</p>

- The LM35 temperature sensor will give continuous analog output corresponding to the temperature.
- The ADC converts the analog values to digital values.
- After performing calculations, the temperature is displayed on the LCD.
- The microcontroller will continuously monitor the temperature and will drive the fan based on the temperature value.

## Schematic Capture

<p align="center">
  <img src="https://github.com/Mostafa-Medhat/Temperature-Controlled-Fan-System/blob/main/docs/Schematic.PNG?raw=true">
</p>

### Main Components
- ATmege16 
- 2*16 LCD
- LM35
- DC Motor
- L293D

### Drivers
- ADC
- PWM
- GPIO
- LCD
- LM35
- DC Motor

### Tools
- Eclipse
- Proteus

## Demo
