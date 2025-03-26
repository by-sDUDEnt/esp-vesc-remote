#include <VescUart.h>

VescUart UART;

int potentiometerPin = 27; // middle pin of 10kOm potentiometer
float current = 1.0; /** The current in amps */


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(potentiometerPin, INPUT);

  /** Setup UART port (Serial1 on Atmega32u4) */
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  
  while (!Serial2) {;}

  /** Define which ports to use as UART */
  UART.setSerialPort(&Serial2);




}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  // int sensorValue = analogRead(potentiometerPin);
  // // print out the value you read:
  // Serial.println(sensorValue);
  // delay(1000);  // delay in between reads for stability
  Serial.println("dsd");
if (UART.getVescValues()) 
  {
    float voltage = UART.data.inpVoltage;
    float current = UART.data.avgInputCurrent;
    UART.setCurrent(2.5);
    delay(5000);
    UART.setCurrent(0);


    Serial.println(voltage);
    Serial.println(current);

  }
  delay(1000);
}












