#include <LiquidCrystal.h>


int randColor;
int randDirection;

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);        // select the pins used on the LCD panel

void setup(){
    lcd.begin(16, 2);                       // start the library
    Serial.begin(9600);
    randomSeed(analogRead(1));
}

void loop() {
  int val;
  val=analogRead(0);
  if (val < 1000) {wood();}
  Serial.println(val);
}

void wood() {
  lcd.clear();
  randColor = random(1,217);
  Serial.println(randColor);
  lcd.setCursor(0, 0);
  if (randColor < 73) {lcd.print("BLACK");}
  else if (randColor < 145) {lcd.print("YELLOW");}
  else if (randColor < 203) {lcd.print("RED");}
  else {lcd.print("GLOW");}
  lcd.setCursor(10, 0);
  lcd.print(randColor);

  randDirection = random(1,5);
  Serial.println(randDirection);
  lcd.setCursor(0, 1);
  if (randDirection == 1) {lcd.print("UP");}
  else if (randDirection == 2) {lcd.print("DN");}
  else if (randDirection == 3) {lcd.print("LT");}
  else {lcd.print("RT");}
  lcd.setCursor(10, 1);  
  lcd.print(randDirection);
  Serial.println("--Next set--");
  delay(500);
}
