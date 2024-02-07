
const int motor1 = 5;
const int motor2 = 3;
const int pot1 = A1;
const int pot2 = A0;
const int switch1 = 2;
const int switch2 = 1;
int Reading1 = 0;
int Reading2 = 0;
int Motorvalue1 = 0;
int Motorvalue2 = 0;
int krk1 =0;
int krk2 =0;



void setup()
{
  pinMode(A0 , INPUT );
  pinMode(A1 , INPUT );
  pinMode( 1 , INPUT );
  pinMode( 2 , INPUT );
  pinMode( 3 , OUTPUT );
  pinMode( 5 , OUTPUT );
  Serial.begin(9600);
}

void loop() 
{
  Reading1 = digitalRead(switch1);
  Reading2 = digitalRead(switch2);
  if( Reading1 == HIGH)
  {
    Motorvalue1 = analogRead(pot1);
    digitalWrite( 5 , HIGH);
    delay(Motorvalue1);
    digitalWrite( 5 , LOW);
    delay(Motorvalue1);
    Serial.write(Motorvalue1);
  }
  
  
  else if( Reading2 == HIGH)
  {
    Motorvalue2 = analogRead(pot1);
    digitalWrite( 3 , HIGH);
    delay(Motorvalue2);
    digitalWrite( 3 , LOW);
    delay(Motorvalue2);
  }
  
  if( Reading1 == HIGH && Reading2 == HIGH)
  {
    Motorvalue1 = analogRead(pot1);
    digitalWrite( 5 , HIGH);
    delay(Motorvalue1);
    digitalWrite( 5 , LOW);
    delay(Motorvalue1);
    Motorvalue2 = analogRead(pot1);
    digitalWrite( 3 , HIGH);
    delay(Motorvalue2);
    digitalWrite( 3 , LOW);
    delay(Motorvalue2);
  }
  
  else
  {
    digitalWrite( 5 , LOW);
    digitalWrite( 3 , LOW);
  }
  
}
