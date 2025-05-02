/*
WATER FLOW METER WITH I2C LCD
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

volatile int flow_frequency; // Measures flow sensor pulses
float vol = 0.0, l_minute;

const unsigned char flowsensor = 2; // Sensor Input
unsigned long currentTime, cloopTime;

// Initialize I2C LCD at address 0x27 with 16 columns and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void flow() // Interrupt function
{
    flow_frequency++;
}

void setup()
{
    pinMode(flowsensor, INPUT);
    digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
    Serial.begin(9600);

    lcd.init();           // Initialize the LCD
    lcd.backlight();      // Turn on backlight
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Water Flow Meter");
    lcd.setCursor(0, 1);
    lcd.print("Circuit Digest");

    attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt

    currentTime = millis();
    cloopTime = currentTime;
}

void loop()
{
    currentTime = millis();
    // Every second, calculate and print litres/hour
    if (currentTime >= (cloopTime + 1000))
    {
        cloopTime = currentTime; // Updates cloopTime
        if (flow_frequency != 0)
        {
            // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
            l_minute = (flow_frequency / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Rate: ");
            lcd.print(l_minute);
            lcd.print(" L/M");

            l_minute = l_minute / 60;
            lcd.setCursor(0, 1);
            vol = vol + l_minute;
            lcd.print("Vol: ");
            lcd.print(vol);
            lcd.print(" L");

            flow_frequency = 0; // Reset Counter
            Serial.print(l_minute, DEC); // Print litres/hour
            Serial.println(" L/Sec");
        }
        else
        {
            Serial.println(" flow rate = 0 ");
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Rate: ");
            lcd.print(flow_frequency);
            lcd.print(" L/M");
            lcd.setCursor(0, 1);
            lcd.print("Vol: ");
            lcd.print(vol);
            lcd.print(" L");
        }
    }
}
