// Pin definitions for ultrasonic sensor, buzzer, switchs and LED's
const   int   switchLeft      = 6,  switchRight    = 7;
const   int   turnRightSignal = 3,  turnLeftSignal = 4;
const   int   trigPin         = 12, echoPin        = 11;
const   int   distanceAlarm   = 13;

// Variables for duration and distance
int   duration, distance;

// Verify Switches
bool      ThereIsASwitchOn              =   false;

// Minimal Distance to Trigger the Alarm
double    minimalDistanceTriggerAlarm   =   150.0;

void setup() {
  Serial.begin(9600);  // Start serial communication for debugging

  // Set up sensor and buzzer pins
  pinMode(trigPin,
                  OUTPUT);
  pinMode(echoPin,
                  INPUT);
  pinMode(distanceAlarm,
                        OUTPUT);

  // Button Signal Pins
  pinMode(switchRight,
                      INPUT_PULLUP);
  pinMode(switchLeft,
                      INPUT_PULLUP);

  // Signal Turn Pins
  pinMode(turnRightSignal,
                          OUTPUT);
  pinMode(turnLeftSignal,
                          OUTPUT);

  // Initialize Signal Pins
  digitalWrite(turnRightSignal,
                              LOW);
  digitalWrite(turnLeftSignal,
                              LOW);
}

void loop() {

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);     // Ensure the distance is correct
  Serial.print("cm\n");

  handleTurnSignals();

  if (ThereIsASwitchOn &&
                          distance < minimalDistanceTriggerAlarm)
  {
    triggerAlarm();
  }

  // Small delay to calculate again
  delay(50);
}

int getDistance(){
  // Trigger the ultrasonic sensor to send a pulse
  digitalWrite(trigPin,
                      LOW);    // Ensure LOW to clear pin
  delayMicroseconds(2);        // Short delay to stabilize the trigger pin
  digitalWrite(trigPin,
                      HIGH);   // Send HIGH pulse to trigger sensor
  delayMicroseconds(10);       // Pulse duration
  digitalWrite(trigPin,
                      LOW);    // Turn off the trigger pin
  
  // Measure the duration of the echo pulse
  duration    =    pulseIn(echoPin,
                                  HIGH);
  
  // Calculate the distance in cm
  distance    =   duration / 2 / 29.1;

  return          distance;
}

void handleTurnSignals(){

  // Variables being used
  bool    swActivateR   =   digitalRead(switchRight);
  bool    swActivateL   =   digitalRead(switchLeft);

  // RIGHT SIDE SWITCH
  if (swActivateR   ==    HIGH){

    ThereIsASwitchOn    =   true;

    digitalWrite(turnRightSignal,
                                HIGH);
    digitalWrite(turnLeftSignal,
                                LOW);   delay(200);
    digitalWrite(turnRightSignal,
                                LOW);   delay(200);
  }
  if (ThereIsASwitchOn == true    &&
                                    swActivateR == LOW)
                                    {
                                      digitalWrite(turnRightSignal,
                                                                  LOW);
                                    }

  // LEFT SIDE SWITCH
  if (swActivateL   ==    HIGH)
  {
    ThereIsASwitchOn      =   true;
    digitalWrite(turnRightSignal,
                                LOW);
    digitalWrite(turnLeftSignal,
                                HIGH);  delay(200);
    digitalWrite(turnLeftSignal,
                                LOW);   delay(200);
  }
  if (ThereIsASwitchOn    ==    true    &&
                                          swActivateL   ==    LOW)
  {
    digitalWrite(turnLeftSignal,
                                LOW);
    }
}

void triggerAlarm(){
    tone(distanceAlarm,
                      3000); //Ensure to use a Hz between 2.5-5 kHz
     delay(200);
     noTone(distanceAlarm);    delay(200);

}
