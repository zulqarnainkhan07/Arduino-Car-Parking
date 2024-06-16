# Arduino Car Parking System

## Overview
This project implements a simple car parking system using Arduino, IR sensors, a servo motor, and an LCD display. It monitors the availability of parking slots and controls access using the servo motor.

## Components Used
- Arduino Uno
- 2x IR Sensors
- Servo Motor
- LCD Display (16x2 characters) with I2C module

## Libraries Used
- Wire.h (for I2C communication with the LCD)
- LiquidCrystal_I2C.h (for controlling the LCD)

## Hardware Setup
1. **Arduino Connections**:
   - Connect IR Sensor 1 to Digital Pin 4.
   - Connect IR Sensor 2 to Digital Pin 6.
   - Connect Servo Motor to Digital Pin 9.
   - Connect SDA pin of the I2C LCD Display to A4 on Arduino.
   - Connect SCL pin of the I2C LCD Display to A5 on Arduino.

2. **Power Supply**:
   - Power the Arduino board using a USB cable connected to your computer or an external power supply.

3. **Assembly**:
   - Mount IR sensors in a position where they can detect incoming and outgoing cars.
   - Attach the servo motor to control the parking barrier.

## Software Setup
1. **Arduino IDE**:
   - Download and install the Arduino IDE from [arduino.cc](https://www.arduino.cc/en/software).

2. **Install Libraries**:
   - Open the Arduino IDE.
   - Navigate to **Sketch > Include Library > Manage Libraries...**.
   - In the Library Manager, search for `LiquidCrystal_I2C` by John Rickman.
   - Click **Install** to install the library.

   If you encounter an error during installation, you can manually download the library
   - Extract the downloaded ZIP file into your Arduino libraries directory (usually found in `Documents/Arduino/libraries/`).

3. **Upload Code**:
   - Open the `Arduino_Uno_file.ino` sketch provided in this repository.
   - Verify and upload the sketch to your Arduino board (select correct board and port under **Tools** menu).

## Usage
1. Upon startup, the LCD will display a welcome message.
2. IR sensors detect incoming and outgoing cars:
   - IR Sensor 1 manages incoming cars.
   - IR Sensor 2 manages outgoing cars.
3. The system dynamically updates the number of available parking slots on the LCD.
4. When all slots are full, the LCD displays a "Parking Full" message.
5. The servo motor controls the barrier to allow or deny access based on slot availability.

## Troubleshooting
- If you encounter issues with the LCD display or servo motor, ensure all connections are secure and configured correctly.
- Check the Arduino IDE serial monitor for debugging messages if needed.

## Credits
- Developed by Zulqarnain Ahmed

## Connect with me
- Feel free to reach out to me through my social media platforms on LinkedIn.
[LinkedIn Account](https://www.linkedin.com/in/zulqarnain-ahmed07/)

## License
This project is licensed under the MIT License - see the LICENSE file for details.
