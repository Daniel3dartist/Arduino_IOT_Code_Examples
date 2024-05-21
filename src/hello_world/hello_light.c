void setup()
{
	// Configure signal 9 as output
  	pinMode(9, OUTPUT);
}


void loop()
{
  	// Activates signal 9 with HIGH level (5V)
	digitalWrite(9, HIGH);
  	// Wait 1000 ms | 1 second
  	delay(1000);
  	// Activates signal 9 with LOW level (5V)
  	digitalWrite(9, LOW);
  	delay(1000);
  	// Wait 1000 ms | 1 second
}