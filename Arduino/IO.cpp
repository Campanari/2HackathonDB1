#include "Arduino.h"
#include "IO.h"

IO::IO() { }

void IO::registrar() {

}

bool IO::disponivel() {
    return Serial.available();
}

void IO::enviar(Sensores sensor, int dados) {
    Serial.print("Sensor ");
    Serial.print(sensor);
    Serial.print(": ");
    Serial.println(dados);
}

void IO::enviar(Sensores sensor, float dados) {
    Serial.print("Sensor ");
    Serial.print(sensor);
    Serial.print(": ");
    Serial.println(dados);
}

Sensores IO::receber() {
  byte entrada = Serial.read();

  Serial.print("Entrada: ");
  Serial.println(entrada);
    
  return (Sensores)entrada;
}
