#define TMP 9
#define RedLed 11
#define BlueLed 3
#define SensorPIR 2

const int LM35 = A0; // Pin that will read the output of the LM35 temperature sensor
int temperature; // var that stores the average temperature
int trigger;

// Global variable to store the intensity
int intensity_red_light = 0;
// Fan intensity
int intensity_fan = 0;

void setup()
{
  // Signal 9 configured as Output
  pinMode(RedLed, OUTPUT);
	pinMode(BlueLed, OUTPUT);
  pinMode(SensorPIR, INPUT);

  Serial.begin(9600); // Sets the speed and starts communication

}
void loop()
{
  temperature = int((double(analogRead(LM35))*5/(1023.0))/0.01);
  trigger = digitalRead(SensorPIR);
    
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.println("---------------------");
  Serial.print("Trigger: ");
  Serial.println(trigger);
  Serial.println("---------------------");
    
  if (temperature<=25)
  {
      intensity_red_light = 85;
  } else if (temperature<=33)
  {
    intensity_red_light = 170;
  } else 
  {
    intensity_red_light = 255;
  }
  analogWrite(RedLed, intensity_red_light);

  if (trigger == LOW)
  {
    //
  }else
  {
    //
  }

  // Wait half a second
  delay(500);
}