
// Global variable to store the intensity
int intensity = 0;

void setup()
{
    // Signal 9 configured as Output
    pinMode(9, OUTPUT);
}
void loop()
{ 
    // Increment intensity value
    intensity += 5;
    // Value cannot be greater than 255
    if (intensity > 255) {
    intensity = 0;
    }
    // Configure output PWM signal
    analogWrite(9, intensity);
    // Wait half a second
    delay(500);
}