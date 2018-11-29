
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal.h>

MPU6050 mpu6050(Wire);
  int hello1=0;
  int hello2=0;
  int hello3=0;
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  lcd.begin(16, 2);
}

void loop() 
{
  mpu6050.update();
  hello1=mpu6050.getAngleX();
  hello2=mpu6050.getAngleY();
  hello3=mpu6050.getAngleZ();
  Serial.print("angleX : ");
  Serial.print(hello1);
  Serial.print("\tangleY : ");
  Serial.print(hello2);
  Serial.print("\tangleZ : ");
  Serial.print(hello3);
  Serial.print("\n");
  lcd.display();
  if(hello1>0)
  {
    digitalWrite(4,HIGH);
    lcd.setCursor(0,0);
    lcd.print("LIGHT");
    lcd.setCursor(0,1);
    lcd.print("ON");
  }
  else
  {
    digitalWrite(4,LOW);
    lcd.setCursor(0,0);
    lcd.print("LIGHT");
    lcd.setCursor(0,1);
    lcd.print("OFF");
  }
  if(hello2>0)
  {
    digitalWrite(5,HIGH);
    lcd.setCursor(6,0);
    lcd.print("LIGHT2");
    lcd.setCursor(6,1);
    lcd.print("ON");
  }
  else
  {
    digitalWrite(5,LOW);
    lcd.setCursor(6,0);
    lcd.print("LIGHT2");
    lcd.setCursor(6,1);
    lcd.print("OFF");
  }
  if(hello3>0)
  {
    digitalWrite(6,HIGH);
    lcd.setCursor(13,0);
    lcd.print("FAN");
    lcd.setCursor(13,1);
    lcd.print("ON");
  }
  else
  {
    digitalWrite(6,LOW);
    lcd.setCursor(13,0);
    lcd.print("FAN");
    lcd.setCursor(13,1);
    lcd.print("OFF");
  }
}
