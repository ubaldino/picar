
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
}

void loop() {
  
  if ( Serial.available() ) {
    int inByte = Serial.read();
    Serial1.write( inByte ); 
  }
}
