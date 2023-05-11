/*
  Created by Cristiano S
  Created in May 2023

  Gives inputs to a 2-bit full adder
*/

unsigned int inputAOne = 11;
unsigned int inputBOne = 10;
unsigned int inputATwo = 9;
unsigned int inputBTwo = 8;

void setup()
{
  // Pin inputs
  pinMode(inputAOne, OUTPUT);
  pinMode(inputBOne, OUTPUT);
  pinMode(inputATwo, OUTPUT);
  pinMode(inputBTwo, OUTPUT);
  // Serial monitor
  Serial.begin(9600); // Start the serial monitor at 9600 baud
  Serial.println("\nStart:  ...\n");
}

void loop()
{
  // Truth table row 1
  digitalWrite(inputATwo, LOW);     // Set inputAOne's power to low
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, LOW);
  Serial.println("00 + 00 = 000");  // Print to serial monitor with new line
  delay(2500);                      // Wait for 2500 milliseconds or 2.5 seconds
  // Truth table row 2
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, HIGH);
  Serial.println("00 + 01 = 001");
  delay(2500);
  // Truth table row 3
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, LOW);
  Serial.println("00 + 10 = 010");
  delay(2500);
  // Truth table row 4
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, HIGH);
  Serial.println("00 + 11 = 011");
  delay(2500);
  // Truth table row 5
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, LOW);
  Serial.println("01 + 00 = 001");
  delay(2500);
  // Truth table row 6
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, HIGH);
  Serial.println("01 + 01 = 010");
  delay(2500);
  // Truth table row 7
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, LOW);
  Serial.println("01 + 10 = 011");
  delay(2500);
  // Truth table row 8
  digitalWrite(inputATwo, LOW);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, HIGH);
  Serial.println("01 + 11 = 100");
  delay(2500);
  // Truth table row 9
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, LOW);
  Serial.println("10 + 00 = 010");
  delay(2500);
  // Truth table row 10
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, HIGH);
  Serial.println("10 + 01 = 011");
  delay(2500);
  // Truth table row 11
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, LOW);
  Serial.println("10 + 10 = 100");
  delay(2500);
  // Truth table row 12
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, LOW);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, HIGH);
  Serial.println("10 + 11 = 101");
  delay(2500);
  // Truth table row 13
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, LOW);
  Serial.println("11 + 00 = 011");
  delay(2500);
  // Truth table row 14
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, LOW);
  digitalWrite(inputBOne, HIGH);
  Serial.println("11 + 01 = 100");
  delay(2500);
  // Truth table row 15
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, LOW);
  Serial.println("11 + 10 = 101");
  delay(2500);
  // Truth table row 16
  digitalWrite(inputATwo, HIGH);
  digitalWrite(inputAOne, HIGH);
  digitalWrite(inputBTwo, HIGH);
  digitalWrite(inputBOne, HIGH);
  Serial.println("11 + 11 = 110");
  delay(2500);

  Serial.println("\nDone\n");
}
