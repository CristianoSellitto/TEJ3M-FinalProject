/*
  Created by Cristiano S
  Created in May 2023

  Gives inputs to a 4-bit full adder
*/

unsigned int inputAOnePin = 13;
unsigned int inputBOnePin = 12;
unsigned int inputATwoPin = 11;
unsigned int inputBTwoPin = 10;
unsigned int inputAThreePin = 9;
unsigned int inputBThreePin = 8;
unsigned int inputAFourPin = 7;
unsigned int inputBFourPin = 6;

void setup()
{
  // Pin inputs
  pinMode(inputAOnePin, OUTPUT);
  pinMode(inputBOnePin, OUTPUT);
  pinMode(inputATwoPin, OUTPUT);
  pinMode(inputBTwoPin, OUTPUT);
  pinMode(inputAThreePin, OUTPUT);
  pinMode(inputBThreePin, OUTPUT);
  pinMode(inputAFourPin, OUTPUT);
  pinMode(inputBFourPin, OUTPUT);
  // Serial monitor
  Serial.begin(9600); // Start the serial monitor at 9600 baud
  Serial.println("\nStart:  ...\n");
}

void loop()
{
  for (int inputAFour = 0; inputAFour < 2; inputAFour++) {
    // Set the a4 pin to on or off if inputAFour is 1 or another number
    switch (inputAFour) {
      case 1:
        digitalWrite(inputAFourPin, HIGH);
        break;
      default:
        digitalWrite(inputAFourPin, LOW);
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
          for (int inputBFour = 0; inputBFour < 2; inputBFour++) {
            // Set the b4 pin to on or off if inputBFour is 1 or another number
            switch (inputBFour) {
              case 1:
                digitalWrite(inputBFourPin, HIGH);
                break;
              default:
                digitalWrite(inputBFourPin, LOW);
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
                  // 4-Bit Adder math
                  int xorGateOne = inputAOne ^ inputBOne;
                  int xorGateOneTwo = 0 ^ xorGateOne;
                  int andGateOne = inputAOne & inputBOne;
                  int andGateOneTwo = 0 & xorGateOne;
                  int orGateOne = andGateOne | andGateOneTwo;
                  int carryOutOne = orGateOne;
                  int xorGateTwoOne = inputATwo ^ inputBTwo;
                  int xorGateTwoTwo = carryOutOne ^ xorGateTwoOne;
                  int andGateTwoOne = inputATwo & inputBTwo;
                  int andGateTwoTwo = carryOutOne & xorGateTwoOne;
                  int orGateTwo = andGateTwoOne | andGateTwoTwo;
                  int carryOutTwo = orGateTwo;
                  int xorGateThreeOne = inputAThree ^ inputBThree;
                  int xorGateThreeTwo = carryOutTwo ^ xorGateThreeOne;
                  int andGateThreeOne = inputAThree & inputBThree;
                  int andGateThreeTwo = carryOutTwo & xorGateThreeOne;
                  int orGateThree = andGateThreeOne | andGateThreeTwo;
                  int carryOutThree = orGateThree;
                  int xorGateFourOne = inputAFour ^ inputBFour;
                  int xorGateFourTwo = carryOutThree ^ xorGateFourOne;
                  int andGateFourOne = inputAFour & inputBFour;
                  int andGateFourTwo = carryOutThree & xorGateFourOne;
                  int orGateFour = andGateFourOne | andGateFourTwo;
                  int carryOutFour = orGateFour;
                  int sumOne = xorGateOneTwo;
                  int sumTwo = xorGateTwoTwo;
                  int sumThree = xorGateThreeTwo;
                  int sumFour = xorGateFourTwo;

                  Serial.print(inputAFour);
                  Serial.print(inputAThree);
                  Serial.print(inputATwo);
                  Serial.print(inputAOne);
                  Serial.print(" + ");
                  Serial.print(inputBFour);
                  Serial.print(inputBThree);
                  Serial.print(inputBTwo);
                  Serial.print(inputBOne);
                  Serial.print(" = ");
                  Serial.print(sumFour);
                  Serial.print(sumThree);
                  Serial.print(sumTwo);
                  Serial.print(sumOne);
                  Serial.print(" Cout ");
                  Serial.println(carryOutFour);
                  delay(2500);
                }
              }
            }
          }
        }
      }
    }
  }

  Serial.println("\nDone\n");
}
