#define R1 25       // define R1 (our board has RELAY1 connected on 25 pin)
#define R2 26       // define R2 (our board has RELAY2 connected on 26 pin)
#define R3 27       // define R3 (our board has RELAY3 connected on 27 pin)
#define R4 33        // define R4 (our board has RELAY4 connected on 33 pin)
void setup() // setup loop for initialize all the devices (only one time)
{
  pinMode(R1, OUTPUT); // making R1 as a output device
  pinMode(R2, OUTPUT); // making R2 as a output device
  pinMode(R3, OUTPUT); // making R3 as a output device
  pinMode(R4, OUTPUT); // making R4 as a output device
  digitalWrite(R1, HIGH); // MAKE all off (relay work in inveter logic(LOW->> ON, HIGH->>OFF))
  digitalWrite(R2, HIGH);
  digitalWrite(R3, HIGH);
  digitalWrite(R4, HIGH);
}

void loop() // main loop for main working task (Run again and again)
{
  digitalWrite(R1, LOW); // Turn on the R1
  delay(1000);             // Delay for 1 sec
  digitalWrite(R1, HIGH);  // Turn off the R1
  delay(1000);             // Delay for 1 sec
  digitalWrite(R2, LOW); // Turn on the R2
  delay(1000);             // Delay for 1 sec
  digitalWrite(R2, HIGH);  // Turn off the R2
  delay(1000);             // Delay for 1 sec
  digitalWrite(R3, LOW); // Turn on the R3
  delay(1000);             // Delay for 1 sec
  digitalWrite(R3, HIGH);  // Turn off the R3
  delay(1000);             // Delay for 1 sec
  digitalWrite(R4, LOW); // Turn on the R4
  delay(1000);             // Delay for 1 sec
  digitalWrite(R4, HIGH);  // Turn off the R4
  delay(1000);             // Delay for 1 sec
}
