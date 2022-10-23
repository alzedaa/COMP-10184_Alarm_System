// COMP-10184 – Mohawk College 
// PIR Sensor Test Application 
// Turn on the blue LED with motion is detected. 
 
#include <Arduino.h> 
bool enabled = true;
boolean buttonState = false;
 
// digital input pin definitions 
#define PIN_PIR D5 
#define PIN_BUTTON D6 
 
 
// ************************************************************* 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure the LED output 
  pinMode(LED_BUILTIN, OUTPUT); 
 
  // PIR sensor is an INPUT 
  pinMode(PIN_PIR, INPUT); 
 
  // Button is an INPUT 
  pinMode(PIN_BUTTON, INPUT_PULLUP); 
  digitalWrite(LED_BUILTIN, HIGH);

  pinMode(D6, INPUT_PULLUP);
} 

// ************************************************************* 
void loop() { 
  bool bPIR; 

   if (digitalRead(D6) == 0) {
    buttonState = !buttonState;
    delay(100);
  }

  if (buttonState) {
    printf("Button on");
    buttonState = !buttonState;
  }
 
  // read PIR sensor (true = Motion detected!).  As long as there 
  // is motion, this signal will be true.  About 2.5 seconds after  
  // motion stops, the PIR signal will become false. 
  bPIR = digitalRead(PIN_PIR); 
 
  // send the PIR signal directly to the LED 
  // but invert it because true = LED off! 
  
  while (enabled)
  {
    if(bPIR) {

    for(int i = 0; i <10; i++) {
      digitalWrite(LED_BUILTIN, LOW);
      delay(125);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(125);
      digitalWrite(LED_BUILTIN, LOW);
      delay(125);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(125);
      digitalWrite(LED_BUILTIN, LOW);
      delay(125);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(125);
      digitalWrite(LED_BUILTIN, LOW);
      delay(125);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(125);
    }
    digitalWrite(LED_BUILTIN, LOW);
    enabled = false;
    }
    
  }
  
  
} 