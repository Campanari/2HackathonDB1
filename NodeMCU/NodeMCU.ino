#define LED_PORT LED_BUILTIN

void setup(void)
{
  Serial.begin(9600);
  pinMode(LED_PORT, OUTPUT); 
}

void loop(void)
{
  if (Serial.available()) {
    int value = Serial.read();

    Serial.println(value);

    if (value == 1) {
      digitalWrite(LED_PORT, HIGH);
    } else {
      digitalWrite(LED_PORT, LOW);
    }
  }

  delay(100);
}
