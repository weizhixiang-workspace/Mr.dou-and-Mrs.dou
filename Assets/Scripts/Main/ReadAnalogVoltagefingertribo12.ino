/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/
float valant=0;
float valant3=0;
float maxpulse=0;
float maxpulse2=0;
float maxpulse2print=0;
float maxpulse1print=0;
float continouspulse=0;
float continouspulse2=0;
float valant2=5;
float valant4=5;
float measurement=0;
float measurement2=0;

//-------------------------------------------
float threshold11=2.2;   //
float threshold21=2.4;
float threshold31=2;
float thresholdbelow1=1.8;


// this is where you change the thershold     --- dont mind the numeration   this is what you need to change---- for your tribo may be different 
float mediumThreshold=2.5;   //medium
float highestThreshold=2.8;   // highest
float lowestThreshold=2.3;  // lowest
float thresholdbelow=2;   // release th



int innercount=0;
int outtercount=0;
int innercount2=0;
int outtercount2=0;
  double time1=millis();
  double time2=time1;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  
  
	time2=millis();
	int sensorValue  = analogRead(A0);
	int sensorValue2 = analogRead(A4);
	int sensorValue3 = analogRead(A1);
	int sensorValue4 = analogRead(A2);

	  
	// Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
	float voltage =  sensorValue  * (5.0 / 1023.0);
	float voltage2 = sensorValue2 * (5.0 / 1023.0);
	float voltage3 = sensorValue3 * (5.0 / 1023.0);
	float voltage4 = sensorValue4 * (5.0 / 1023.0);
 
	if(innercount == 0)//初始时进入
	{
		if(voltage>lowestThreshold)
		{
			innercount++;
			maxpulse=lowestThreshold;
			maxpulse1print=0;
			continouspulse=0;
		}
	}


	if(innercount==1)
	 {
	   if(voltage>maxpulse)
		{
			maxpulse=voltage;
			maxpulse1print=maxpulse;
		}
		else
		{
			if(maxpulse>lowestThreshold && maxpulse<mediumThreshold)
			{
				maxpulse1print=maxpulse1print;
				continouspulse=1;
			}
			else if(maxpulse>mediumThreshold && maxpulse<highestThreshold)
			{
	 
				maxpulse1print=maxpulse1print;
				continouspulse=1;
			}
			else if(maxpulse>highestThreshold )
			{
				maxpulse1print=maxpulse1print;
				continouspulse=2;
			}
			else
			{
				maxpulse=0;
				maxpulse1print=0;
	  
			}


		}

		
		if(voltage<lowestThreshold)
		{
			outtercount++;
			maxpulse=lowestThreshold;
			maxpulse1print=0;
		}

		if(voltage<thresholdbelow)
		{
	 
			outtercount++;
			innercount--;
			maxpulse=lowestThreshold;
			maxpulse1print=0;
			continouspulse=0;
		}
	  
	}


 
	if(innercount2 == 0)
	{
		if(voltage2>threshold31)
		{
			innercount2++;
			maxpulse2=threshold31;
			maxpulse2print=0;
			continouspulse2=10;
		}
	}


	if(innercount2==1)
	{
		if(voltage2>maxpulse2)
		{
			maxpulse2=voltage2;
			maxpulse2print=maxpulse2;
		}
		else
		{

			if(maxpulse2>threshold31 && maxpulse2<threshold11)
			{
			  
				maxpulse2print=maxpulse2print;
			  
			}else if(maxpulse2>threshold11 && maxpulse2<threshold21)
			{
				maxpulse2print=maxpulse2print;
				continouspulse2=11;
			
			}else if(maxpulse2>threshold21 )
			{
				maxpulse2print=maxpulse2print;
				continouspulse2=12;
		
			}else
			{
				maxpulse2=0;
				maxpulse2print=0;
			
			}
		}

    
		if(voltage2<threshold31)
		{
			outtercount2++;
			maxpulse2=threshold31;
			maxpulse2print=0;
		}

		if(voltage2<thresholdbelow1)
		{
			outtercount2++;
			innercount2--;
			maxpulse2=threshold31;
			maxpulse2print=0;
			continouspulse2=10;
	  
		}
  
	}




// thesholdprinting  ------------------------------------ this is not necessary to be sent to unity
Serial.print(mediumThreshold);
Serial.print(",");
Serial.print(highestThreshold);
Serial.print(",");
Serial.print(threshold3);
Serial.print(",");

// this is the angle this goes to unity   00 0 degree    01 low degree 02 high degree, you will see 0 or 1 or two in serial plotter output
Serial.print(continouspulse);
Serial.print(",");  

//-------------------------------------------------
//Serial.print(maxpulse1print);
//Serial.print(",");



//Serial.print(threshold11);
//Serial.print(",");
//Serial.print(threshold21);
//Serial.print(",");
//Serial.println(threshold31);
//Serial.print(",");
//Serial.print(continouspulse2);
//Serial.print(",");

 
//Serial.print(maxpulse2print);
//Serial.print(",");  


Serial.println(voltage);
//Serial.print(",");
//Serial.print(voltage2);
//Serial.println(",");  
//Serial.print(voltage3);
//Serial.print(",");
//Serial.println(voltage4);


  


  

//   Serial.print(",");
//  Serial.println((valant+valant2));
//  Serial.println(valant);
//  for (int i=1;i<6;i++){
//  delay(100);
//   Serial.println(valant);
//  }
//   Serial.println(valant2);
//  for (int i=1;i<6;i++){
//  delay(100);
//   Serial.println(valant2);
//  }
  
//   valant=sensorValue;
//delay(5);
}
