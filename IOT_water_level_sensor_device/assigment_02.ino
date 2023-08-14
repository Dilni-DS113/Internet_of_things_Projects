// Setting Led pins to correct values 
const int greenPin = 2; 
const int yellowPin = 3; 
const int redPin = 4 ;

void setup() {
  Serial.begin(9600);
pinMode(greenPin , OUTPUT);
pinMode (yellowPin,OUTPUT);
pinMode(redPin,OUTPUT);

}

void loop() {
  //Setting the water level sensor pin(Potentiometer) 
  int waterLevelsensorpin  = analogRead(A2); 
  
if(waterLevelsensorpin >= 0 && waterLevelsensorpin < 150) // Fisrt condition: Is the water level in the range of 0-150ml  
{                                                             // --> yes then water level in safe level 
  for(int i = 0; i<=7;i++)   // looping LED to crating blinking     // --> NO --> fisrt condtion false 
  {
    digitalWrite(greenPin,HIGH);
   delay(100); 
    digitalWrite(greenPin,LOW);
  } 
   Serial.print(waterLevelsensorpin);
   Serial.println(" Appropriate water level");
delay(100); 
}

else if (waterLevelsensorpin >= 150 && waterLevelsensorpin < 250) // Second condition: Is the water level in the range of 150-249ml
{                                                                     // --> yes  then water level is becoming unsafe level 
  for(int i = 0; i<=7;i++) // looping LED to crating blinking           // --> NO --> second condition fasle  
  {                                                                        
    digitalWrite(yellowPin,HIGH); 
   delay(100); 
    digitalWrite(yellowPin,LOW);
  } 
   Serial.print(waterLevelsensorpin);
   Serial.println(" Concerning water level");
delay(100); 
}

else if(waterLevelsensorpin >= 250 && waterLevelsensorpin < 500) // Third condition: Is the water level in the range of 250-499ml
{                                                                    // --> yes then water level is unsafe level
  for(int i = 0; i<=7;i++) // looping LED to crating blinking           // --> NO --> third condition flase
  {
    digitalWrite(redPin,HIGH); 
   delay(100); 
    digitalWrite(redPin,LOW);
  } 
   Serial.print(waterLevelsensorpin);
   Serial.println(" Dangers water level");
delay(100); 
}

else // IF the water level is higer than 500 this else function will excute 
{
  for(int i = 0; i<=7;i++)// This loop casues a faster blink as everything is togther 
  {
  digitalWrite(redPin,HIGH);
  delay(100); 
    digitalWrite(redPin,LOW);
    Serial.print(waterLevelsensorpin); 
    Serial.println(" WARNING"); 
  delay(100); 
  }
}
        }
