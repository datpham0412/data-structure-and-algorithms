const int ledPins[] = {11, 10, 9}; // LEDs connected to pins 11, 10, and 9
const int buttonPins[] = {2, 3, 4, 5}; // Buttons connected to pins 2, 3, 4, and 5

int ledStates[] = {LOW, LOW, LOW}; // States of LEDs
int buttonStates[] = {LOW, LOW, LOW, LOW}; // States of buttons
int lastButtonStates[] = {LOW, LOW, LOW, LOW}; // Previous button states

unsigned long lastDebounceTimes[] = {0, 0, 0, 0}; // Last debounce times for buttons
unsigned long debounceDelay = 50; // Debounce time in milliseconds

int blinkSpeed = 500; // Initial blinking speed of LED 2
bool blinkState = LOW; // Blinking state of LED 2

int brightness = 5;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT); // Configure LED pins as output
    digitalWrite(ledPins[i], ledStates[i]); // Initialize LED states
  }

  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Configure button pins as input with internal pull-up resistors
  }
}

void loop() {
  for (int i = 0; i < 4; i++) {
    int reading = digitalRead(buttonPins[i]);

    if (reading != lastButtonStates[i]) {
      lastDebounceTimes[i] = millis();
    }

    if ((millis() - lastDebounceTimes[i]) > debounceDelay) {
      if (reading != buttonStates[i]) {
        buttonStates[i] = reading;

        if (buttonStates[i] == HIGH) {
          // Button 1: Toggle LED 1
          if (i == 0) {
            ledStates[0] = !ledStates[0];
            digitalWrite(ledPins[0], ledStates[0]);
          }
          // Button 2: Increase blinking speed of LED 2
          else if (i == 1) {
            blinkSpeed -= 100;
          }
          // Button 3: Decrease blinking speed of LED 2
          else if (i == 2) {
            blinkSpeed += 100;
          }
          // Button 4: Control LED 3 brightness
          else if (i == 3) {
            brightness += 20;
            analogWrite(ledPins[2], brightness); // Control LED 3 brightness
          }
        }
      }
    }

    lastButtonStates[i] = reading;
  }

  // Blink LED 2 with the specified blinkSpeed
  if (millis() - lastDebounceTimes[1] >= blinkSpeed) {
    lastDebounceTimes[1] = millis();
    blinkState = !blinkState;
    digitalWrite(ledPins[1], blinkState);
  }
}