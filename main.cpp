// C++ code
//
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);
void setup()
{
  	pinMode(2,OUTPUT);
  	pinMode(3,OUTPUT);
  	pinMode(4,OUTPUT);
  	pinMode(5,OUTPUT);
 	pinMode(6,OUTPUT);
  	pinMode(7,OUTPUT);
 	pinMode(8,OUTPUT);
  	pinMode(9,OUTPUT);
  	pinMode(A1,INPUT);
	pinMode(A0,INPUT);
  	Serial.begin(9600);
  	lcd_1.begin(10, 2);
    lcd_1.setCursor(0, 0);       
    lcd_1.print("SAFE");
    lcd_1.setCursor(0, 1);
  	lcd_1.print("YIPPY");
  	digitalWrite(8,HIGH);
  	
}

void loop()
{
  	int buttonState = digitalRead(10);
	int smoke = analogRead(A0);
  	int analogValue = analogRead(A1);
    float voltage = analogValue * (5.0 / 1023.0); 
    float temperatureC = (voltage - 0.5) * 100.0;
	
  	
    // check if the pushbutton is pressed.
  if (buttonState == HIGH){
    
    	lcd_1.clear();
    	noTone(9);
    	digitalWrite(8,HIGH);
    	digitalWrite(2,LOW);
  		digitalWrite(3,LOW);
  		digitalWrite(4,LOW);
  		digitalWrite(5,LOW);
  		digitalWrite(6,LOW);
  		digitalWrite(7,LOW);
  		lcd_1.setCursor(0, 0);       
    	lcd_1.print("SAFE");
    	lcd_1.setCursor(0, 1);
  		lcd_1.print("YIPPY");
  		delay(1000);
    
  }else {
    if (smoke > 20 && smoke <= 25)
{
    digitalWrite(8, LOW);
    lcd_1.clear();
    digitalWrite(2, HIGH);
    lcd_1.print("READING: ");
    lcd_1.print(smoke);
    delay(1000); 
}
else if (smoke > 25 && smoke <= 30)
{
    digitalWrite(8, LOW);
    lcd_1.clear();
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    lcd_1.print("READING: ");
    lcd_1.print(smoke);
    delay(1000); 
}
else if (smoke > 30 && smoke <= 35)
{
    digitalWrite(8, LOW);
    lcd_1.clear();
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    lcd_1.print("READING: ");
    lcd_1.print(smoke);
    delay(1000); 
}
else if (smoke > 35 && smoke <= 40)
{
    digitalWrite(8, LOW);
    lcd_1.clear();
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    lcd_1.print("READING: ");
    lcd_1.print(smoke);
    delay(1000); 
}
else if (smoke > 40 && smoke <= 50)
{
    digitalWrite(8, LOW);
    lcd_1.clear();
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    lcd_1.print("READING: ");
    lcd_1.print(smoke);
    delay(1000); 
}
else if (smoke > 60)
{
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    lcd_1.clear();
    lcd_1.setCursor(0, 0);       
    lcd_1.print("DANGEROUS");
    lcd_1.setCursor(0, 1);
    lcd_1.print("READING: ");
    lcd_1.print(smoke);
    delay(500);
    tone(9, 1000);        
    delay(1000); 
}	
        }         
  	if (temperatureC > 100)
    {
        digitalWrite(2,HIGH);
  		digitalWrite(3,HIGH);
  		digitalWrite(4,HIGH);
  		digitalWrite(5,HIGH);
  		digitalWrite(6,HIGH);
  		digitalWrite(7,HIGH);             
    	lcd_1.setCursor(0, 0);       
    	lcd_1.print("Temp Warning");
      	lcd_1.setCursor(0, 1);
  		lcd_1.print("Temp: ");
  		lcd_1.print(temperatureC);
      	lcd_1.print(" C");
      	tone(9, 1000, 50);  
    	delay(250);        
    	noTone(9);         
    	delay(1000); 
    } 
    else if (temperatureC < 100)
    {
      lcd_1.clear();
    }  
}
