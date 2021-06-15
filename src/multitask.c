// C language code write for Arduino 1.8.15/Ubuntu
// Run it from Arduino IDE 

int analogPin = 1;                  // Analog port on board
float val = 0;                      // value needed to calculating voltage  
int previous_lap = millis();        // time screen for previous second
const int thousand = 1000;          // 1 second 
void setup() {                      // setup function 

  Serial.begin(9600);               // Open Serial port
  pinMode(LED_BUILTIN, OUTPUT);     // pin mode for led on arduino board
}

void loop() {                       // Loop function
  int current_lap = millis();       // current time screen
  if((current_lap - previous_lap) > thousand - 1)                 // check for 1 second passed
  {
    digitalWrite(LED_BUILTIN, HIGH);                              // send signal to led to blink
    if((current_lap - previous_lap) > thousand + thousand - 1)    // check if two second passed to set previous time screen to current screen
      {
        previous_lap = current_lap;                               
      }
  }
  else
  {
      digitalWrite(LED_BUILTIN, LOW);                             // if 1 second didn't pass, then send signal to led to not blink
  }
  
 
  val = analogRead(analogPin);                                    // read voltage value from ADT in format (0, 1024)
  val = (val * 5)/1024;                                           // convert to (0V, 5V) format
  Serial.println(val);                                            // print it to serial monitor (open it from Tools)

}
