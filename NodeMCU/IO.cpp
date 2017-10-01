#include <ESP8266WiFi.h>
#include "IO.h"

IO::IO() { }

bool IO::disponivel() {
    return Serial.available();
}

void IO::enviar(Sensores sensor, int dados) {
  
}

void IO::enviar(Sensores sensor) {
  
}

Dashboard IO::obterDashboard() {

}

Planta IO::obterPlanta(int id) {
  Serial.println("obterPlanta");

  enviar(Sensores::Todos);

  Planta planta;

  int valor = -1;

  while ((valor != Serial.read()) > -1) {
    Serial.println(valor);

    switch (valor) {
      case Sensores::Chuva:
      planta.chuva = Serial.read();
      break;
      case Sensores::Luminosidade:
      planta.luminosidade = Serial.read();
      break;
      case Sensores::Proximidade:
      planta.proximidade = Serial.read();
      break;
      case Sensores::Temperatura:
      planta.temperatura = Serial.read();
      break;
      case Sensores::UmidadeSolo:
      planta.umidadeSolo = Serial.read();
      break;
    }
  }

  char retorno[256];
  sprintf(retorno, "%d,%d,%d", planta.umidadeSolo, planta.luminosidade, planta.temperatura);
  planta.retorno = retorno;

  return planta;
}

Abastecimento IO::obterAbastecimento() {

}
