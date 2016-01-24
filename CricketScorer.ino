#include "IRremote.h" //include the infrared library

int RECV_PIN = 8; //use digital pin 8 to 

int score = 0; //add score as a variable

int overs = 0; //add overs as a variable

int runRate = 0; //add runRate as a variable

int balls = 0; //add score as a variable

int resetPin = 9; //use digital pin 9 to reset

IRrecv irrecv(RECV_PIN);

decode_results results;

#include <LiquidCrystal.h> //include the library code

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //delcare the lcds pins

void setup() {
  pinMode(9, INPUT); //declare pin 9 as input
  irrecv.enableIRIn(); //enable the ir receiver
  
  lcd.begin(16, 2); //state the lcds amount of columns and rows
}

void loop() {
  overs = balls / 6; //calculate the overs
  runRate = score / overs; //calculate the run rate
  
  lcd.setCursor(0,0); //set cursor at line 1 space 1
  lcd.print("Runs:"); //add the word "Runs:" at 0,0
  lcd.print(score); //add the variable 'runs' after the word
  lcd.setCursor(8,0); //set cursor to line 1 space
  lcd.print("Overs:"); //add the word "Overs:" at 0,0
  lcd.print(overs); //add the variable 
  lcd.setCursor(0, 1);
  lcd.print("Mins:"); //add the word "Mins:" at line 2 space 1
  lcd.print(millis() / 60000); //add the minutes spent batting after "Mins:"
  lcd.setCursor(8,1);
  lcd.print("Rate:"); //add the word "Rate:"
  lcd.print(runRate); //add the variable 'runRate' after "Rate:"
  
 if (irrecv.decode(&results)) //decode infrared
 
 {
  translateIR(); //translate ir signal
  irrecv.resume(); //get ready to receive next value
 }
}

 void translateIR()
 {
    switch(results.value) {
{
  case 0x4F09DFF1: //add your own remote value
    score += 0; //add no runs
    balls ++; //add a ball
    break;
    
  case 0xE8289565: //add your own remote value
    score += 1; //add 1 run
    balls ++; //add 1 ball
    break;

  case 0x66800DCD: //add your own remote value
    score += 2; //add 2 runs
    balls ++; //add 1 ball
    break;
    
  case 0xC03CA26F: //add your own remote value
    score += 3; //add 3 runs 
    balls ++; //add 1 ball
    break;

  case 0x490541DF: //add your own remote value
    score += 4; //add 4 runs
    balls ++; //add 1 ball
    break;

  case 0xB1CE824B: //add your own remote value
    score += 5; //add 5 runs
    balls ++; //add 1 ball
    break;

  case 0x6F6EBBF3: //add your own remote value
    score += 6; //add 6 runs
    balls ++; //add 1 ball
    break;
  case 0x335A607E://add your own remote value
  pinMode(9, OUTPUT); //reset the arduino
  digitalWrite(9, LOW); //reset the arduino
  break;
    }
   }
 }
