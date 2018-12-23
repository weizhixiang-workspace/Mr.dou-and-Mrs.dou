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
float threshold24=2.5;   // highest
float threshold34=2.1;  // lowest
float thresholdbelow4=1.8;   // release th



//-------------------------------------------  variables for signal 5------------------------------------------------
float voltage5 = 0;
float maxpulse5=0;
float maxpulse1print5=0;
float continouspulse5=0;
int innercount5=0;
// Threshold for signal 5 ---- needs to be changed depending on the person
float threshold15=2.5;   //medium
float threshold25=2.8;   // highest
float threshold35=2.3;  // lowest
float thresholdbelow5=2;   // release th



//-------------------------------------------  variables for signal 6------------------------------------------------
float voltage6 = 0;
float maxpulse6=0;
float maxpulse1print6=0;
float continouspulse6=0;
int innercount6=0;
// Threshold for signal 4 ---- needs to be changed depending on the person
float threshold16=2.5;   //medium
float threshold26=2.8;   // highest
float threshold36=2.3;  // lowest
float thresholdbelow6=2;   // release th


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  

  int sensorValue  = analogRead(A0);//shizhi
  int sensorValue2 = analogRead(A4);
  int sensorValue3 = analogRead(A1);//zhongzhi
  int sensorValue4 = analogRead(A2);//wumingzhi
  int sensorValue5 = analogRead(A3);
  int sensorValue6 = analogRead(A5);

  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
 voltage =  sensorValue  * (5.0 / 1023.0);
 voltage2 = sensorValue2 * (5.0 / 1023.0);
 voltage3 = sensorValue3 * (5.0 / 1023.0);
 voltage4 = sensorValue4 * (5.0 / 1023.0);
 voltage5 = sensorValue5 * (5.0 / 1023.0);
 voltage6 = sensorValue6 * (5.0 / 1023.0);
  

//detectionfunction(voltage,2.5,2.8,2.3,1.8);


//-------------------------------------------------------- Detection and pre-processing of voltage 1---------------------------------------------------------
if(innercount == 0){
  if(voltage>threshold3){
    innercount++;
    maxpulse=threshold3;
    maxpulse1print=0;
    continouspulse=0;
  }
}


if(innercount==1){
   if(voltage>maxpulse){
      maxpulse=voltage;
      maxpulse1print=maxpulse;
   }else{

      if(maxpulse>threshold3 && maxpulse<threshold1){
          maxpulse1print=maxpulse1print;
          continouspulse=1;
         
        }else if(maxpulse>threshold1 && maxpulse<threshold2){
          
           maxpulse1print=maxpulse1print;
           continouspulse=1;
        }else if(maxpulse>threshold2 ){
        
           maxpulse1print=maxpulse1print;
           continouspulse=2;
        }else{
           maxpulse=0;
           maxpulse1print=0;  
        }
    }

if(voltage<threshold3){
    maxpulse=threshold3;
    maxpulse1print=0;
    }

if(voltage<thresholdbelow){
   innercount--;
    maxpulse=threshold3;
    maxpulse1print=0;
    continouspulse=0;
}
  
  }






//-------------------------------------------------------- Detection and pre-processing of voltage 2---------------------------------------------------------
if(innercount2 == 0){
  if(voltage2>threshold32){
    innercount2++;
    maxpulse2=threshold32;
    maxpulse1print2=0;
    continouspulse2=0;
  }
}


if(innercount2==1){
   if(voltage2>maxpulse2){
      maxpulse2=voltage2;
      maxpulse1print2=maxpulse2;
   }else{

      if(maxpulse2>threshold32 && maxpulse2<threshold12){
          maxpulse1print2=maxpulse1print2;
          continouspulse2=1;
         
        }else if(maxpulse2>threshold12 && maxpulse2<threshold22){
          
           maxpulse1print2=maxpulse1print2;
           continouspulse2=1;
        }else if(maxpulse2>threshold22 ){
        
           maxpulse1print2=maxpulse1print2;
           continouspulse2=2;
        }else{
           maxpulse2=0;
           maxpulse1print2=0;  
        }
    }

if(voltage2<threshold32){
    maxpulse2=threshold32;
    maxpulse1print2=0;
    }

if(voltage2<thresholdbelow2){
   innercount2--;
    maxpulse2=threshold32;
    maxpulse1print2=0;
    continouspulse2=0;
}
  
  }


//-------------------------------------------------------- Detection and pre-processing of voltage 3---------------------------------------------------------
if(innercount3 == 0){
  if(voltage3>threshold33){
    innercount3++;
    maxpulse3=threshold33;
    maxpulse1print3=0;
    continouspulse3=0;
  }
}


if(innercount3==1){
   if(voltage3>maxpulse3){
      maxpulse3=voltage3;
      maxpulse1print3=maxpulse3;
   }else{

      if(maxpulse3>threshold33 && maxpulse3<threshold13){
          maxpulse1print3=maxpulse1print3;
          continouspulse3=1;
         
        }else if(maxpulse3>threshold13 && maxpulse3<threshold23){
          
           maxpulse1print3=maxpulse1print3;
           continouspulse3=1;
        }else if(maxpulse3>threshold23 ){
        
           maxpulse1print3=maxpulse1print3;
           continouspulse3=2;
        }else{
           maxpulse3=0;
           maxpulse1print3=0;  
        }
    }

if(voltage3<threshold33){
    maxpulse3=threshold33;
    maxpulse1print3=0;
    }

if(voltage3<thresholdbelow3){
   innercount3--;
    maxpulse3=threshold33;
    maxpulse1print3=0;
    continouspulse3=0;
}
  
  }




//-------------------------------------------------------- Detection and pre-processing of voltage 4---------------------------------------------------------
if(innercount4 == 0){
  if(voltage4>threshold34){
    innercount4++;
    maxpulse4=threshold34;
    maxpulse1print4=0;
    continouspulse4=0;
  }
}


if(innercount4==1){
   if(voltage4>maxpulse4){
      maxpulse4=voltage4;
      maxpulse1print4=maxpulse4;
   }else{

      if(maxpulse4>threshold34 && maxpulse4<threshold14){
          maxpulse1print4=maxpulse1print4;
          continouspulse4=1;
         
        }else if(maxpulse4>threshold14 && maxpulse4<threshold24){
          
           maxpulse1print4=maxpulse1print4;
           continouspulse4=1;
        }else if(maxpulse4>threshold24 ){
        
           maxpulse1print4=maxpulse1print4;
           continouspulse4=2;
        }else{
           maxpulse4=0;
           maxpulse1print4=0;  
        }
    }

if(voltage4<threshold34){
    maxpulse4=threshold34;
    maxpulse1print4=0;
    }

if(voltage4<thresholdbelow4){
   innercount4--;
    maxpulse4=threshold34;
    maxpulse1print4=0;
    continouspulse4=0;
}
  
  }



//-------------------------------------------------------- Detection and pre-processing of voltage 5---------------------------------------------------------
if(innercount5 == 0){
  if(voltage5>threshold35){
    innercount5++;
    maxpulse5=threshold35;
    maxpulse1print5=0;
    continouspulse5=0;
  }
}


if(innercount5==1){
   if(voltage5>maxpulse5){
      maxpulse5=voltage5;
      maxpulse1print5=maxpulse5;
   }else{

      if(maxpulse5>threshold35 && maxpulse5<threshold15){
          maxpulse1print5=maxpulse1print5;
          continouspulse5=1;
         
        }else if(maxpulse5>threshold15 && maxpulse5<threshold25){
          
           maxpulse1print5=maxpulse1print5;
           continouspulse5=1;
        }else if(maxpulse5>threshold25 ){
        
           maxpulse1print5=maxpulse1print5;
           continouspulse5=2;
        }else{
           maxpulse5=0;
           maxpulse1print5=0;  
        }
    }

if(voltage5<threshold35){
    maxpulse5=threshold35;
    maxpulse1print5=0;
    }

if(voltage5<thresholdbelow5){
   innercount5--;
    maxpulse5=threshold35;
    maxpulse1print5=0;
    continouspulse5=0;
}
  
  }


//-------------------------------------------------------- Detection and pre-processing of voltage 6---------------------------------------------------------
if(innercount6 == 0){
  if(voltage6>threshold36){
    innercount6++;
    maxpulse6=threshold36;
    maxpulse1print6=0;
    continouspulse6=0;
  }
}


if(innercount6==1){
   if(voltage6>maxpulse6){
      maxpulse6=voltage6;
      maxpulse1print6=maxpulse6;
   }else{

      if(maxpulse6>threshold36 && maxpulse6<threshold16){
          maxpulse1print6=maxpulse1print6;
          continouspulse6=1;
         
        }else if(maxpulse6>threshold16 && maxpulse6<threshold26){
          
           maxpulse1print6=maxpulse1print6;
           continouspulse6=1;
        }else if(maxpulse6>threshold26 ){
        
           maxpulse1print6=maxpulse1print6;
           continouspulse6=2;
        }else{
           maxpulse6=0;
           maxpulse1print6=0;  
        }
    }

if(voltage6<threshold36){
    maxpulse6=threshold36;
    maxpulse1print6=0;
    }

if(voltage6<thresholdbelow6){
   innercount6--;
    maxpulse6=threshold36;
    maxpulse1print6=0;
    continouspulse6=0;
}
  
  }












// 
//if(innercount2 == 0){
//if(voltage2>threshold31){
//    innercount2++;
// maxpulse2=threshold31;
//  maxpulse2print=0;
//   continouspulse2=10;
//    }
//}
//
//
// if(innercount2==1){
//   if(voltage2>maxpulse2){
//    maxpulse2=voltage2;
//    maxpulse2print=maxpulse2;
//
//    }else{
//
//if(maxpulse2>threshold31 && maxpulse2<threshold11){
//  
// maxpulse2print=maxpulse2print;
//   continouspulse2=11;
//   
//  }else if(maxpulse2>threshold11 && maxpulse2<threshold21){
//  maxpulse2print=maxpulse2print;
//  continouspulse2=11;
//
//  }else if(maxpulse2>threshold21 ){
//  maxpulse2print=maxpulse2print;
//  continouspulse2=12;
//
//  }else{
//maxpulse2=0;
//       maxpulse2print=0;
//
//  }
//
//
//    }
//
//    
//  if(voltage2<threshold31){
//
//    outtercount2++;
//
//        maxpulse2=threshold31;
//  maxpulse2print=0;
//    }
//
//    if(voltage2<thresholdbelow1){
//       innercount2--;
//        maxpulse2=threshold31;
//  maxpulse2print=0;
//  continouspulse2=10;
//  
//    }
//  
//  }
//
//
//if(innercount3 == 0){
//if(voltage3>threshold33){
//    innercount3++;
// maxpulse3=threshold33;
//    maxpulse1print3=0;
//    continouspulse3=0;
//    }
//}
//
//
// if(innercount3==1){
//   if(voltage3>maxpulse3){
//    maxpulse3=voltage3;
//       maxpulse1print3=maxpulse3;
//     //   continouspulse=maxpulse;
//    }else{
//
//if(maxpulse3>threshold3 && maxpulse3<threshold1){
//   maxpulse1print3=maxpulse1print3;
//    continouspulse3=1;
//   
//  }else if(maxpulse3>threshold13 && maxpulse<threshold23){
//    
//     maxpulse1print3=maxpulse1print3;
//      continouspulse=13;
//  }else if(maxpulse3>threshold23 ){
//  
//     maxpulse1print3=maxpulse1print3;
//     continouspulse3=2;
//  }else{
//   maxpulse3=0;
//   maxpulse1print3=0;  
//  }
//    }
//
//    
//  if(voltage3<threshold33){
//        maxpulse3=threshold33;
//    maxpulse1print3=0;
//    }
//
//    if(voltage3<thresholdbelow3){
//       innercount3--;
//        maxpulse3=threshold33;
//        maxpulse1print3=0;
//        continouspulse3=0;
//    }
//  
//  }
//


//
//if(innercount4 == 0){
//if(voltage4>threshold34){
//    innercount4++;
// maxpulse4=threshold34;
//    maxpulse1print4=0;
//    continouspulse4=0;
//    }
//}
//
//
// if(innercount4==1){
//   if(voltage4>maxpulse4){
//    maxpulse4=voltage4;
//       maxpulse1print4=maxpulse4;
//     //   continouspulse=maxpulse;
//    }else{
//
//if(maxpulse4>threshold34 && maxpulse4<threshold14){
//   maxpulse1print4=maxpulse1print4;
//    continouspulse4=1;
//   
//  }else if(maxpulse4>threshold14 && maxpulse4<threshold24){
//    
//     maxpulse1print4=maxpulse1print4;
//      continouspulse=14;
//  }else if(maxpulse4>threshold24 ){
//  
//     maxpulse1print4=maxpulse1print4;
//     continouspulse4=2;
//  }else{
//   maxpulse4=0;
//   maxpulse1print4=0;  
//  }
//    }
//
//    
//  if(voltage4<threshold34){
//        maxpulse4=threshold34;
//    maxpulse1print3=0;
//    }
//
//    if(voltage4<thresholdbelow4){
//       innercount4--;
//        maxpulse4=threshold34;
//        maxpulse1print4=0;
//        continouspulse4=0;
//    }
//  
//  }
//
//







 //--------------------------------------------------------Debug Prints---------------------------------





 //-------------------------------------------------PRINT Thresholds for Finger 1----------------------------------------
//Serial.print(threshold1);
//Serial.print(",");
//Serial.print(threshold2);
//Serial.print(",");
//Serial.print(threshold3);
//Serial.print(",");
//Serial.print(thresholdbelow);
//Serial.print(",");
//---------------------------------------------------Print Result for Finger 1 -----------------------------------------
//Serial.print(continouspulse);
//Serial.print(",");  
//Serial.print(maxpulse1print);
//Serial.print(",");



////
////-------------------------------------------------PRINT Thresholds for Finger 2----------------------------------------
////Serial.print(threshold11);
////Serial.print(",");
//Serial.print(threshold12);
//Serial.print(",");
//Serial.print(threshold13);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 2 -----------------------------------------
//Serial.print(continouspulse2);
//Serial.print(",");


////
////-------------------------------------------------PRINT Thresholds for Finger 3----------------------------------------
////Serial.print(threshold13);
////Serial.print(",");
//Serial.print(threshold23);
//Serial.print(",");
//Serial.print(threshold33);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 3 -----------------------------------------
//Serial.print(continouspulse3);
//Serial.print(",");  

// //-------------------------------------------------PRINT Thresholds for Finger 4----------------------------------------
////Serial.print(threshold1);
////Serial.print(",");
//Serial.print(threshold24);
//Serial.print(",");
//Serial.print(threshold34);
//Serial.print(",");
//Serial.print(thresholdbelow4);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 4 -----------------------------------------
//Serial.print(continouspulse4);
//Serial.print(",");  
////Serial.print(maxpulse1print);
////Serial.print(",");


//// //-------------------------------------------------PRINT Thresholds for Finger 1----------------------------------------
////Serial.print(threshold15);
////Serial.print(",");
//Serial.print(threshold25);
//Serial.print(",");
//Serial.print(threshold35);
//Serial.print(",");
//Serial.print(thresholdbelow5);
//Serial.print(",");
////---------------------------------------------------Print Result for Finger 1 -----------------------------------------
//Serial.print(continouspulse5);
//Serial.print(",");  
////Serial.print(maxpulse1print5);
////Serial.print(",");



 //-------------------------------------------------PRINT Thresholds for Finger 6----------------------------------------
//Serial.print(threshold16);
//Serial.print(",");
//Serial.print(threshold26);
//Serial.print(",");
//Serial.print(threshold36);
//Serial.print(",");
//Serial.print(thresholdbelow6);
//Serial.print(",");
//////---------------------------------------------------Print Result for Finger 1 -----------------------------------------
//Serial.print(continouspulse6);
//Serial.print(",");  
////Serial.print(maxpulse1print6);
////Serial.print(",");




Serial.println(String(continouspulse)+String(continouspulse2)+String(continouspulse3)+String(continouspulse4));


//Serial.println(voltage);
//Serial.print(",");
//Serial.print(voltage2);
//Serial.print(",");  
//Serial.print(voltage3);
//Serial.print(",");
//Serial.println(voltage4);




}




//float detectionfunction(float voltage,float threshold1,float threshold2,float threshold3,float thresholdbelow){
//
//
//  
//if(innercount == 0){
//  if(voltage>threshold3){
//    innercount++;
//    maxpulse=threshold3;
//    maxpulse1print=0;
//    continouspulse=0;
//  }
//}
//
//
//if(innercount==1){
//   if(voltage>maxpulse){
//      maxpulse=voltage;
//      maxpulse1print=maxpulse;
//   }else{
//
//      if(maxpulse>threshold3 && maxpulse<threshold1){
//          maxpulse1print=maxpulse1print;
//          continouspulse=1;
//         
//        }else if(maxpulse>threshold1 && maxpulse<threshold2){
//          
//           maxpulse1print=maxpulse1print;
//           continouspulse=1;
//        }else if(maxpulse>threshold2 ){
//        
//           maxpulse1print=maxpulse1print;
//           continouspulse=2;
//        }else{
//           maxpulse=0;
//           maxpulse1print=0;  
//        }
//    }
//
//if(voltage<threshold3){
//    maxpulse=threshold3;
//    maxpulse1print=0;
//    }
//
//if(voltage<thresholdbelow){
//   innercount--;
//    maxpulse=threshold3;
//    maxpulse1print=0;
//    continouspulse=0;
//}
//  
//  }
//
//return continouspulse;
//
//  
//  }
