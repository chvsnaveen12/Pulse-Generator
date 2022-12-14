#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 3, d5 = 4, d6 = 5, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define outputA A1
#define outputB A2
#define button A0
#define menuButton 10

int aLastState;
int aState;
int delayVal;
bool pulse = false;
bool micro = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(button,INPUT_PULLUP);
  pinMode(menuButton,INPUT_PULLUP);
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,LOW);
  aLastState = digitalRead(outputA);
}

void loop() {
  singleStep();
  delay(500);
  multiStep();
  delay(500);
  micro = false;
  delayAdjust();
  delay(500);
  micro = true;
  delayAdjust();
  delay(500);
}

void multiStep(){
  lcd.clear();
  int multiCount = 0;
  lcd.print("Multi Step Mode");
  lcd.setCursor(0, 1);
  lcd.print("Count:");
  lcd.print(multiCount);
  while(true){
    aState = digitalRead(outputA);
    if(aState != aLastState){     
      if(digitalRead(outputB) != aState){ 
        if(multiCount > 0)
          multiCount--; 
      }
      else
        multiCount++;
          
    lcd.clear();    
    lcd.print("Multi Step Mode");
    lcd.setCursor(0, 1);
    lcd.print("Count:");
    lcd.print(multiCount);
    }
    
    aLastState = aState;

    if(digitalRead(button) == 0){
      delayVal = 1;
      if(multiCount<150)
        delayVal = 20;
      if(multiCount<10)
        delayVal = 250;
        
      for (int i=0; i<multiCount;i++){
        digitalWrite(2,HIGH);
        delay(delayVal);
        digitalWrite(2,LOW);
        delay(delayVal);
      }
    }
    
    if(digitalRead(menuButton) == 0)
      break;    
    
  }
  
}

void delayAdjust(){
  delayVal = 100;
  lcd.clear(); 
  lcd.print("Delay Mode");
  lcd.setCursor(0, 1);
  if(micro)
    lcd.print("micros:"); 
  else
    lcd.print("millis:");
  lcd.print(delayVal);
    
  while(true){
    aState = digitalRead(outputA);
    if(aState != aLastState){     
      if(digitalRead(outputB) != aState){ 
        if(delayVal > 1)
          delayVal--;
      }
      else
        delayVal++;
          
    lcd.clear();    
    lcd.print("Delay Mode");
    lcd.setCursor(0, 1);
    if(micro)
      lcd.print("micros:"); 
    else
      lcd.print("millis:");
    lcd.print(delayVal);
    }

    if(pulse){
      digitalWrite(2,HIGH);
      if(micro)
        delayMicroseconds(delayVal);
      else
        delay(delayVal);
      digitalWrite(2,LOW);
      if(micro)
        delayMicroseconds(delayVal);  
      else
        delay(delayVal);
      
    }

    if(digitalRead(button) == 0){
      pulse = !pulse;
      delay(500);
    }
  
    if(digitalRead(menuButton) == 0)
      break;    
      
   aLastState = aState;  
   }
}
  
void singleStep(){
  lcd.clear();
  int singleCount = 0;
  lcd.print("Single Step Mode");
  lcd.setCursor(0, 1);
  lcd.print(singleCount);
  while(true){
    if(digitalRead(button) == 0){
      singleCount++;
      lcd.setCursor(0, 1);
      lcd.print(singleCount);
      digitalWrite(2,HIGH);
      delay(250);
      digitalWrite(2,LOW);
      delay(250);
    }
  
    if(digitalRead(menuButton) == 0)
      break;    
    
  }
}
