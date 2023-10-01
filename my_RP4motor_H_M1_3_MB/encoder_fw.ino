
void setup_encoder_fw() { 
  pinMode(encoderPinA, INPUT_PULLUP); 
  pinMode(encoderPinB, INPUT_PULLUP);
  Serial.begin(9600);  // Start serial communication for debugging
  attachInterrupt(digitalPinToInterrupt(encoderPinA), encoderInterrupt, CHANGE);  
}


void encoderInterrupt() {
  int encoderPinAVal = digitalRead(encoderPinA);  
  if ((encoderPinALast == LOW) && (encoderPinAVal == HIGH)) {
    if (digitalRead(encoderPinB) == LOW) {
      encoderPoss--;
    } else {
      encoderPoss++;
    }
  } 
  encoderPinALast = encoderPinAVal;

  
}
