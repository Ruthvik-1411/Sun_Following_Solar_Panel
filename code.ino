// Sun following Panel using 2 Ldrs.
#include<Servo.h>                                    //including servo library
# define spin 9                                      //defining servo pin
#define Ldrpin_01 A0                                 //defining Ldr pins
#define Ldrpin_02 A1
int val1;  //assuming it is morning then ldr1 is far from sun and ldr2 is close to sun.[ldr1 is above, ldr2 is below]
int val2;
int diff;
int val=20;                                          //predefined value obtained while testing.(can vary depending on light intensity)
int angle=90;
Servo myservo;                                       //object myservo from class Servo.
void setup() {
  // put your setup code here, to run once:
pinMode(spin,OUTPUT);                                //declaring servo pin as output.
pinMode(Ldrpin_01,INPUT);                            //declaring ldr pins as input.
pinMode(Ldrpin_02,INPUT);
myservo.attach(spin);                                //telling that my servo is attached to servo pin using library function.
Serial.begin(9600);
myservo.write(angle);                                //initially put servo at 90 degrees i.e. horizontal to surface.
}

void loop() {
  // put your main code here, to run repeatedly:
diff = readval();                 //calling function that reads and prints the ldr values

if (diff>val)                     //[EVENING] if the difference is greater than val i.e. upper ldr is more exposed,then sun is back, turn towards west.
{
  if(angle<180)                   //as long as the angle is less than 180deg increase the angle from 90deg or prev angle, for corresponding change in light intensity.
    angle++;
myservo.write(angle);
delay(10);                       //wait for 10milli seconds and check again[to get slow response to change in intensity, the time can be increased].
}
else if (diff<-val)               //[MORNING] if the difference is less than negeative val i.e. lower ldr is more exposed,then sun is front, turn towards east.
{
  if(angle>30)                    //as long as the angle is greater than 30deg decrease the angle from 90deg or prev angle, for corresponding change in light intensity. 
     angle--;
myservo.write(angle);
delay(10);

}         
}

int readval(){                    //The following can be directly used in void loop. It is not compulsory to create a new function, it is just neat this way. 
  int dif;
val1 = analogRead(Ldrpin_01);                     
val2 = analogRead(Ldrpin_02);
val1 = map(val1,0,1023,0,180);
val2 = map(val2,0,1023,0,180);    //print statements can also be added to see the LDR values obtained 
dif = val1-val2;                                  
Serial.print("difference is: ");
Serial.println(dif);              //print statement is used just for viewing our values while testing.[can be omitted]
return dif;
}
