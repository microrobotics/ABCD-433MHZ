const int pinD0 = 2; // Connect to D0 on the receiver
const int pinD1 = 3; // Connect to D1 on the receiver
const int pinD2 = 4; // Connect to D2 on the receiver
const int pinD3 = 5; // Connect to D3 on the receiver
const int pinVT = 6; // Connect to VT on the receiver

// Debounce variables
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 450;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  pinMode(pinD0, INPUT);
  pinMode(pinD1, INPUT);
  pinMode(pinD2, INPUT);
  pinMode(pinD3, INPUT);
  pinMode(pinVT, INPUT);
}

void loop() {
  // Check if there is a valid transmission
  if (digitalRead(pinVT) == HIGH) {
    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (digitalRead(pinD3) == HIGH) {
        Serial.println("Button A pressed");
        lastDebounceTime = millis();
      }
      if (digitalRead(pinD2) == HIGH) {
        Serial.println("Button B pressed");
        lastDebounceTime = millis();
      }
      if (digitalRead(pinD1) == HIGH) {
        Serial.println("Button C pressed");
        lastDebounceTime = millis();
      }
      if (digitalRead(pinD0) == HIGH) {
        Serial.println("Button D pressed");
        lastDebounceTime = millis();
      }
    }
  }
}
