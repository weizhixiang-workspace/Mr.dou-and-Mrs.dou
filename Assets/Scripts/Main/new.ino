/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/
//-------------------------------------------  variables for signal 1------------------------------------------------
float voltage =  0;
float maxpulse=0;
float maxpulse1print=0;
int continouspulse=0;
int innercount=0;
// Threshold for signal 1 ---- needs to be changed depending on the person
float threshold1=2.5;   //medium
float threshold2=2.8;   // highest
float threshold3=2.3;  // lowest
float thresholdbelow=2.0;   // release th

//-------------------------------------------  variables for signal 2------------------------------------------------
float voltage2 = 0;
float maxpulse2=0;
float maxpulse1print2=0;
int continouspulse2=0;
int innercount2=0;
// Threshold for signal 1 ---- needs to be changed depending on the person
float threshold12=2.2;   //
float threshold22=2.4;
float threshold32=2;
float thresholdbelow2=1.8;


//-------------------------------------------  variables for signal 3------------------------------------------------

float voltage3 =0;
float maxpulse3=0;
float maxpulse1print3=0; 
int continouspulse3=0;  
int innercount3=0;  
// Threshold for signal 3 ---- needs to be changed depending on the person
float threshold13=2.5;   //medium
float threshold23=2.6;   // highest
float threshold33=2.3;  // lowest
float thresholdbelow3=2;   // release th

  
 //-------------------------------------------  variables for signal 4------------------------------------------------
float voltage4 = 0;
float maxpulse4=0;
float maxpulse1print4=0;
int continouspulse4=0;
int innercount4=0;
// Threshold for signal 4 ---- needs to be changed depending on the person
float threshold14=2.5;   //medium
float