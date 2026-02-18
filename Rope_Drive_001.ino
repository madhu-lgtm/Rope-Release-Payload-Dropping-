//Rope Drive Mechanism (RD21F (Jonson Motor Geared Motor)- 200RPM - Input Voltage 16v) 
//Programming Board nano 
//Used 2ch Relay Active LOW type
//Make sure to set the toggle switch to mid position on tansmitter befor turning on the drone .. 
// ..as initial position 
// Make sure to disconnect any power input or output while programming the nano

/*
Program Uploded On :- 18-feb-2026
Developed By :- K Madhu Mohan Chary
For More Details :- madhu@marutdrones.com
*/

const int pwm_read_pin = 9 ; //d9 pin 
const int in1_pin = 8;
const int in2_pin = 7;
unsigned int init_delay = 1000;//wait 1sec for drone to initilize 
int pwm_read_val = 0;
int pwm_min = 1000;
int pwm_mid = 1500;
int pwm_max = 2000;
int pwm_buff = 200; 

void setup() {
  // put your setup code here, to run once:
  pinMode(in1_pin,OUTPUT);
  pinMode(in2_pin,OUTPUT);
  pinMode(pwm_read_pin,INPUT);
  Serial.begin(9600);
  delay(init_delay);
}

void loop() {
  // put your main code here, to run repeatedly:

  pwm_read_val = pulseIn(pwm_read_pin,HIGH);
  if(pwm_read_val >= (pwm_min - pwm_buff) && pwm_read_val <= (pwm_min + pwm_buff)){
    digitalWrite(in1_pin,LOW);
    digitalWrite(in2_pin,HIGH);
    //Serial.println("Down");
  }
  else if (pwm_read_val >= (pwm_max - pwm_buff) && pwm_read_val <= (pwm_max + pwm_buff)){
    digitalWrite(in1_pin,HIGH);
    digitalWrite(in2_pin,LOW);
    //Serial.println("Up");
  }
  else if (pwm_read_val >= (pwm_mid - pwm_buff) && pwm_read_val <= (pwm_mid + pwm_buff)){
    digitalWrite(in1_pin,HIGH);
    digitalWrite(in2_pin,HIGH);
    //Serial.println("Stop");
  }
  delay(100);
}
