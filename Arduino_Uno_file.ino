#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Initialize the LCD with its I2C address, and dimensions (16x2)
#include <Servo.h> 

Servo myservo1;  // Create a Servo object named 'myservo1'

int IR1 = 4;  // Digital pin for IR sensor 1
int IR2 = 6;  // Digital pin for IR sensor 2

int Slot = 4;  // Number of available parking slots

int flag1 = 0;  // Flag for IR sensor 1
int flag2 = 0;  // Flag for IR sensor 2

void setup() {
  lcd.begin(2,16);  // Initialize the LCD with 2 lines and 16 characters per line
  lcd.backlight();  // Turn on the backlight of the LCD
  pinMode(IR1, INPUT);  // Set IR sensor 1 pin as input
  pinMode(IR2, INPUT);  // Set IR sensor 2 pin as input
  
  myservo1.attach(9);  // Attach the servo motor to digital pin 9
  myservo1.write(145);  // Set initial position of the servo motor
  
  lcd.setCursor (0,0);  // Set cursor to the first line, first position
  lcd.print("  Welcome To");  // Print welcome message on LCD
  lcd.setCursor (0,1);  // Set cursor to the second line, first position
  lcd.print(" SMIU Parking ");  // Print parking system name on LCD
  delay (3000);  // Delay for 3 seconds
  lcd.clear();  // Clear the LCD screen
}

void loop(){ 
  if(digitalRead (IR1) == LOW && flag1==0){
    if(Slot > 0){
      flag1 = 1;  // Set flag for IR sensor 1
      if(flag2 == 0){
        myservo1.write(0);  // Open parking slot using servo
        Slot = Slot - 1;  // Decrease available slots by 1
      }
    } else {
      lcd.setCursor (0,0);  // Set cursor to the first line, first position
      lcd.print("     Sorry");  // Print message indicating parking is full
      lcd.setCursor (0,1);  // Set cursor to the second line, first position
      lcd.print("  Parking Full");  // Print message indicating parking is full
      delay (2000);  // Delay for 2 seconds
      lcd.clear();  // Clear the LCD screen
    }
  }

  if(digitalRead (IR2) == LOW && flag2 == 0){
    flag2 = 1;  // Set flag for IR sensor 2
    if(flag1 == 0){
      myservo1.write(0);  // Open parking slot using servo
      Slot = Slot + 1;  // Increase available slots by 1
    }
  }

  if(flag1 == 1 && flag2 == 1){
    delay (500);  // Delay for 0.5 seconds
    myservo1.write(145);  // Close parking slot using servo
    flag1 = 0;  // Reset flag for IR sensor 1
    flag2 = 0;  // Reset flag for IR sensor 2
  }

  lcd.setCursor (0,0);  // Set cursor to the first line, first position
  lcd.print("   Welcome!");  // Print welcome message on LCD
  lcd.setCursor (0,1);  // Set cursor to the second line, first position
  lcd.print("  Slot Left: ");  // Print message indicating slots left
  lcd.print(Slot);  // Print the number of available slots on LCD
}
