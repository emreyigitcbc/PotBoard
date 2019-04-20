/*

      POTBOARD PROJECT - "EMRE CEBECI"

  IF YOU CHANGE PINS, DO NOT FORGET TO CHANGE FROM CODE AND ARDUINO!

  POT 1 (pot):
  - Middle leg to A0

  POT 2 (pot2):
  - Middle leg to A1

  BUTTON 1 (button):
  - Random leg to A2

  BUTTON 2 (button2):
  - Random leg to A3

  LCD (lcd):
  - RS: 12
  - RW: GND
  - E: 11
  - D4: 5
  - D5: 4
  - D6: 3
  - D7: 2
   VSS: GND
   VCC: 5V
   A: 5V (or 3.3V)
   K: GND

  STATUE LED: (led)
  - VDD to 6

  FONT LED: (bled)
  - VDD to 9
  [*] If you want to write anything to Serial Port screen, just use Serial.begin(9600) and add "Serial.print("letter")" below every "lcd.print()"
  [*] YOU NEED "OneButton" LIBRARY!

  -Download OneButton Library:
  https://github.com/mathertel/OneButton

*/

// LIBRARIES
#include <LiquidCrystal.h>
#include "OneButton.h"

const byte but = A2;
OneButton button(but, true);

const byte but2 = A3;
OneButton button2(but2, true);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte pot = A0;
const byte pot2 = A1;
const byte led = 6;
const byte bled = 9;

// LCD WIDHT AND HEIGHT, IF YOU USING 20x4, DO NOT FORGET TO CHANGE!
int lcdw = 16;
int lcdh = 2;

int pot_deger = 0;
int pot2_deger = 0;
int konumx = 0;
int konumy = 0;
int buyukharf = 1;

void setup()
{
  pinMode(pot, INPUT);
  pinMode(pot2, INPUT);
  pinMode(led, OUTPUT);
  pinMode(bled, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  button.attachClick(basildi); // EXECUTE basildi ON CLICK
  button2.attachClick(bicim); // EXECUTE basildi ON CLICK
  button.attachDoubleClick(tekTemizle); // EXECUTE tekTemizle ON DOUBLE CLICK
  button.attachLongPressStop(temizle); // EXECUTE temizle ON LONG PRESS AND RELEASE
}

void loop()
{
  if (buyukharf == 1) {
    digitalWrite(bled, HIGH);
  } else {
    digitalWrite(bled, LOW);
  }
  pot_deger = analogRead(pot);
  pot_deger = map(pot_deger, 0, 1023, 0, 25);
  pot2_deger = analogRead(pot2);
  pot2_deger = map(pot2_deger, 0, 1023, 0, 24);

  button.tick();
  button2.tick();

  // LETTERS
  if (buyukharf == 1) {
    if (pot_deger == 0) {
      lcd.setCursor(konumx, konumy);
      lcd.print("A");
    } else if (pot_deger == 1) {
      lcd.setCursor(konumx, konumy);
      lcd.print("B");
    } else if (pot_deger == 2) {
      lcd.setCursor(konumx, konumy);
      lcd.print("C");
    } else if (pot_deger == 3) {
      lcd.setCursor(konumx, konumy);
      lcd.print("D");
    } else if (pot_deger == 4) {
      lcd.setCursor(konumx, konumy);
      lcd.print("E");
    } else if (pot_deger == 5) {
      lcd.setCursor(konumx, konumy);
      lcd.print("F");
    } else if (pot_deger == 6) {
      lcd.setCursor(konumx, konumy);
      lcd.print("G");
    } else if (pot_deger == 7) {
      lcd.setCursor(konumx, konumy);
      lcd.print("H");
    } else if (pot_deger == 8) {
      lcd.setCursor(konumx, konumy);
      lcd.print("I");
    } else if (pot_deger == 9) {
      lcd.setCursor(konumx, konumy);
      lcd.print("J");
    } else if (pot_deger == 10) {
      lcd.setCursor(konumx, konumy);
      lcd.print("K");
    } else if (pot_deger == 11) {
      lcd.setCursor(konumx, konumy);
      lcd.print("L");
    } else if (pot_deger == 12) {
      lcd.setCursor(konumx, konumy);
      lcd.print("M");
    } else if (pot_deger == 13) {
      lcd.setCursor(konumx, konumy);
      lcd.print("N");
    } else if (pot_deger == 14) {
      lcd.setCursor(konumx, konumy);
      lcd.print("O");
    } else if (pot_deger == 15) {
      lcd.setCursor(konumx, konumy);
      lcd.print("P");
    } else if (pot_deger == 16) {
      lcd.setCursor(konumx, konumy);
      lcd.print("R");
    } else if (pot_deger == 17) {
      lcd.setCursor(konumx, konumy);
      lcd.print("S");
    } else if (pot_deger == 18) {
      lcd.setCursor(konumx, konumy);
      lcd.print("T");
    } else if (pot_deger == 19) {
      lcd.setCursor(konumx, konumy);
      lcd.print("U");
    } else if (pot_deger == 20) {
      lcd.setCursor(konumx, konumy);
      lcd.print("V");
    } else if (pot_deger == 21) {
      lcd.setCursor(konumx, konumy);
      lcd.print("Y");
    } else if (pot_deger == 22) {
      lcd.setCursor(konumx, konumy);
      lcd.print("Z");
    } else if (pot_deger == 24) {
      lcd.setCursor(konumx, konumy);
      lcd.print(" ");
    }
  }
  if (buyukharf == 0) {
    if (pot_deger == 0) {
      lcd.setCursor(konumx, konumy);
      lcd.print("a");
    } else if (pot_deger == 1) {
      lcd.setCursor(konumx, konumy);
      lcd.print("b");
    } else if (pot_deger == 2) {
      lcd.setCursor(konumx, konumy);
      lcd.print("c");
    } else if (pot_deger == 3) {
      lcd.setCursor(konumx, konumy);
      lcd.print("d");
    } else if (pot_deger == 4) {
      lcd.setCursor(konumx, konumy);
      lcd.print("e");
    } else if (pot_deger == 5) {
      lcd.setCursor(konumx, konumy);
      lcd.print("f");
    } else if (pot_deger == 6) {
      lcd.setCursor(konumx, konumy);
      lcd.print("g");
    } else if (pot_deger == 7) {
      lcd.setCursor(konumx, konumy);
      lcd.print("h");
    } else if (pot_deger == 8) {
      lcd.setCursor(konumx, konumy);
      lcd.print("i");
    } else if (pot_deger == 9) {
      lcd.setCursor(konumx, konumy);
      lcd.print("j");
    } else if (pot_deger == 10) {
      lcd.setCursor(konumx, konumy);
      lcd.print("k");
    } else if (pot_deger == 11) {
      lcd.setCursor(konumx, konumy);
      lcd.print("l");
    } else if (pot_deger == 12) {
      lcd.setCursor(konumx, konumy);
      lcd.print("m");
    } else if (pot_deger == 13) {
      lcd.setCursor(konumx, konumy);
      lcd.print("n");
    } else if (pot_deger == 14) {
      lcd.setCursor(konumx, konumy);
      lcd.print("o");
    } else if (pot_deger == 15) {
      lcd.setCursor(konumx, konumy);
      lcd.print("p");
    } else if (pot_deger == 16) {
      lcd.setCursor(konumx, konumy);
      lcd.print("r");
    } else if (pot_deger == 17) {
      lcd.setCursor(konumx, konumy);
      lcd.print("s");
    } else if (pot_deger == 18) {
      lcd.setCursor(konumx, konumy);
      lcd.print("t");
    } else if (pot_deger == 19) {
      lcd.setCursor(konumx, konumy);
      lcd.print("u");
    } else if (pot_deger == 20) {
      lcd.setCursor(konumx, konumy);
      lcd.print("v");
    } else if (pot_deger == 21) {
      lcd.setCursor(konumx, konumy);
      lcd.print("y");
    } else if (pot_deger == 22) {
      lcd.setCursor(konumx, konumy);
      lcd.print("z");
    } else if (pot_deger == 24) {
      lcd.setCursor(konumx, konumy);
      lcd.print(" ");
    }
  }
  // DIGITS
  if (pot2_deger == 0 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("0");
  } else if (pot2_deger == 1 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("1");
  } else if (pot2_deger == 2 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("2");
  } else if (pot2_deger == 3 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("3");
  } else if (pot2_deger == 4 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("4");
  } else if (pot2_deger == 5 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("5");
  } else if (pot2_deger == 6 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("6");
  } else if (pot2_deger == 7 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("7");
  } else if (pot2_deger == 8 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("8");
  } else if (pot2_deger == 9 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("9");
  } else if (pot2_deger == 10 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("/");
  } else if (pot2_deger == 11 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("-");
  } else if (pot2_deger == 12 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("=");
  } else if (pot2_deger == 13 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("_");
  } else if (pot2_deger == 14 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("*");
  } else if (pot2_deger == 15 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("$");
  } else if (pot2_deger == 16 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("&");
  } else if (pot2_deger == 17 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("\\");
  } else if (pot2_deger == 18 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("(");
  } else if (pot2_deger == 19 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print(")");
  } else if (pot2_deger == 20 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("[");
  } else if (pot2_deger == 21 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("]");
  } else if (pot2_deger == 22 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("{");
  } else if (pot2_deger == 23 && pot_deger == 23) {
    lcd.setCursor(konumx, konumy);
    lcd.print("}");
  }
}

// WHAT HAPPENS ON CLICK BUTTON
void basildi() {
  konumx++;
  if (konumx == 16) {
    konumx = 0;
    konumy = 1;
  }
  if (konumx == 16 && konumy == 1) {
    temizle();
  }
  ledYak();
}

// TURN ON LED
void ledYak() {
  digitalWrite(led, 1);
  delay(250);
  digitalWrite(led, 0);
}

// CLEAR EVERYTHING
void temizle() {
  konumx = 0;
  konumy = 0;
  lcd.clear();
  ledYak();
}

// DELETE LAST CHRACTER AND COME BACK
void tekTemizle() {
  lcd.setCursor(konumx, konumy);
  lcd.print(" ");
  konumx = konumx - 1;
  lcd.setCursor(konumx, konumy);
  lcd.print(" ");
  if (konumx < 0) {
    konumx = 0;
  }
  ledYak();
}

// UPPER CASE - LOWER CASE
void bicim() {
  if (buyukharf == 1) {
    buyukharf = 0;
  } else if (buyukharf == 0) {
    buyukharf = 1;
  }
  ledYak();
}
