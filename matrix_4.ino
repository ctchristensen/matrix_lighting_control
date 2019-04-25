//==========MATRIX PHYSICAL PIN ADDRESSES================

//Column pins, which are anodes.
byte cols[] = {2, 3, 4, 5, 6, 7, 8, 9};

//Row pins, which are cathodes.
byte rows[] = {10, 11, 12, 13, 14, 15, 16, 17};
//=======================================================

//Patterns Array, may hold an indeterminate number of pattern arrays.
int pats[][8][8] ={
//TEST PATTERN 1
//int pattern1[8][8] =
{
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
},

//TEST PATTERN 2
//int pattern2[8][8] =
{
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 1, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
}
};


void setup() {
//  Serial.begin(9600);
  //Initialize pin outs. Set columns (anodes) as low...
  for (int pin = 0; pin < 8; pin++){
    pinMode(cols[pin], OUTPUT);
    digitalWrite(cols[pin], LOW);
  //and set rows (cathodes) as high.
    pinMode(rows[pin], OUTPUT);
    digitalWrite(rows[pin], HIGH);
  }
}
int pat = 0;
unsigned long increment = millis();
void loop() {
//  Serial.print(increment);
//  Serial.print("\n");
  if (increment < millis()-3000){
    pat = ((pat+1)%2);
    increment = millis();
  }
  for (int row = 0; row < 8; row++){
    digitalWrite(rows[row], LOW);
    for (int col = 0; col < 8; col++){
      if (pats[pat][row][col] == 1){
        digitalWrite(cols[col], HIGH);
        delayMicroseconds(400);
//        delay(200);
        digitalWrite(cols[col], LOW);
      }
    }
    digitalWrite(rows[row], HIGH);
  }
}
