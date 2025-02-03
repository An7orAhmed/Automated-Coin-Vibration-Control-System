#include <NewPing.h>
#define coin_1 2
#define coin_2 3
#define echo_1 5
#define trig_1 4
#define echo_2 7
#define trig_2 6

NewPing sonar_1(trig_1, echo_1, 100);
NewPing sonar_2(trig_2, echo_2, 100);

int dis_1, dis_2;
long int set_dis_1, set_dis_2, adc; 

void setup() {
  Serial.begin(9600);
  pinMode(coin_1, OUTPUT);
  pinMode(coin_2, OUTPUT);  
}

void loop() {
  adc = analogRead(A0);
  set_dis_1 = map(adc, 0, 1023, 0, 100);
  Serial.print("Sonar 1 set dis: ");
  Serial.println(set_dis_1, DEC); 
  
  Serial.print("Ping 1: ");
  dis_1 = sonar_1.ping_cm();
  Serial.print(dis_1, DEC); 
  Serial.println("cm");
  Serial.println();
  delay(500);

  adc = analogRead(A1);
  set_dis_2 = map(adc, 0, 1023, 0, 100);
  Serial.print("Sonar 2 set dis: ");
  Serial.println(set_dis_2, DEC); 
  
  Serial.print("Ping 2: ");
  dis_2 = sonar_2.ping_cm();
  Serial.print(dis_2, DEC); 
  Serial.println("cm");
  Serial.println();
  delay(500);

  if(dis_1 > set_dis_1) digitalWrite(coin_1, HIGH);
  else digitalWrite(coin_1, LOW);
  if(dis_2 > set_dis_2) digitalWrite(coin_2, HIGH);
  else digitalWrite(coin_2, LOW);
}
