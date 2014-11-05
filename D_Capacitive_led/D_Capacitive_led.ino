 #include <CapacitiveSensor.h>

/* 
* CapitiveSense Library Demo Sketch
* Paul Badger 2008
* Slightly adapted by Bare Conductive 2011 
* Uses a high value resistor e.g. 10 megohm between send pin and receive pin
* Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
* Receive pin is the sensor pin - try different amounts of Bare Paint
* Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
*/

int led = 9;      // PWM pin that the LED is on.  n.b. PWM 0 is on digital pin 9
int threshold = 100;

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
//CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
//CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   pinMode(led, OUTPUT);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    //long total2 =  cs_4_6.capacitiveSensor(30);
    //long total3 =  cs_4_8.capacitiveSensor(30);

   // Serial.print(millis() - start);        // check on performance in milliseconds
   // Serial.print("\t");                    // tab character for debug windown spacing

    Serial.println(total1);                  // print sensor output 1
    
    if(total1 > threshold ){    
        digitalWrite(led, HIGH);
        Serial.println("high"); 
    }else{
        digitalWrite(led, LOW);
        Serial.println("low"); 
    }

    delay(100);
    
                                             //OPTIONAL: To use additional sensors,change Serial.println to Serial.print for proper window spacing
   // Serial.print("\t");
   // Serial.print(total2);                  // print sensor output 2
   // Serial.print("\t");
   // Serial.println(total3);                // print sensor output 3

    delay(10);                             // arbitrary delay to limit data to serial port 
}
