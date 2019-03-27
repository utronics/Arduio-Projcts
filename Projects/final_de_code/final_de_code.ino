#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String inData;
#define m11 7    // rear motor
#define m12 8
#define m21 9    // front motor
#define m22 10
char str[2],i;
void forward()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void backward()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, HIGH);
   digitalWrite(m21, LOW);
   digitalWrite(m22, HIGH); 
}
void right()
{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, HIGH);
   digitalWrite(m22, LOW);
}
void left()
{
   digitalWrite(m11, HIGH);
   digitalWrite(m12, LOW);
   delay(100);
   digitalWrite(m21, LOW );
   digitalWrite(m22, LOW);
}
void Stop()

{
   digitalWrite(m11, LOW);
   digitalWrite(m12, LOW);
   digitalWrite(m21, LOW);
   digitalWrite(m22, LOW);
}

void setup() 
{
  Serial.begin(9600);       
    lcd.begin(16, 2);
   }
void loop() 
{
 int i=0;
  //lcd.setCursor(0, 0);
 lcd.print("design eng... ");
  //
lcd.setCursor(0, 1);
lcd.print("hi,i'm robotooth");
  char commandbuffer[100];

  if(Serial.available())
{
     delay(100);
     while( Serial.available() && i< 99) 
     {
        commandbuffer[i++] = Serial.read();
     }
     commandbuffer[i++]='\0';
  }

  if(i>0)

     Serial.println((char*)commandbuffer);
     lcd.print((char*)commandbuffer);
     delay(1000);
     lcd.clear();
{
  Serial.begin(9600);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
}
  while(Serial.available())
  {
    char ch=Serial.read();
    str[i++]=ch;
    
    if(str[i-1]=='1')
    {
     Serial.println("Forward");
     forward();
     i=0;
    }
    else if(str[i-1]=='2')
    {
     Serial.println("right");
     left();
     i=0;
    }
    else if(str[i-1]=='3')
    {
      Serial.println("backward");
      backward();
      i=0;
    }
    
    else if(str[i-1]=='4')
    {
      Serial.println("left");
      right();
      i=0;
    }
    else if(str[i-1]=='5')
    {
      Serial.println("Stop");
      Stop();
      i=0;
    }
    delay(100);
  }
}


