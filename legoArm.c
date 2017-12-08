#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial servoBlue(10, 11); // RX | TX
char command;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

Servo miniservo;

int pos = 0;    // variable to store the servo position
int minipos = 0;

void setup(){
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  miniservo.attach(8);
  Serial.begin(9600);
  servoBlue.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("connected to bluetooth. pairing key 1234");
}
 
void loop()
{
 
  if (servoBlue.available()){
    command = (servoBlue.read());
    if (command=='1'){
      Serial.println(command);
        if (pos < 180){
        pos += 15; 
        myservo.write(pos);
        delay(15);  
        }
    }
    
    if (command=='2'){
      Serial.println(command);
        if (pos > 0){
        pos -= 15;
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
    }

    if (command=='3'){
      Serial.println(command);
        if (minipos < 180){
        minipos += 15; 
        miniservo.write(minipos); // tell servo to go to position in variable 'pos'
        delay(15);  
        }
    }

     if (command=='4'){
      Serial.println(command);
        if (minipos > 0){
        minipos -= 15;
        miniservo.write(minipos);
        delay(15);                       // waits 15ms for the servo to reach the position
        }
    }
  }

}
