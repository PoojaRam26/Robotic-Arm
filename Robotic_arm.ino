#include <Servo.h>

Servo servox;
Servo servoy;
Servo servoz;
Servo servog;


int posx=90;
int posy=90;
int posz=40;
int posg=0;


int x=A0;
int y=A1;
int z=A2;

int valx=0;
int valy=0;
int valz=0;

void setup() 
{
  servox.attach(9);
  servoy.attach(10);
  servoz.attach(11);
  servog.attach(12);
  
  servox.write(90);
  servoy.write(90);
  servoz.write(40);
  servog.write(0);
  Serial.begin(9600);
}

void loop()
{
valx=analogRead(x);
valx=analogRead(y);
valx=analogRead(z);
Serial.print(analogRead(x));
Serial.print("\t");
Serial.print(analogRead(y));
Serial.print("\t");
Serial.print(analogRead(z));
Serial.println();
delay(35);
 
//Serial

if ((valx>270)&&(valx<315)&&(valy<320)&&(valy>350))
{
  posx--;
  servox.write(posx);
}
if ((valx>375)&&(valx<415)&&(valy<320)&&(valy>350))
{
  posx++;
  servox.write(posx);
}

//Base Servo 

if ((valx>260)&&(valx<300)&&(valy<320)&&(valy>350))
{
  posy++;
  servoy.write(posy);
}
if ((valx>270)&&(valx<315)&&(valy<320)&&(valy>350))
{
  posy--;
  servoy.write(posy);
}

//Gripper

if(valz<330)
{
  servog.write(180);
}
if(valz>350)
{
  servog.write(0);
}

//Servo 2

if ((valx>290)&&(valx<325)&&(valy<305)&&(valy>330))
{
  posy++;
  servoz.write(posz);
}

if ((valx>250)&&(valx<380)&&(valy<305)&&(valy>330))
{
  posz--;
  servoz.write(posz);
}


}
