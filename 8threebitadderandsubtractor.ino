/*
  Created by Cristiano S
  Created in May 2023

  Gives inputs to a 3-bit full adder and subtractor
*/

unsigned int inputSignPin = 13;
unsigned int inputAOnePin = 12;
unsigned int inputBOnePin = 11;
unsigned int inputATwoPin = 10;
unsigned int inputBTwoPin = 9;
unsigned int inputAThreePin = 8;
unsigned int inputBThreePin = 7;

void setup()
{
  // Pin inputs
  pinMode(inputSignPin, OUTPUT);
  pinMode(inputAOnePin, OUTPUT);
  pinMode(inputBOnePin, OUTPUT);
  pinMode(inputATwoPin, OUTPUT);
  pinMode(inputBTwoPin, OUTPUT);
  pinMode(inputAThreePin, OUTPUT);
  pinMode(inputBThreePin, OUTPUT);
  // Serial monitor
  Serial.begin(9600); // Start the serial monitor at 9600 baud
  Serial.println("\nStart:  ...\n");
}

void loop()
{
  for (int inputSign = 0; inputSign < 2; inputSign++) {
    // Set the sign pin to on or off if inputSign is 1 or another number
    switch (inputSign) {
      case 1:
        digitalWrite(inputSignPin, HIGH);
        break;
      default:
        digitalWrite(inputSignPin, LOW);
        break;
    }
    for (int inputAThree = 0; inputAThree < 2; inputAThree++) {
      // Set the a3 pin to on or off if inputAThree is 1 or another number
      switch (inputAThree) {
        case 1:
          digitalWrite(inputAThreePin, HIGH);
          break;
        default:
          digitalWrite(inputAThreePin, LOW);
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
          for (int inputBThree = 0; inputBThree < 2; inputBThree++) {
            // Set the b3 pin to on or off if inputBThree is 1 or another number
            switch (inputBThree) {
              case 1:
                digitalWrite(inputBThreePin, HIGH);
                break;
              default:
                digitalWrite(inputBThreePin, LOW);
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
                // 3-Bit adder and subtractor math
                int xorGateSp = inputSign ^ inputBOne;
                int xorGateSp2 = inputSign ^ inputBTwo;
                int xorGateSp3 = inputSign ^ inputBThree;
                int xorGateOne = inputAOne ^ xorGateSp;
                int xorGateOneTwo = inputSign ^ xorGateOne;
                int andGateOne = inputAOne & xorGateSp;
                int andGateOneTwo = inputSign & xorGateOne;
                int orGateOne = andGateOne | andGateOneTwo;
                int carryOutOne = orGateOne;
                int xorGateTwoOne = inputATwo ^ xorGateSp2;
                int xorGateTwoTwo = carryOutOne ^ xorGateTwoOne;
                int andGateTwoOne = inputATwo & xorGateSp2;
                int andGateTwoTwo = carryOutOne & xorGateTwoOne;
                int orGateTwo = andGateTwoOne | andGateTwoTwo;
                int carryOutTwo = orGateTwo;
                int xorGateThreeOne = inputAThree ^ xorGateSp3;
                int xorGateThreeTwo = carryOutTwo ^ xorGateThreeOne;
                int andGateThreeOne = inputAThree & xorGateSp3;
                int andGateThreeTwo = carryOutTwo & xorGateThreeOne;
                int orGateThree = andGateThreeOne | andGateThreeTwo;
                int carryOutThree = orGateThree;
                int sumOne = xorGateOneTwo;
                int sumTwo = xorGateTwoTwo;
                int sumThree = xorGateThreeTwo;

                // Print calcuation to serial monitor
                char signText = '+';
                if (inputSign == 1) {
                  signText = '-';
                }

                Serial.print(inputAThree);
                Serial.print(inputATwo);
                Serial.print(inputAOne);
                Serial.print(" ");
                Serial.print(signText);
                Serial.print(" ");
                Serial.print(inputBThree);
                Serial.print(inputBTwo);
                Serial.print(inputBOne);
                Serial.print(" = ");
                Serial.print(sumThree);
                Serial.print(sumTwo);
                Serial.print(sumOne);
                Serial.print(" Cout ");
                Serial.println(carryOutThree);
                delay(2500);
              }
            }
          }
        }
      }
    }
  }

  Serial.println("\nDone\n");
}
