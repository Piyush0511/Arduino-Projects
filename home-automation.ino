#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String a;
char buf[5];

void dooropen()
{
  digitalWrite(10, 0);
}
void doorclose()
{
  digitalWrite(10, 1);
}

void doora()
{
  dooropen();
  delay(500);
  doorclose();
  delay(500);
}
void doorb()
{
  dooropen();
  delay(500);
  doorclose();
  delay(500);
}
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(115200); // opens serial port, sets data rate to 9600 bps
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  digitalWrite(9, 1);
  digitalWrite(10, 1);
}

void loop() {

  while (Serial.available())
  {

    a = Serial.readString(); // read the incoming data as string
    Serial.println(a);
    //a.toCharArray(buf, 3);
    Serial.println(a[1]);
    lcd.clear();
    if (a[0] == 's')
    {
      if (a[2] == 'e')
      {
        if (a[1] == 'a')
        {
          lcd.clear();
          Serial.println("Bulb 1 ON");
          digitalWrite(6, 0);
          lcd.print("Bulb 1 ON");
        }
        else  if (a[1] == 'b')
        {
          lcd.clear();
          Serial.println("Bulb 2 ON");
          digitalWrite(7, 0);
          lcd.print("Bulb 2 ON");
        }
        else if (a[1] == 'c')
        {
          lcd.clear();
          Serial.println("Bulb 3 ON");
          digitalWrite(8, 0);
          lcd.print("Bulb 3 ON");
        }
        else if (a[1] == 'd')
        {
          lcd.clear();
          Serial.println("Fan ON");
          digitalWrite(9, 0);
          lcd.print("Fan ON");
        }
        else if (a[1] == 'e')
        {
          lcd.clear();
          Serial.println("Door Open");
          // digitalWrite(10, 0);//
          lcd.print("Door Open");
          doora();
        }
        else if (a[1] == 'f')
        {
          lcd.clear();
          Serial.println("Bulb 1 OFF");
          digitalWrite(6, 1);
          lcd.print("Bulb 1 OFF");
        }
        else if (a[1] == 'g')
        {
          lcd.clear();
          Serial.println("Bulb 2 OFF");
          digitalWrite(7, 1);
          lcd.print("Bulb 2 OFF");
        }
        else if (a[1] == 'h')
        {
          lcd.clear();
          Serial.println("Bulb 3 OFF");
          digitalWrite(8, 1);
          lcd.print("Bulb 8 OFF");
        }
        else if (a[1] == 'i')
        {
          lcd.clear();
          Serial.println("Fan OFF");
          digitalWrite(9, 1);
          lcd.print("Fan OFF");
        }
        else if (a[1] == 'j')
        {
          lcd.clear();
          Serial.println("Door Close");
          //digitalWrite(10, 1);//
          lcd.print("Door Close");
          doorb();
        }
        else if (a[1] == 'k')
        {
          lcd.clear();
          Serial.println("intruder");
          digitalWrite(13, 1);
          delay(1000);
          lcd.print("intruder");
        }
      }
      else if (a[1] == 'l')
      {
        lcd.clear();
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
        lcd.print("All r on");
      }
      else if (a[1] == 'm')
      {
        lcd.clear();
        digitalWrite(6, 1);
        digitalWrite(7, 1);
        digitalWrite(8, 1);
        digitalWrite(9, 1);
        lcd.print("All r off");
      }
      else if (a[1] == 'o')
      {

      }

    }
  }

}

