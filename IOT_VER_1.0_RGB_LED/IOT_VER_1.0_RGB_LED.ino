#define LED_R 15       // define led red (our board has LED connected on 9 pin)
#define LED_G 2       // define led green (our board has LED connected on 10 pin)
#define LED_B 0       // define led blue (our board has LED connected on 11 pin)

void setup() // setup loop for initialize all the devices (only one time)
{
  pinMode(LED_R, OUTPUT); // making LED R as a output device
  pinMode(LED_G, OUTPUT); // making LED G as a output device
  pinMode(LED_B, OUTPUT); // making LED B as a output device
}

void loop() // main loop for main working task (Run again and again)
{
  digitalWrite(LED_R, HIGH); // Turn on the LED
  delay(1000);             // Delay for 1 sec
  digitalWrite(LED_R, LOW);  // Turn off the LED
  delay(1000);             // Delay for 1 sec
  digitalWrite(LED_G, HIGH); // Turn on the LED
  delay(1000);             // Delay for 1 sec
  digitalWrite(LED_G, LOW);  // Turn off the LED
  delay(1000);             // Delay for 1 sec
  digitalWrite(LED_B, HIGH); // Turn on the LED
  delay(1000);             // Delay for 1 sec
  digitalWrite(LED_B, LOW);  // Turn off the LED
  delay(1000);             // Delay for 1 sec
}
