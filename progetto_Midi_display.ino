#include <LiquidCrystal.h>


//tasti input
int sw1 = 5;
int sw2 = 3;
int sw3 = 4;


int inizio = 0;
int fine = 10;



int N;
int val1, val2, val3,val4;
//pin per collegamento lcd 16x2
LiquidCrystal lcd(6, 8 , 12, 11, 10, 9);


void setup() {
  //  Set MIDI baud rate:
  pinMode(13,OUTPUT); //pin uscita
  digitalWrite(13,LOW);
  pinMode(7,OUTPUT);
  
 digitalWrite(7,LOW);
  Serial.begin(31250);


  pinMode( 3, INPUT );          // Set pin for switch
  pinMode( 4, INPUT);
  pinMode (5, INPUT);
  
  lcd.begin(16, 2);
  lcd.print("Controller MIDI");
  delay (1000);
  lcd.clear();
  lcd.print(" Preset: SELECT");
}


void loop() {
  if (inizio>99){
    inizio=0;}
  if ((inizio >= 0) & (inizio <= 99))
  {
    
    digitalWrite(13,LOW);
    val1 = digitalRead (sw1);
    if ((val1 == HIGH)&(inizio>0)) {
      inizio--;
      //192 = program change
      Serial.write(192);
      Serial.write(inizio);
      lcd.clear();
      lcd.print("  Preset:");
      lcd.setCursor(11,0);
      lcd.print(inizio);
      delay (20);
    }

    val2 = digitalRead (sw2);
    if (val2 == HIGH) {
      inizio=inizio+10; 
      if (inizio>=100) 
        { inizio=0;}
      Serial.write(192);
      Serial.write(inizio);
      lcd.clear();
      lcd.print("  Preset:");
      lcd.setCursor(11,0);
      lcd.print(inizio);
      delay (20);
    }

    val3 = digitalRead (sw3);
    if ((val3 == HIGH) & (inizio<99)) {
      inizio++;
      Serial.write(192);
      Serial.write(inizio);
      
      lcd.clear();
      lcd.print("  Preset:");
      lcd.setCursor(11,0);
      lcd.print(inizio);
      delay (20);
    }
    
     
}
       
       
       
     

    do {
      val1 = digitalRead(sw1);
      val2 = digitalRead(sw2);
      val3 = digitalRead(sw3);
      delay (20);
    }
    while ((val1 == HIGH) || (val2 == HIGH) || (val3 == HIGH));
  }




}
