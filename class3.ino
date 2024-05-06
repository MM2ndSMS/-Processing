# Processing  코드

import processing.serial.*;
Serial port;

PImage img; 
int i;

float[] ultrasonic_sensor = {0, 0, 0, 0};
int[] ultrasonic_sensor1 = new int [2];
String Serial_Data_String = null;

void setup() {
  size(700, 900);
  img=loadImage("C://SAE_CAR\\IMG//ultrasonic_sensor.png");
  port = new Serial(this, "com4", 115200);
}

void draw()
{
  background(255);
  image(img, 260, 400, 197, 98);
  display_ultrasonic_sensor_data();
}

void display_ultrasonic_sensor_data()
{
  if(ultrasonic_sensor1[0]<15);
  fill(0, 255, 0);
  rect(340, 400, 35, i--);
  //if(i <- 180) i= 0;
}

void serialEvent(Serial port)
{
  Serial_Data_String = port.readStringUntil('\n');
  
  if(Serial_Data_string ! = null
  {
    print("input data: ");
    print (Serial_Data_String) ;
    
   Serial_Data_String = trim(Serial_Data_String);
   String [] values = split(Serial_Data_String," ");
   
   if( (values.length == 4) && (values[0].indexOf('#')==0) && (values[3].indexOf('*')==0) )
   {
     print(values [0]) ;
     print(" ");
     print (values [1]);
     print(" ");
     print (values [3]) ;
     print(" \n");
     
     ultrasonic_sensor1[0] = int(values [1]);
     ultrasonic_sensor1[1] = int(values [2]);
   }
  }
}



# 아두이노 코드

int ultrasonic_data[2];

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:


  Serial.print("# ");                 // Start Byte
  Serial.print(ultrasonic_data[0]);     // Data Byte 
  Serial.print(" ");                 // Start Byte
  Serial.print(ultrasonic_data[1]);     // Data Byte 
  Serial.println(" *");               // End Byte  
  delay(500);
  ultrasonic_data[0]++;
  ultrasonic_data[1]+=2;
  
  if(ultrasonic_data[0]>180)  ultrasonic_data[0] =0;
  if(ultrasonic_data[1]>180)  ultrasonic_data[1] =0;
  
}
