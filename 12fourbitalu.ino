/*
  Created by Cristiano S
  Created in June 2023

  Gives inputs to a 4-bit ALU
*/

// Input Pins
unsigned int aZeroPin = 13;
unsigned int bZeroPin = 12;
unsigned int aOnePin = 11;
unsigned int bOnePin = 10;
unsigned int aTwoPin = 9;
unsigned int bTwoPin = 8;
unsigned int aThreePin = 7;
unsigned int bThreePin = 6;
unsigned int sZeroPin = 5;
unsigned int sOnePin = 4;
unsigned int sTwoPin = 3;
unsigned int sThreePin = 2;
unsigned int mPin = 1;
unsigned int carryPin = 0;

// Sign text variable
char signText = '?';

void setup()
{
  // Pin inputs
  pinMode(aZeroPin, OUTPUT);
  pinMode(bZeroPin, OUTPUT);
  pinMode(aOnePin, OUTPUT);
  pinMode(bOnePin, OUTPUT);
  pinMode(aTwoPin, OUTPUT);
  pinMode(bTwoPin, OUTPUT);
  pinMode(aThreePin, OUTPUT);
  pinMode(bThreePin, OUTPUT);
  pinMode(sZeroPin, OUTPUT);
  pinMode(sOnePin, OUTPUT);
  pinMode(sTwoPin, OUTPUT);
  pinMode(sThreePin, OUTPUT);
  pinMode(mPin, OUTPUT);
  pinMode(carryPin, OUTPUT);
  // Serial monitor
  Serial.begin(9600); // Start the serial monitor at 9600 baud
  Serial.println("\nStart:  ...\n");
}

void loop()
{
  for (int carryIn = 0; carryIn < 2; carryIn++) {
    // Set the carry in pin to on or off if carryIn is 1 or another number
    switch (carryIn) {
      case 1:
        digitalWrite(carryPin, HIGH);
        break;
      default:
        digitalWrite(carryPin, LOW);
        break;
    }
    for (int mInput = 0; mInput < 2; mInput++) {
      // Set the m pin to on or off if mInput is 1 or another number
      switch (mInput) {
        case 1:
          digitalWrite(mPin, HIGH);
          break;
        default:
          digitalWrite(mPin, LOW);
          break;
      }
      for (int sThree = 0; sThree < 2; sThree++) {
        // Set the sign three pin to on or off if sThree is 1 or another number
        switch (sThree) {
          case 1:
            digitalWrite(sThreePin, HIGH);
            break;
          default:
            digitalWrite(sThreePin, LOW);
            break;
        }
        for (int sTwo = 0; sTwo < 2; sTwo++) {
          // Set the sign two pin to on or off if sTwo is 1 or another number
          switch (sTwo) {
            case 1:
              digitalWrite(sTwoPin, HIGH);
              break;
            default:
              digitalWrite(sTwoPin, LOW);
              break;
          }
          for (int sOne = 0; sOne < 2; sOne++) {
            // Set the sign one pin to on or off if sOne is 1 or another number
            switch (sOne) {
              case 1:
                digitalWrite(sOnePin, HIGH);
                break;
              default:
                digitalWrite(sOnePin, LOW);
                break;
            }
            for (int sZero = 0; sZero < 2; sZero++) {
              // Set the sign zero pin to on or off if sZero is 1 or another number
              switch (sZero) {
                case 1:
                  digitalWrite(sZeroPin, HIGH);
                  break;
                default:
                  digitalWrite(sZeroPin, LOW);
                  break;
              }
              for (int inputBThree = 0; inputBThree < 2; inputBThree++) {
                // Set the b3 pin to on or off if inputBThree is 1 or another number
                switch (inputBThree) {
                  case 1:
                    digitalWrite(bThreePin, HIGH);
                    break;
                  default:
                    digitalWrite(bThreePin, LOW);
                    break;
                }
                for (int inputBTwo = 0; inputBTwo < 2; inputBTwo++) {
                  // Set the b2 pin to on or off if inputBTwo is 1 or another number
                  switch (inputBTwo) {
                    case 1:
                      digitalWrite(bTwoPin, HIGH);
                      break;
                    default:
                      digitalWrite(bTwoPin, LOW);
                      break;
                  }
                  for (int inputBOne = 0; inputBOne < 2; inputBOne++) {
                    // Set the b1 pin to on or off if inputBOne is 1 or another number
                    switch (inputBOne) {
                      case 1:
                        digitalWrite(bOnePin, HIGH);
                        break;
                      default:
                        digitalWrite(bOnePin, LOW);
                        break;
                    }
                    for (int inputBZero = 0; inputBZero < 2; inputBZero++) {
                      // Set the b0 pin to on or off if inputBZero is 1 or another number
                      switch (inputBZero) {
                        case 1:
                          digitalWrite(bZeroPin, HIGH);
                          break;
                        default:
                          digitalWrite(bZeroPin, LOW);
                          break;
                      }
                      for (int inputAThree = 0; inputAThree < 2; inputAThree++) {
                        // Set the a3 pin to on or off if inputAThree is 1 or another number
                        switch (inputAThree) {
                          case 1:
                            digitalWrite(aThreePin, HIGH);
                            break;
                          default:
                            digitalWrite(aThreePin, LOW);
                            break;
                        }
                        for (int inputATwo = 0; inputATwo < 2; inputATwo++) {
                          // Set the a2 pin to on or off if inputATwo is 1 or another number
                          switch (inputATwo) {
                            case 1:
                              digitalWrite(aTwoPin, HIGH);
                              break;
                            default:
                              digitalWrite(aTwoPin, LOW);
                              break;
                          }
                          for (int inputAOne = 0; inputAOne < 2; inputAOne++) {
                            // Set the a1 pin to on or off if inputAOne is 1 or another number
                            switch (inputAOne) {
                              case 1:
                                digitalWrite(aOnePin, HIGH);
                                break;
                              default:
                                digitalWrite(aOnePin, LOW);
                                break;
                            }
                            for (int inputAZero = 0; inputAZero < 2; inputAZero++) {
                              // Set the a0 pin to on or off if inputAZero is 1 or another number
                              switch (inputAZero) {
                                case 1:
                                  digitalWrite(aZeroPin, HIGH);
                                  break;
                                default:
                                  digitalWrite(aZeroPin, LOW);
                                  break;
                              }

                              /*4-Bit ALU logic */

                              // Inverse Inputs
                              int mInvert = !mInput;
                              int carryInInvert = !carryIn;

                              /* NOR Gates */

                              // NOR 1 logic
                              int andGateOne1 = inputAZero & inputAZero;
                              int andGateTwo1 = inputBZero & sZero;
                              int andGateThree1 = sOne & !inputBZero;
                              int norGateOne = !(andGateOne1 | andGateTwo1 | andGateThree1);

                              // NOR 2 logic
                              int andGateOne2 = !inputBZero & sTwo & inputAZero;
                              int andGateTwo2 = inputAZero & inputBZero & sThree;
                              int norGateTwo = !(andGateOne2 | andGateTwo2);

                              // NOR 3 logic
                              int andGateOne3 = inputAOne & inputAOne;
                              int andGateTwo3 = inputBOne & sZero;
                              int andGateThree3 = sOne & !inputBOne;
                              int norGateThree = !(andGateOne3 | andGateTwo3 | andGateThree3);

                              // NOR 4 logic
                              int andGateOne4 = !inputBOne & sTwo & inputAOne;
                              int andGateTwo4 = inputAOne & sThree & inputBOne;
                              int norGateFour = !(andGateOne4 | andGateTwo4);

                              // NOR 5 logic
                              int andGateOne5 = inputATwo & inputATwo;
                              int andGateTwo5 = inputBTwo & sZero;
                              int andGateThree5 = sOne & !inputBTwo;
                              int norGateFive = !(andGateOne5 | andGateTwo5 | andGateThree5);

                              // NOR 6 logic
                              int andGateOne6 = !inputBTwo & sTwo & inputATwo;
                              int andGateTwo6 = inputATwo & sThree & inputBTwo;
                              int norGateSix = !(andGateOne6 | andGateTwo6);

                              // NOR 7 logic
                              int andGateOne7 = inputAThree & inputAThree;
                              int andGateTwo7 = inputBThree & sZero;
                              int andGateThree7 = sOne & !inputBThree;
                              int norGateSeven = !(andGateOne7 | andGateTwo7 | andGateThree7);

                              // NOR 8 logic
                              int andGateOne8 = !inputBThree & sTwo & inputAThree;
                              int andGateTwo8 = inputAThree & sThree & inputBThree;
                              int norGateEight = !(andGateOne8 | andGateTwo8);

                              /* XOR Gates */

                              // XOR 1 logic
                              int nandGateOne9 = !(carryInInvert & mInvert);
                              int xorGateOne9 = norGateOne ^ norGateTwo;
                              int xorGateOne = nandGateOne9 ^ xorGateOne9;

                              // XOR 2 logic
                              int andGateOne10 = mInvert & norGateOne;
                              int andGateTwo10 = mInvert & norGateTwo & carryInInvert;
                              int norGateOne10 = !(andGateOne10 | andGateTwo10);
                              int xorGateOne10 = norGateThree ^ norGateFour;
                              int xorGateTwo = norGateOne10 ^ xorGateOne10;

                              // XOR 3 logic
                              int andGateOne11 = mInvert & norGateThree;
                              int andGateTwo11 = mInvert & norGateOne & norGateFour;
                              int andGateThree11 = mInvert & carryInInvert & norGateTwo & norGateFour;
                              int norGateOne11 = !(andGateOne11 | andGateTwo11 | andGateThree11);
                              int xorGateOne11 = norGateFive ^ norGateSix;
                              int xorGateThree = norGateOne11 ^ xorGateOne11;

                              // XOR 4 logic
                              int andGateOne12 = mInvert & norGateFive;
                              int andGateTwo12 = mInvert & norGateThree & norGateSix;
                              int andGateThree12 = mInvert & norGateOne & norGateFour & norGateSix;
                              int andGateFour12 = mInvert & carryInInvert & norGateTwo & norGateFour & norGateSix;
                              int norGateOne12 = !(andGateOne12 | andGateTwo12 | andGateThree12 | andGateFour12);
                              int xorGateOne12 = norGateSeven ^ norGateEight;
                              int xorGateFour = norGateOne12 ^ xorGateOne12;

                              // Output G logic
                              int nandGateOne13 = !(norGateTwo & norGateFour & norGateSix & norGateEight);

                              // Output P logic
                              int andGateOne14 = norGateOne & norGateFour & norGateSix & norGateEight;
                              int andGateTwo14 = norGateThree & norGateSix & norGateEight;
                              int andGateThree14 = norGateFive & norGateEight;
                              int andGateFour14 = norGateSeven & norGateSeven;
                              int norGateOne14 = !(andGateOne14 | andGateTwo14 | andGateThree14 | andGateFour14);

                              // Output Carry In Plus 4 logic
                              int nandGateOne15 = !(carryInInvert & norGateTwo & norGateFour & norGateSix & norGateEight);
                              int orGateOne15 = !nandGateOne15 | !norGateOne14;

                              // All Outputs
                              int sumZero = xorGateOne;
                              int sumOne = xorGateTwo;
                              int sumTwo = xorGateThree;
                              int sumThree = xorGateFour;
                              int aEqualsB = xorGateOne & xorGateTwo & xorGateThree & xorGateFour;
                              int outputG = nandGateOne13;
                              int outputP = norGateOne14;
                              int invertCarryInPlusFour = !orGateOne15;

                              // Print calcuation to serial monitor
                              Serial.println();
                              Serial.println("- New Sequence -");
                              Serial.print("M = ");
                              Serial.println(mInput);
                              Serial.print("iCₙ = ");
                              Serial.println(carryInInvert);
                              Serial.print("S = ");
                              Serial.print(sThree);
                              Serial.print(sTwo);
                              Serial.print(sOne);
                              Serial.println(sZero);
                              Serial.print(inputAThree);
                              Serial.print(inputATwo);
                              Serial.print(inputAOne);
                              Serial.print(inputAZero);
                              Serial.print(" ");
                              Serial.print(signText);
                              Serial.print(" ");
                              Serial.print(inputBThree);
                              Serial.print(inputBTwo);
                              Serial.print(inputBOne);
                              Serial.print(inputBZero);
                              Serial.print(" = ");
                              Serial.print(sumThree);
                              Serial.print(sumTwo);
                              Serial.print(sumOne);
                              Serial.println(sumZero);
                              Serial.print("A = B = ");
                              Serial.println(aEqualsB);
                              Serial.print("G = ");
                              Serial.println(outputG);
                              Serial.print("!Cin + 4 = ");
                              Serial.println(invertCarryInPlusFour);
                              Serial.print("P = ");
                              Serial.println(outputP);
                              delay(2500);
                            }
                          }
                        }
                      }
                    }
                  }
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
