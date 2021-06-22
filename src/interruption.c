// C language code write for Arduino 1.8.15/Ubuntu
// Run it from Arduino IDE 

const int led_pin = 7;
const int interrupt_pin = 2;

int toggle_state;
byte last_button_state = HIGH;
unsigned long int last_pressed;
volatile bool state;
int debounce_delay = 20;

void setup()
{
  pinMode(led_pin, OUTPUT);
  pinMode(interrupt_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin), button_pressed, CHANGE);
}

void loop()
{
  if((millis() - last_pressed) > debounce_delay && state)
  {
      last_pressed = millis();
      if(digitalRead(interrupt_pin) == LOW && last_button_state == HIGH)
      {
        toggle_state = !toggle_state;
        digitalWrite(led_pin, toggle_state);
        last_button_state = 0;
      }
      else if(digitalRead(interrupt_pin) == HIGH && last_button_state == LOW)
      {
        last_button_state = 1;  
      }
      state = false;
  }
}

void button_pressed()
{
    state = ! state;
}