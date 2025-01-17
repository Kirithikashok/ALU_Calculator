#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include  <Keypad.h> //Header file for Keypad from https://github.com/Chris--A/Keypad
const  byte ROWS = 4; // Four rows
const byte COLS = 4; // Three columns
// Define  the Keymap
char keys[ROWS][COLS] = {

  {'1','2','3','A'},

  {'4','5','6','B'},

  {'7','8','9','C'},

  {'*','0','#','D'}

};


const int button1 = 8;  // the number of the pushbutton pin
const int button2 = 9;  // the number of the pushbutton pin
int button1State = 0;  // variable for reading the pushbutton status
int button2State = 0;  // variable for reading the pushbutton status


void setup() {
  Serial.begin(9600);  // start serial for output
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
}

void loop() {
  lcd.setCursor(0, 0); // Set cursor to the first line, first position
  lcd.print("ALU Calculator");
  lcd.setCursor(0, 1);

  key = kpd.getKey();  //storing pressed key value in a char

  if (key!=NO_KEY)
  DetectButtons();

  if  (result==true)
  CalculateResult();

  DisplayResult();
}

void  DetectButtons()
{ 
     lcd.clear(); //Then clean it
    if (key=='*')  //If cancel Button is pressed
    {Serial.println ("Button Cancel"); Number=Num1=Num2=0;  result=false;}
    
     if (key == '1') //If Button 1 is pressed
    {Serial.println  ("Button 1"); 
    if (Number==0)
    Number=1;
    else
    Number  = (Number*10) + 1; //Pressed twice
    }
    
     if (key == '4') //If  Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (key == '7') //If Button 7 is pressed
    {Serial.println ("Button  7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10)  + 7; //Pressed twice
    } 
  

    if (key == '0')
    {Serial.println  ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if  (key == '2') //Button 2 is Pressed
    {Serial.println ("Button 2"); 
     if  (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed  twice
    }
    
     if (key == '5')
    {Serial.println ("Button  5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10)  + 5; //Pressed twice
    }
    
     if (key == '8')
    {Serial.println  ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number  = (Number*10) + 8; //Pressed twice
    }   
  

    if (key == '#')
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (key == '3')
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3;  //Pressed twice
    }
    
     if (key == '6')
    {Serial.println  ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number  = (Number*10) + 6; //Pressed twice
    }
    
     if (key == '9')
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }
    if(ButtonPush() == true){
      lcd.setCursor(0, 1);
      lcd.print("Arithmetic:- ");
      arithmetic();
    }
    if (ButtonPush() == false){
      lcd.setCursor(0, 1);
      lcd.print("Logical:- ");
      logical();
    }

}

void CalculateResult() 
{
  if (action == '+')
    Number = Num1 + Num2;
  if (action == '-')
    Number = Num1 - Num2;
  if (action == '*')
    Number = Num1 * Num2;
  if (action == '/')
    Number = Num1 / Num2;
  if (action == '&') // Logical AND
    Number = Num1 & Num2;
  if (action == '|') // Logical OR
    Number = Num1 | Num2;
  if (action == '^') // Logical XOR
    Number = Num1 ^ Num2;
}


void DisplayResult()
{
  lcd.setCursor(0,2);   // set the cursor to column 0, line 1
  lcd.print(Num1); lcd.print(action);  lcd.print(Num2); 
  
  if (result==true)
  {lcd.print(" ="); lcd.print(Number);}  //Display the result
  
  lcd.setCursor(0, 3);   // set the cursor to column  0, line 1
  lcd.print(Number); //Display the result
}

bool ButtonPush(){
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);
  if (button1State == HIGH && button2State == LOW){
    return true;
  }
  if (button1State == LOW && button2State == HIGH){
    return false;
  }
}

