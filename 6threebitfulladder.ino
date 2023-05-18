/*
  Created by Cristiano S
  Created in May 2023

  Gives inputs to a 2-bit full adder and subtractor in two's compliment
*/

unsigned int inputSignPin = 12;
unsigned int inputAOnePin = 11;
unsigned int inputBOnePin = 10;
unsigned int inputATwoPin = 9;
unsigned int inputBTwoPin = 8;

void setup()
{
  // Pin inputs
  pinMode(inputSignPin, OUTPUT);
  pinMode(inputAOnePin, OUTPUT);
  pinMode(inputBOnePin, OUTPUT);
  pinMode(inputATwoPin, OUTPUT);
  pinMode(inputBTwoPin, OUTPUT);
  // Serial monitor
  Serial.begin(9600);                // Start the serial monitor at 9600 baud
  Serial.println("\nStart:  ...\n"); // Print to serial monitor on a new line
}

void loop()
{
  for (int inputSign = 0; inputSign < 2; inputSign++) {
    // Set the sign pin to on or off if inputATwo is 1 or another number
    switch (inputSign) {
      case 1:
        digitalWrite(inputSignPin, HIGH);
        break;
      default:
        digitalWrite(inputSignPin, LOW);
        break;
    }
    for (int inputATwo = 0; inputATwo < 2; inputATwo++) {
      // Set the a2 pin to on or off if inputATwo is 1 or another number
      switch (inputATwo) {
        case 1:
          digitalWrite(inputATwoPin, HIGH);
          break;
        default:
          digitalWrite(inputATwoPin, LOW);
          break;
      }
      for (int inputAOne = 0; inputAOne < 2; inputAOne++) {
        // Set the a1 pin to on or off if inputAOne is 1 or another number
        switch (inputAOne) {
          case 1:
            digitalWrite(inputAOnePin, HIGH);
            break;
          default:
            digitalWrite(inputAOnePin, LOW);
            break;
        }
        for (int inputBTwo = 0; inputBTwo < 2; inputBTwo++) {
          // Set the b2 pin to on or off if inputBTwo is 1 or another number
          switch (inputBTwo) {
            case 1:
              digitalWrite(inputBTwoPin, HIGH);
              break;
            default:
              digitalWrite(inputBTwoPin, LOW);
              break;
          }
          for (int inputBOne = 0; inputBOne < 2; inputBOne++) {
            // Set the b1 pin to on or off if inputBOne is 1 or another number
            switch (inputBOne) {
              case 1:
                digitalWrite(inputBOnePin, HIGH);
                break;
              default:
                digitalWrite(inputBOnePin, LOW);
                break;
            }
            // 2-Bit adder with subtraction logic
            int xorGateSp = inputSign ^ inputBOne;
            int xorGateSp2 = inputSign ^ inputBTwo;
            int xorGateOne = inputAOne ^ xorGateSp;
            int xorGateOne2 = xorGateOne ^ inputSign;
            int andGateOne = inputAOne & xorGateSp;
            int andGateOne2 = inputSign & xorGateOne;
            int orGateOne = andGateOne | andGateOne2;
            int carryOutOne = orGateOne;
            int xorGateTwo = inputATwo ^ xorGateSp2;
            int xorGateTwo2 = xorGateTwo ^ carryOutOne;
            int andGateTwo = inputATwo & xorGateSp2;
            int andGateTwo2 = xorGateTwo & carryOutOne;
            int orGateTwo = andGateTwo | andGateTwo2;
            int carryOutTwo = orGateTwo;
            int sumOne = xorGateOne2;
            int sumTwo = xorGateTwo2;

            // Print calcuation to serial monitor
            char signText = '+';
            if (inputSign == 1) {
              signText = '-';
            }

            Serial.print(inputATwo);
            Serial.print(inputAOne);
            Serial.print(" ");
            Serial.print(signText);
            Serial.print(" ");
            Serial.print(inputBTwo);
            Serial.print(inputBOne);
            Serial.print(" = ");
            Serial.print(sumTwo);
            Serial.print(sumOne);
            Serial.print(" Cout ");
            Serial.println(carryOutTwo);
            delay(3000);
          }
        }
      }
    }
  }

  Serial.println("\nDone\n");
}
