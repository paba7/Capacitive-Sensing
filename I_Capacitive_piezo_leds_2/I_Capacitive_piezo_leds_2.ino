#include <CapacitiveSensor.h>

/* 
* CapitiveSense Library Demo Sketch
* Paul Badger 2008/ Slightly adapted by Bare Conductive 2011 
* Uses a high value resistor e.g. 10 megohm between send pin and receive pin
* Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
* Receive pin is the sensor pin - try different amounts of Bare Paint
* Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
*/

/*by Tom Igoe, with suggestion from Michael Flynn

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone2
*/

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil


int speakerOut = 9; 
int led = 10;      // PWM pin that the LED is on.  n.b. PWM 0 is on digital pin 9
int led2 = 11; 
int threshold = 1000;
int threshold2 = 300;
int threshold3 = 3000;

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   cs_4_6.set_CS_AutocaL_Millis(0xFFFFFFFF);
   Serial.begin(9600);
    pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    //long total3 =  cs_4_8.capacitiveSensor(30);

   // Serial.print(millis() - start);        // check on performance in milliseconds
   // Serial.print("\t");                    // tab character for debug windown spacing

    // Serial.print(millis() - start);        // check on performance in milliseconds
   
                                             //OPTIONAL: To use additional sensors,change Serial.println to Serial.print for proper window spacing
    
   // Serial.print("\t");
   // Serial.println(total3);                // print sensor output 3
    
  // map the analog input range (in this case, 0 - 2000 from the conductive ink pad)
  // to the output pitch range (120 - 1500Hz)
  // change the minimum and maximum input numbers below
  // depending on the range your sensor's giving: 
  int thisPitch = map(total1, 0, 2000, 120, 1500);
  
  
   // play the pitch:
  //tone(9, thisPitch, 10);
  
  
 if(total1 < threshold && total1 > 200){    
        tone(9, thisPitch, 10);
        digitalWrite(led, HIGH);
         digitalWrite(led2, LOW);
          Serial.print("\n"); 
        Serial.print("LED high "); 
        Serial.print("LED2 low ");
        Serial.print("\t");
        Serial.print("play left"); 
         Serial.print("\t");                    // tab character for debug windown spacing
    Serial.print("totalA: ");
    Serial.print(total1);                  // print sensor output 1
    }else if (total2 > threshold2 && total1 < 700 ) {
       tone(9, thisPitch, 20);
        digitalWrite(led2, HIGH);
        digitalWrite(led, LOW);
        Serial.print("\n");
        Serial.print("LED2 HIGH ");
        Serial.print("LED low "); 
        Serial.print("play right ");
        Serial.print("\t");
   Serial.print("totalB: ");
   Serial.print(total2);                  // print sensor output 2
        }else if (total1 > threshold3 && total2 > threshold3 ) {
       tone(9, thisPitch, 30);
       digitalWrite(led2, LOW);
        digitalWrite(led, LOW);
         Serial.print("\n");
       Serial.print("\n");
        Serial.print("LED low ");
        Serial.print("LED2 low");
       Serial.print("\t"); 
        Serial.print("play both");
    }else{
        noTone(9);
        Serial.println("noTone"); 
         Serial.print("\t");                    // tab character for debug windown spacing
    Serial.print("totalA: ");
    Serial.print(total1); 
    Serial.print("\t");
   Serial.print("totalB: ");
   Serial.print(total2); 
    }

    delay(100);
  
   
                       // arbitrary delay to limit data to serial port 
}
