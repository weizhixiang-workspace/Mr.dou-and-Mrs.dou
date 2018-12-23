void setup() {
  Serial.begin(9600);
 //   pinMode(A0,INPUT_PULLUP);
  // put your setup code here, to run once:
}

void loop() {
  int sensorValue0 = analogRead(A0);
  delay(3);
  sensorValue0 = analogRead(A0);
  delay(3);
  float voltage0 = sensorValue0 * (5.0/1023.0)*10;
  
  int sensorValue1 = analogRead(A1);
  delay(3);
  sensorValue1 = analogRead(A1);
  delay(3);
  float voltage1 = sensorValue1 *(5.0/1023.0)*10;

  int sensorValue2 = analogRead(A2);
  delay(3);
  sensorValue2 = analogRead(A2);
  delay(3);
  float voltage2 = sensorValue2 *(5.0/1023.0)*10;

  int sensorValue3 = analogRead(A3);
  delay(3);
  sensorValue3 = analogRead(A3);
  delay(3);
  float voltage3 = sensorValue3 *(5.0/1023.0)*10;
//  
//  if (voltage0 < 15)
//  {
//  Serial.print(2);
//  }
//  else if (voltage0 > 20)
//  {
//    Serial.print(1);
//    }
//    
//   if (voltage1 < 20)
//{
//  Serial.print(3);
//  }
//  else if(voltage1 > 28)
//  {
//    Serial.print(4);
//    }

  Serial.print(voltage0);
  Serial.print(",");
  Serial.print(voltage1);
  Serial.print(",");
  Serial.print(voltage2);
  Serial.print(",");
  Serial.println(voltage3);

  

  // put your main code here, to run repeatedly:

}
