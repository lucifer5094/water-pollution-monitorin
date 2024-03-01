
# ARDUINO WATER QUALITY MONITORING SYSTEM:

This project is an Arduino-based water quality monitoring system that measures various parameters including pH, TDS, turbidity, water level, temperature, and humidity. The system displays the data on an LCD screen and sends it to the serial monitor for further analysis.

# FEATURES:

Measures pH, TDS, turbidity, water level, temperature, and humidity

Displays data on a 16x2 LCD screen

Sends data to the serial monitor for logging and analysis

Uses ultrasonic sensor to measure distance of objects


# HARDWARE REQUIREMENTS:


Arduino Uno or compatible board

LiquidCrystal I2C library https://github.com/johnrickman/LiquidCrystal_I2C

DHT sensor (DHT11 or DHT22)

pH sensor

TDS sensor

Turbidity sensor

Ultrasonic sensor (HC-SR04)

16x2 LCD display

Breadboard and jumper wires


# SOFTWARE REQUIREMENTS:


Arduino IDE (https://www.arduino.cc/)

LiquidCrystal_I2C library (included in the code)

DHT library (https://learn.adafruit.com/dht/downloads)


# INSTRUCTIONS:


1. Download the code and libraries.

2. Install the required libraries in the Arduino IDE.

3. Connect the hardware components according to the provided schematics (not included in this example README).

4. Upload the code to your Arduino board.

5. Open the serial monitor in the Arduino IDE to view the sensor data.

NOTE: This is a basic example and may require modifications depending on your specific hardware and sensor models. Calibration of the sensors may also be necessary for accurate readings.
