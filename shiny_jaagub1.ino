char reading;

void setup()
{
  Serial.begin(9600);
  pinMode(2,0);
  pinMode(3,0);
}

void loop()
{
  if(Serial.available()>0)
  reading = Serial.read();
   analogWrite(10,(digitalRead(3)||reading == 'R')*(analogRead(A0)/4));
   analogWrite(9,(digitalRead(2)||reading == 'L')*(analogRead(A1)/4))
     }
                    
