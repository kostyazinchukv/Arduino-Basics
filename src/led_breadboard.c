// C language code write for Arduino 1.8.15/Ubuntu
// Run it from Arduino IDE 

const int led = 7;                                  // Pin on the Arduino Uno Board              
const int one_second = 1000;                        // One second constant
int previous_timescreen = millis();                 // previous time needed to determine passed time

void setup() {
  pinMode(led, OUTPUT);                             // pin mode to pin port on Arduino Uno board
}

void loop() {
  int current_timescreen = millis();                                              
  if((current_timescreen - previous_timescreen) > one_second - 1){                
    digitalWrite(led, HIGH);                                                      
    if((current_timescreen - previous_timescreen) > one_second + one_second - 1){
      previous_timescreen = current_timescreen;
    }
  }
  else{
    digitalWrite(led, LOW);
  }
}