/*
  Created by Cristiano S
  Created in May 2023

  Gives inputs to a 1/2 adder
*/

unsigned int inputA = 10;
unsigned int inputB = 9;

void setup()
{
  // Pin inputs
  pinMode(inputA, OUTPUT);
  pinMode(inputB, OUTPUT);
  // Serial monitor
  Serial.begin(9600); // Start the serial monitor at 9600 baud
  Serial.println("\nStart:  ...\n");
}

void loop()
{
  // Truth table row 1
  digitalWrite(inputA, LOW);
  digitalWrite(inputB, LOW);
  Serial.println("0 + 0 = 00"); // Print to serial monitor with new line
  delay(2500);                  // Wait for 2500 milliseconds or 2.5 seconds
  // Truth table row 2
  digitalWrite(inputA, LOW);
  digitalWrite(inputB, HIGH);
  Serial.println("0 + 1 = 01");
  delay(2500);
  // Truth table row 3
  digitalWrite(inputA, HIGH);
  digitalWrite(inputB, LOW);
  Serial.println("1 + 0 = 01");
  delay(2500);
  // Truth table row 4
  digitalWrite(inputA, HIGH);
  digitalWrite(inputB, HIGH);
  Serial.println("1 + 1 = 10");
  delay(2500);

  Serial.println("\nDone\n");
}
