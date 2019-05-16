#include <Servo.h> //Includes the library for the servo motor
const int tPin = 8; //Setting the trig pin
const int ePin = 9; //Setting the echoPin
// defining time and distance
long duration;
int distance;
Servo myServo; // Defining an object servo

//The setup function
void setup() {
  pinMode(tPin, OUTPUT); // trigPin as an Output
  pinMode(ePin, INPUT); // echoPin as an Input
  Serial.begin(9600); //begins it.
  myServo.attach(10); // (At the digital pin 10, the pin connected to servo.)
}

//The loop function
void loop() {
// starts rotating from degree 15 to 165 degrees.
for(int i=15;i<=165;i++){
  myServo.write(i);  //Writes the angle
  delay(30);
  distance = calculateDistance(); //delays and calculates the distance
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  //The above four lines print the angle and the distance.
}
//Repeats the same from 165 to 15 degrees.
for(int i=165;i>15;i--){
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
 }
 
} //Loop ends here.

//This calculates the distance.
int calculateDistance(){
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);
  duration = pulseIn(ePin, HIGH);
  distance= duration*0.034/2;
  return distance;
}
