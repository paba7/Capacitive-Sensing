/*pontentiometer(POT)  LED Fade
Uses POT to fade an LED to fade
This example code is in the public domain
*/

int potPin = A0;    // Analog input pin that the potentiometer is attached to
int potValue = 0;  // value read from the pot
int led = 9..;      // PWM pin that the LED is on.  n.b. PWM 0 is on digital pin 9



//the setup routine runs once when you press reset:
void setup() {
//initialize serial communication at 9600 bits per second
  Serial.begin(9600); 
  // declare the led pin as an output:
  pinMode(led, OUTPUT);
}

//the loop routine runs over and over again forever:
void loop() {
    potValue = analogRead(potPin); // read the pot value
  analogWrite(led, potValue/4);  // PWM the LED with the pot value (divided by 4 to fit in a byte)
  Serial.println(potValue);      // print the pot value back to the debugger pane
  delay(10);                     // wait 10 milliseconds before the next loop


}


