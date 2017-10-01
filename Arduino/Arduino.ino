#include "Led.h"
#include "Sensores.h"
#include "SensorProximidade.h"
#include "SensorUmidadeSolo.h"
#include "SensorChuva.h"
#include "SensorLuminosidade.h"
#include "SensorTemperatura.h"
#include "IO.h"

#define LED_PORT 12
#define SENSOR_P_TRIGGER_PORT 4
#define SENSOR_P_ECHO_PORT 5
#define SENSOR_U_S_PORT 6
#define SENSOR_U_S_SWITCH_PORT 6
#define SENSOR_U_S_PORT A0
#define SENSOR_C_PORT 8
#define SENSOR_L_PORT 2
#define SENSOR_T_PORT 3

Led* led;
SensorProximidade* sensorProximidade;
SensorUmidadeSolo* sensorUmidadeSolo;
SensorChuva* sensorChuva;
SensorLuminosidade* sensorLuminosidade;
SensorTemperatura* sensorTemperatura;
IO* io;

void setup(void) {
  
  Serial.begin(115200);

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

  io = new IO(10, 11);
}

void loop(void) {
  led->desligar();

  if (io->disponivel()) {    
    Sensores sensor = io->receber();

    if ((sensor & Sensores::Chuva) == Sensores::Chuva) {
      bool estaChovendo = sensorChuva->ler();
      Serial.print("Sensor chuva: ");
      Serial.println(estaChovendo);

      io->enviar(Sensores::Chuva, estaChovendo);

      led->ligar();    
    }

    if ((sensor & Sensores::Luminosidade) == Sensores::Luminosidade) {
      int luminosidade = sensorLuminosidade->ler();
      Serial.print("Sensor luminosidade: ");
      Serial.println(luminosidade);
      
      io->enviar(Sensores::Luminosidade, luminosidade);

      led->ligar();  
    }

    if ((sensor & Sensores::Proximidade) == Sensores::Proximidade) {
      int distancia = sensorProximidade->ler();
      Serial.print("Sensor proximidade: ");
      Serial.println(distancia);          
      
      io->enviar(Sensores::Proximidade, distancia);

      led->ligar();  
    }

    if ((sensor & Sensores::Temperatura) == Sensores::Temperatura) {
      float temperatura = sensorTemperatura->ler();
      Serial.print("Sensor temperatura: ");
      Serial.println(temperatura);      
      
      io->enviar(Sensores::Temperatura, temperatura);

      led->ligar();  
    }

    if ((sensor & Sensores::UmidadeSolo) == Sensores::UmidadeSolo) {
      int umidadeSolo = sensorUmidadeSolo->ler();
      Serial.print("Sensor humidade solo: ");
      Serial.println(umidadeSolo);      
      
      io->enviar(Sensores::UmidadeSolo, umidadeSolo);

      led->ligar();  
    }
  }

  delay(1000);
}
