#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial bluetooth(10, 11); // RX | TX
char command;

Servo baseServo;  
Servo miniservo;

int pos = 0;    // variable to store the servo position
int minipos = 0;

void setup(){
    baseServo.attach(9);  // attaches the servo on pin 9 to the servo object
    miniservo.attach(8);
    Serial.begin(9600);
    bluetooth.begin(9600);  //Default Baud for comm, it may be different for your Module. 
    Serial.println("connected to bluetooth. pairing key 1234");
}

void loop()
{
    if (bluetooth.available()){
        command = (bluetooth.read());
        switch (command){
            case '1': 
                if (pos < 180){
                    pos += 15;
                    baseServo.write(pos);
                }
                break;
            case '2':
                if (pos > 0){
                    pos -= 15;
                    baseServo.write(pos);
                }
                break;
            case '3': 
                if (minipos < 180){
                    minipos += 15; 
                    miniservo.write(minipos); // tell servo to go to position in variable 'pos'
                }
                break;
            case '4':
                if (minipos > 0){
                    minipos -= 15;
                    miniservo.write(minipos);
                }
                break; 
        }
        delay(15);
    }
}
