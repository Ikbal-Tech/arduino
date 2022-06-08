#include <SoftwareSerial.h>
SoftwareSerial send_data(2,3);

//Fotodiyot pinleri 
int sensorPin0 = A0;
int sensorValue0 = 0; 
int sensorPin1 = A1;
int sensorValue1 = 0;
int sensorPin2 = A2;
int sensorValue2 = 0;
int sensorPin3 = A3;
int sensorValue3 = 0;
int sensorPin4 = A4;
int sensorValue4 = 0;
int sensorPin5 = A5;
int sensorValue5 = 0;
int sensorPin6 = A6;
int sensorValue6 = 0;
int sensorPin7 = A7;
int sensorValue7 = 0;
int sensorPin8 = A8;
int sensorValue8 = 0;
int sensorPin9 = A9;
int sensorValue9 = 0;
int sensorPin10 = A10;
int sensorValue10 = 0;
int sensorPin11 = A11;
int sensorValue11 = 0;
int sensorPin12 = A12;
int sensorValue12 = 0;
int sensorPin13 = A13;
int sensorValue13 = 0;
int sensorPin14 = A14;
int sensorValue14 = 0;

//Led pinleri 15 li seri halde
int LED1_15 = 4;

//Fotodiyotların okuduğu değerde sıkıntı çıkarsa maxı düşürüp test et
//maxtan büyük gelen değer max a yuvarlanır. Yüksek değerlerin sıkıntı
//çıkarmaması için önlem
int max=10000;

void setup()
{ 
  //Ledler output
  pinMode(LED1_15,OUTPUT);

  //Bluetooth veri çıkışları
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);

  //Fotodiyotlar input
  pinMode(sensorPin0, INPUT); 
  pinMode(sensorPin1, INPUT); 
  pinMode(sensorPin2, INPUT); 
  pinMode(sensorPin3, INPUT); 
  pinMode(sensorPin4, INPUT); 
  pinMode(sensorPin5, INPUT); 
  pinMode(sensorPin6, INPUT); 
  pinMode(sensorPin7, INPUT); 
  pinMode(sensorPin8, INPUT); 
  pinMode(sensorPin9, INPUT); 
  pinMode(sensorPin10, INPUT); 
  pinMode(sensorPin11, INPUT); 
  pinMode(sensorPin12, INPUT); 
  pinMode(sensorPin13, INPUT); 
  pinMode(sensorPin14, INPUT); 
 
  
  Serial.begin(9600);
  send_data.begin(9600);
}
void loop()
{
  //Ledleri yak
   digitalWrite(LED1_15, HIGH);
  
   digitalWrite(9, HIGH);
   digitalWrite(8, HIGH);
   
   //Fotodiyot değerlerini okuma
   sensorValue0 = analogRead(sensorPin0);
   sensorValue1 = analogRead(sensorPin1);
   sensorValue2 = analogRead(sensorPin2);
   sensorValue3 = analogRead(sensorPin3);
   sensorValue4 = analogRead(sensorPin4);
   sensorValue5 = analogRead(sensorPin5);
   sensorValue6 = analogRead(sensorPin6);
   sensorValue7 = analogRead(sensorPin7);
   sensorValue8 = analogRead(sensorPin8);
   sensorValue9 = analogRead(sensorPin9);
   sensorValue10 = analogRead(sensorPin10);
   sensorValue11 = analogRead(sensorPin11);
   sensorValue12 = analogRead(sensorPin12);
   sensorValue13 = analogRead(sensorPin13);
   sensorValue14 = analogRead(sensorPin14);
   
   delay(400);

   //Fotodiyot değerlerini yanyana yazdırma
   if(max<sensorValue0){
    sensorValue0=max;
    }
   Serial.print(sensorValue0);

   if(max<sensorValue1){
    sensorValue1=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue1);

   if(max<sensorValue2){
    sensorValue2=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue2);

   if(max<sensorValue3){
    sensorValue3=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue3);

   if(max<sensorValue4){
    sensorValue4=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue4);

   if(max<sensorValue5){
    sensorValue5=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue5);

   if(max<sensorValue6){
    sensorValue6=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue6);

   if(max<sensorValue7){
    sensorValue7=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue7);

   if(max<sensorValue8){
    sensorValue8=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue8);

   if(max<sensorValue9){
    sensorValue9=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue9);

   if(max<sensorValue10){
    sensorValue10=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue10);

   if(max<sensorValue11){
    sensorValue11=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue11);

   if(max<sensorValue12){
    sensorValue12=max;
    }
   Serial.print(" - "); 
   Serial.print(sensorValue12);

   if(max<sensorValue13){
    sensorValue13=max;
    }
   Serial.print(" - ");
   Serial.print(sensorValue13);

   if(max<sensorValue14){
    sensorValue14=max;
    }
   Serial.print(" - ");
   Serial.print(sensorValue14);
   Serial.println();
  
  if(Serial.available())
  {
    int data = Serial.read();
    send_data.print("Read data: "); 
    send_data.println(data);
    send_data.println("\n");
  }
 }
