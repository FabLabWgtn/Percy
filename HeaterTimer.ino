/*
Auto timing arduino code for chocolate heater
Uses a potentiometer and relay to control the duty cycle of our heating element.
 */

// Pin setup
const int PotPin = A0;  // Analog input pin that the potentiometer is attached to
const int RelayPin = 9; // Analog output pin that the LED is attached to

int cycletime = 1000; //total number of cycles, keep high to presever relay but low enough to maintain temp.
int cyclecurrent = 0; //variable to log how many cycles have passed

const boolean Debug = false; //Set true to enable serial output

void setup() {
  // initialize serial if debug enabled
  if(Debug == true){
    Serial.begin(9600);
  }
  pinMode(RelayPin, OUTPUT);
}

void loop() {
  cyclecurrent ++; //add one to the cycle count
  //Read the Pot value and map it to a cycle duration
  int PotValue = analogRead(PotPin);
  int outputValue = map(PotValue, 0, 1023, 0, cycletime);
  //toggle the relay
  if(outputValue >= cyclecurrent){
    digitalWrite(RelayPin, HIGH);
  } 
  else{
    digitalWrite(RelayPin, LOW);
  }
  if(cyclecurrent >= cycletime){ //check to see if full cycle has been completed
    cyclecurrent = 0;
  }

  // print the results to the serial monitor:
  if(Debug == true){
    Serial.print("cycle = ");
    Serial.print(cyclecurrent);
    Serial.print("\t sensor = " );
    Serial.print(PotValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
  }
  delay(2); //wait 2 milliseconds before next cycle
  
}
