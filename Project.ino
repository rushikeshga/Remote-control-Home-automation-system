#include <IRremote.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(7,8,9,10,11,12);
const int RECV_PIN=14;
IRrecv irrecv(RECV_PIN);
decode_results results;
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
bool i=true;
bool j=true;
bool k=true;
bool l=true;
bool m=true;
void setup()
{
 lcd.begin(16, 2);

  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  irrecv.enableIRIn();
  irrecv.blink13(true);
 
}
void loop() 
{
  if (irrecv.decode(&results)) 
   {
     Serial.println(results.value,HEX);
     delay(100);
     
     if(results.value==0xFD08F7)
     {
        
        digitalWrite(IN1, i);
       	
        lcd.clear();
       if(i==true){
        Serial.print("Fan is turned on");
        lcd.print("Fan is  on");
       }
       else{
         Serial.print("Fan is turned off");
        lcd.print("Fan is  off");
       }
       	i=!i;
        
     }
     
     if(results.value==0xFD8877)
     {
        
        digitalWrite(IN2, j);     	
        lcd.clear();
        if(j==true){
        Serial.print("Bulb is turned on");
        lcd.print("Bulb is  on");
       }
       else{
         Serial.print("Bulb is turned off");
        lcd.print("Bulb is  off");
       }
       	j=!j;
     }
     if(results.value==0xFD48B7)
     {
        digitalWrite(IN3, k);
        lcd.clear();
        if(k==true){
        Serial.print("AC is turned on");
        lcd.print("AC is  on");
       }
       else{
         Serial.print("AC is turned off");
        lcd.print("AC is  off");
       }
       	k=!k;
     }  
     
     if(results.value==0xFD28D7)
     {
        
        digitalWrite(IN4, l);
       
        lcd.clear();
        if(l==true){
        Serial.print("TV is turned on");
        lcd.print("TV is  on");
       }
       else{
         Serial.print("TV is turned off");
        lcd.print("TV is  off");
       }
       	l=!l;
     }
     
     if(results.value==0xFD00FF)
     {
        m=false;
        digitalWrite(IN1, m);
        digitalWrite(IN2, m);
        digitalWrite(IN3, m);
        digitalWrite(IN4, m);
        i=true;
		j=true;
		k=true;
		l=true;
        lcd.clear();
         lcd.print("ALL appliance off");
       // delay(200);
     }
     irrecv.resume(); 
     //delay(100);
   }
}
