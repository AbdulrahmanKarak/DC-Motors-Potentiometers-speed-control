const int sw_L = 1;  
const int sw_R = 2;  

const int pot_L = A0; 
const int pot_R = A1;

const int DCmotor_L = 3;
const int DCmotor_R = 5;


int inDC_L;
int inDC_R;
int outDC_L;
int outDC_R;


char reading = 'x';

void setup()
{
  pinMode(sw_L, INPUT);
  pinMode(sw_R, INPUT);

  pinMode(pot_R, INPUT);
  pinMode(pot_L, INPUT);

  pinMode(DCmotor_L, OUTPUT); 
  pinMode(DCmotor_R, OUTPUT); 
  
  Serial.begin(9600); 
  

}

void loop()
{
 
 inDC_L = analogRead(pot_L);
 inDC_R = analogRead(pot_R);
  
   outDC_L = map(inDC_L, 0, 1023, 0, 255);
   outDC_R = map(inDC_R, 0, 1023, 0, 255);
  
   reading=Serial.read();
  

  if(digitalRead(sw_L) || reading == 'L' )

  {
       analogWrite(DCmotor_L, outDC_L);
       Serial.print("outDC_L = ");
       Serial.println(outDC_L);
       delay(1000);
     
  }
 else if(digitalRead(sw_R) || reading == 'R')
  {
    analogWrite(DCmotor_R, outDC_R);
    Serial.print("outDC_R = ");
    Serial.println(outDC_R);
    delay(1000);
    while(Serial.read() == 'L');

  }
  
 else if (digitalRead(sw_L) || digitalRead(sw_R) || reading == 'S')
   {
     analogWrite(DCmotor_L, 0 );
     analogWrite(DCmotor_R, 0);
   }
 else 
   {
   Serial.println(" Open the switch");delay(2000);
   }
                                          

  
}
                    



