# Complete Guide for Arduino task

## Steps
- [Download](#download)
- [Connection](#connection)
- [Tasks](#tasks)
    - [Blinking](#blinking)
    - [Voltage divider](#voltage-divider)
    - [Multitasking](#multitasking)

# Download

To download Arduino IDE use this 
[link](https://www.arduino.cc/en/software).
 Be sure that you download version **Linux 64 bits** to avoid any trouble further.

 Open terminal (Ctrl + Alt + T) and unpacked tar file via next command:
 > tar -C \<*directory for unpacking*> -xvf \<*arduino tar file*>

 After you unpacked this tar file, open up directory which you chose for this. Run this command:
 >sudo ./install.sh

 This will install Arduino IDE. To open Arduino type:
 >./arduino


# Connection

Connect you board and computer via USB port.

Run code that you will write in this IDE is possible through **upload** item. 

there will be lights on board meaning it is work. If it isn't ask team member to help.

# Tasks

In this section you will see tasks and little examples/solutions to them. Solutions might be one of possible, so you can try to solve them by yourself.

## Blinking

***TASK*** --> Make LED on Arduino board blinking every second

Here is code sample
```C
void setup(){
    pinMode(LED_BUILTIN, OUTPUT);// pin mode for led on arduino board
}
void loop(){
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // write value opposite to current in led on board
  delay(1000); // 1 second delay
}
```

## Voltage divider
***TASK*** --> Take a voltage value from ADT on Arduino board. As a scheme use voltage delimiter scheme example. All needed wires and resistors will be provide by team member.

Code sample
```C
void setup(){
    Serial.begin(9600);// Open Serial port
}
void loop(){
  val = analogRead(analogPin); // read voltage value from ADT in format (0, 1024)
  val = (val * 5)/1024;        // convert to (0V, 5V) format
  Serial.println(val);         // print it to serial monitor (open it from Tools)
}

```

## Multitasking
***TASK*** --> Make tasks [blinkig](#blinking) and [voltage divider](#voltage-divider) run simultaniously. 
```C
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
```

