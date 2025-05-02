# Water Flow Meter with I2C LCD

This project is an Arduino-based water flow meter system that uses a flow sensor to measure the water flow rate and display the results on an I2C LCD. The system calculates the flow rate in liters per minute and the total volume of water passed through the sensor.

## Components Used

- **Arduino Board (Uno, Nano, etc.)**
- **Flow Sensor (e.g., YF-S201)**
- **I2C LCD Display (16x2)**
- **Wires and Breadboard**

## Circuit Diagram

- The flow sensor is connected to the Arduino pin 2 (using interrupt mode).
- The I2C LCD is connected to the I2C pins on the Arduino (SDA and SCL).

## Code Description

- The flow sensor generates pulses based on the flow of water.
- An interrupt function counts the pulses from the flow sensor.
- The flow rate is calculated in liters per minute by dividing the pulse frequency by a constant (7.5).
- The total volume is calculated by summing up the flow rate over time.
- The results (flow rate and volume) are displayed on a 16x2 I2C LCD.

## Functionality

- **Flow Rate Display:** The LCD shows the current flow rate in liters per minute (L/M).
- **Total Volume Display:** The total volume of water passed through the sensor is displayed in liters (L).
- **Serial Output:** The flow rate in liters per second is printed to the serial monitor for debugging purposes.

## Libraries Used

- **Wire:** Used for I2C communication with the LCD.
- **LiquidCrystal_I2C:** Provides functions for controlling the I2C LCD display.

## Pin Configuration

- **Flow Sensor Pin:** Pin 2 (Interrupt Pin)
- **I2C LCD:** Connected to the default SDA and SCL pins on the Arduino.

## Installation

1. Clone this repository to your local machine.
2. Open the `Water_Flow_Meter.ino` file in the Arduino IDE.
3. Connect the components as per the circuit diagram.
4. Upload the code to your Arduino board.
5. Open the Serial Monitor to view the flow rate in liters per second.
