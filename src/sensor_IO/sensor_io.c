#define TMP 9
#define RedLed 11
#define BlueLed 3
#define SensorPIR 2

const int LM35 = A0; // Pino que lera a saida do sensor de temperatura LM35
int temperature; // var que armazena a temperatura media
int trigger;

// Variavel global para armazenar a intensidade
int intensidade_red_light = 0;
// Intensidade do ventilador

void setup()
{
  	// Sinal 9 configurado como Saida
  	pinMode(RedLed, OUTPUT);
	pinMode(BlueLed, OUTPUT);
    pinMode(SensorPIR, INPUT);

    Serial.begin(9600); // Define a velocidade e inicia a comunicação

}
void loop()
{
    temperature = int((double(analogRead(LM35))*5/(1023.0))/0.01);
    trigger = digitalRead(SensorPIR);
    
  	//Serial.print("Temperature: ");
    //Serial.println(temperature);
  	//Serial.println("---------------------");
  	Serial.print("Trigger: ");
    Serial.println(trigger);
  	Serial.println("---------------------");
    
  	if (temperature<=25)
    {
        intensidade_red_light = 85;
    } else if (temperature<=33)
    {
        intensidade_red_light = 170;
    } else {
        intensidade_red_light = 255;
    }
    analogWrite(RedLed, intensidade_red_light);

    if (trigger == LOW)
    {
        //
    }else
    {
     //
    }

    // Aguarda meio segundo
    delay(500);
}