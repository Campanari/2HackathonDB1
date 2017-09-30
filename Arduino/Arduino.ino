#include "Led.h"
#include "SensorProximidade.h"
#include "SensorUmidadeSolo.h"

#define LED_PORT 13
#define SENSOR_P_TRIGGER_PORT 4
#define SENSOR_P_ECHO_PORT 5
#define SENSOR_U_S_PORT 6
#define SENSOR_U_S_PORT 6
#define SENSOR_U_S_PORT 6

Led* led;
SensorProximidade* sensorProximidade;
SensorUmidadeSolo* sensorUmidadeSolo;

void setup(void) {

  Serial.begin(9600);
  
  led = new Led(LED_PORT);
  led->registrar();

  sensorProximidade = new SensorProximidade(SENSOR_P_TRIGGER_PORT, SENSOR_P_ECHO_PORT);
  sensorProximidade->registrar();
  
  sensorUmidadeSolo = new SensorUmidadeSolo(SENSOR_U_S_PORT);
  sensorUmidadeSolo->registrar();
}

void loop(void) {
  int recebido = receberDados();

  int distancia = sensorProximidade->ler();
  
  if (distancia < 50) {
    led->ligar();
  } else {
    led->desligar();
  }

  Serial.print("distância: ");
  Serial.println(distancia);

  int retorno = sensorUmidadeSolo->ler();
  Serial.println(retorno);
  
  delay(100);
}

int receberDados() {
  if (Serial.available()) {
    return Serial.read();
  }

  return -1;
}
