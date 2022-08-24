int indexPos = 0;
int seq = 0;
int pind;
int pinc;
int pinb;

int pindOld;
int pincOld;
int pinbOld;

int newPin;
int newPinIndex;
int oldPin = 6;
int oldPinIndex;
bool runOnce = false;
int loopNumber = 0;

int counter = 0;

int setOrder[] = {6, 7, 8, 4, 5, 3, 9, 10, 2, 11};

void setup() {
  // put your setup code here, to run once:
  //pinMode(2,INPUT_PULLUP);
  //pinMode(3,INPUT_PULLUP);
  //pinMode(4,INPUT_PULLUP);
  //pinMode(5,INPUT_PULLUP);
  //pinMode(6,INPUT_PULLUP);
  //pinMode(7,INPUT_PULLUP);
  //pinMode(8,INPUT_PULLUP);
  //pinMode(9,INPUT_PULLUP);
  //pinMode(10,INPUT_PULLUP);
  //pinMode(11,INPUT_PULLUP);


  DDRB  &= B00000000; // digital pins 8,9 used as inputs. 10 - SS also input
  PORTB |= B11111111; // 8,9 - pull-up to +VCC via internal 100k resistors.

  DDRC  &= B00000000; // pins 14-19 (A0 - A5) also used as digital inputs
  PORTC |= B11111111; // pulled-up to +VCC via internal 100k resistors

  DDRD  &= B00000011; // digital pins 0-7 are inputs
  PORTD |= B11111100; // pulled-up to +VCC via internal 100k resistors


  Serial.begin(9600);
}

void loop() { //6,7,8,4,5,3,9,10,2,11
  // put your main code here, to run repeatedly:
  Serial.print(PIND, BIN);
  Serial.print("  ");
  Serial.print(PINB, BIN);
  Serial.print("  ");
  Serial.print(PINC, BIN);
  Serial.print("  ");
  Serial.print(newPinIndex);
  Serial.print("  ");
  Serial.print(oldPinIndex);
  Serial.print("  ");
  Serial.print(indexPos);
  Serial.print("  ");
  Serial.print(oldPin);
  Serial.print("\n");
  //delay(200);


  //Serial.println(pind);
  //Serial.print("\t");
  //Serial.print(pinc);
  //Serial.print("\t");
  //Serial.print(pinb);

  //6,7,8,4,5,3,9,10,2,11
  //  indexPos = 1;
  //  oldPin = 7;
  //  counter = 1;
  



  for (int i = 2; i < 12; i++) {
    if (digitalRead(i) == 0) {
      for (int j = 0; j < 10; j++) {
        if (i == setOrder[j]) {
          newPinIndex = j;
          break;
        }
      }
//      break;
    }

  }

  if (oldPinIndex - newPinIndex == -1) {
    indexPos++;
  }
  if (oldPinIndex - newPinIndex == 1) {
    indexPos--;
  }

  oldPinIndex = newPinIndex;
}
