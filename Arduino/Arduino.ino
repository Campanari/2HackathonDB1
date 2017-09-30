#include "Led.h"
#include "SensorProximidade.h"
#include "SensorUmidadeSolo.h"
#include "SensorChuva.h"
#include "SensorLuminosidade.h"
#include "SensorTemperatura.h"

#define LED_PORT 13
#define SENSOR_P_TRIGGER_PORT 4
#define SENSOR_P_ECHO_PORT 5
#define SENSOR_U_S_PORT 6
#define SENSOR_U_S_SWITCH_PORT 6
#define SENSOR_U_S_PORT A0
#define SENSOR_C_PORT 8
#define SENSOR_L_PORT A2
#define SENSOR_T_PORT A1

Led* led;
SensorProximidade* sensorProximidade;
SensorUmidadeSolo* sensorUmidadeSolo;
SensorChuva* sensorChuva;
SensorLuminosidade* sensorLuminosidade;
SensorTemperatura* sensorTemperatura;

void setup(void) {

  Serial.begin(9600);

  led = new Led(LED_PORT);
  led->registrar();

  sensorProximidade = new SensorProximidade(SENSOR_P_TRIGGER_PORT, SENSOR_P_ECHO_PORT);
  sensorProximidade->registrar();

  sensorUmidadeSolo = new SensorUmidadeSolo(SENSOR_U_S_PORT, SENSOR_U_S_SWITCH_PORT);
  sensorUmidadeSolo->registrar();

  sensorChuva = new SensorChuva(SENSOR_C_PORT);
  sensorChuva->registrar();

  sensorLuminosidade = new SensorLuminosidade(SENSOR_L_PORT);
  sensorLuminosidade->registrar();

  sensorTemperatura = new SensorTemperatura(SENSOR_T_PORT);
  sensorTemperatura->registrar();
}

void loop(void) {
  int recebido = receberDados();

  int distancia = sensorProximidade->ler();

  if (distancia < 50) {
    led->ligar();
  } else {
    led->desligar();
  }

  Serial.print("Sensor proximidade: ");
  Serial.println(distancia);

  int umidadeSolo = sensorUmidadeSolo->ler();
  Serial.print("Sensor humidade solo: ");
  Serial.println(umidadeSolo);

  int estaChovendo = sensorChuva->ler();
  Serial.print("Sensor chuva: ");
  Serial.println(estaChovendo);

  int luminosidade = sensorLuminosidade->ler();
  Serial.print("Sensor luminosidade: ");
  Serial.println(luminosidade);

  float temperatura = sensorTemperatura->ler();
  Serial.print("Sensor temperatura: ");
  Serial.println(temperatura);

  delay(1000);
}

int receberDados() {
  if (Serial.available()) {
    return Serial.read();
  }

  return -1;
}
