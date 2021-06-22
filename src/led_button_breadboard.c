// C language code write for Arduino 1.8.15/Ubuntu
// Run it from Arduino IDE 

const int buttonPin = 2;                            // the number of the pushbutton pin
const int ledPin = 7;                               // the number of the LED pin


int ledState = HIGH;                                // the current state of the output pin
int buttonState;                                    // the current reading from the input pin
int lastButtonState = LOW;                          // the previous reading from the input pin


unsigned long lastDebounceTime = 0;                 // the last time the output pin was toggled
unsigned long debounceDelay = 0;                    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  Serial.println(reading);
  if (reading != lastButtonState) {
    
    lastDebounceTime = millis();                        // reset the debouncing timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {                       // if the button state has changed:
      buttonState = reading;


      if (buttonState == HIGH) {                        // only toggle the LED if the new button state is HIGH
        ledState = !ledState;
      }
    }
  }

  digitalWrite(ledPin, ledState);

  lastButtonState = reading;
}