
int led9 = 9;           // the PWM pin the LED is attached to
int led10 = 10;
int brightness = 0;    // how bright the LED is
int fadeAmount = 15;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
   Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led10, brightness);
  analogWrite(led9, brightness);
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  Serial.println(fadeAmount);
  // wait for 30 milliseconds to see the dimming effect
  delay(50);
}
