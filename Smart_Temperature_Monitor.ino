int tempPin = A0;
int ledPin = 13;
int buzzerPin = 8;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    int sensorValue = analogRead(tempPin);

    float voltage = sensorValue * (5.0 / 1023.0);
    float temperatureC = (voltage - 0.5) * 100;

    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" °C");

    if (temperatureC > 35)
    {
        digitalWrite(ledPin, HIGH);
        digitalWrite(buzzerPin, HIGH);
    }
    else
    {
        digitalWrite(ledPin, LOW);
        digitalWrite(buzzerPin, LOW);
    }

    delay(1000);
}