#define RED 13
#define GREEN 12
#define BLUE 11
#define BUTTON 10
#define BUZZER 6 


#include <SoftwareSerial.h>

SoftwareSerial HC05(2, 3);
char Incoming_value = 0;
int buttonState = 0;

void setup()
{
  Serial.begin(9600);
  HC05.begin(9600);
  Serial.begin(9600);
  while (!Serial) {
    Serial.println("erreur") ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("bonjour") ;
  HC05.println("hello, word");
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{
  if (HC05.available() > 0)
  {
    Incoming_value = HC05.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
    if (Incoming_value == '0')
      digitalWrite(RED, HIGH);
    else if (Incoming_value == '1')
      digitalWrite(RED, LOW);


    if (Incoming_value == '2')
      digitalWrite(GREEN, HIGH);
    else if (Incoming_value == '3')
      digitalWrite(GREEN, LOW);



    if (Incoming_value == '4')
      digitalWrite(BLUE, HIGH);
    else if (Incoming_value == '5')
      digitalWrite(BLUE, LOW);







    if (Incoming_value == '6')
    {
      buttonState = digitalRead(BUTTON);
      if (buttonState == LOW)
      {
        while (buttonState == LOW)
        {
          tone (BUZZER,450);
          buttonState = digitalRead(BUTTON);
          digitalWrite(RED, HIGH);
          digitalWrite(GREEN, HIGH);
          digitalWrite(BLUE, HIGH);

          delay(1000);

          digitalWrite(RED, LOW);
          digitalWrite(GREEN, LOW);
          digitalWrite(BLUE, LOW);
        }
      }
    }
    else if (Incoming_value == '7')
      {noTone (BUZZER);}
      


  }
}
