#include <ESP8266WiFi.h>
#include "ModuloWifi.h"
#include "Broker.h"
#include "IO.h"

#define LED_PORT LED_BUILTIN
#define SSID "DB1TALK"
#define PASSWORD "12345678"

#define BROKER_MQTT "iot.eclipse.org"
#define BROKER_PORT 1883
#define TOPICO_SUBSCRIBE "comandos"
#define TOPICO_PUBLISH "consultas"
#define COMANDO_DASHBOARD "DASHBOARD"
#define COMANDO_PLANTA "PLANTA"
#define COMANDO_ABASTECIMENTO "ABASTECIMENTO"
#define COMANDO_ABRIR "ABRIR"
#define COMANDO_FECHAR "FECHAR"
#define COMANDO_AGUAR "AGUAR"
#define ID_MQTT "AirDUDV"

void mqtt_callback(char* topic, byte* payload, unsigned int length);

ModuloWifi* wifi;
WiFiClient client;
Broker broker(client, BROKER_MQTT, BROKER_PORT);
IO* io;

void setup()
{
  Serial.begin(115200);

  wifi = new ModuloWifi("DB1TALK", PASSWORD);
  wifi->conectar();

  broker.getClient()->setCallback(mqtt_callback);

  io = new IO();
}

//Função: envia ao Broker o estado atual do output
//Parâmetros: nenhum
//Retorno: nenhum
//void EnviaEstadoOutputMQTT(void)
//{
//    if (EstadoSaida == '0')
//      MQTT.publish(TOPICO_PUBLISH, "D");
//
//    if (EstadoSaida == '1')
//      MQTT.publish(TOPICO_PUBLISH, "L");
//
//    Serial.println("- Estado da saida D0 enviado ao broker!");
//    delay(1000);
//}

String executarComando;

void loop()
{
  wifi->conectar();

  if (executarComando == COMANDO_DASHBOARD) {
    
  } else if (executarComando == COMANDO_PLANTA) {
    executarComando = "";

    Planta planta = io->obterPlanta(1);

    if (!broker.conectado()) {
      broker.conectar(ID_MQTT, TOPICO_SUBSCRIBE);
    }
  
    Serial.println("sajhgh3");
  
    broker.enviar(TOPICO_PUBLISH, planta.retorno);
  } else if (executarComando == COMANDO_ABASTECIMENTO) {
    
  } else if (executarComando == COMANDO_AGUAR) {
    
  } else if (executarComando == COMANDO_FECHAR) {
    
  } else if (executarComando == COMANDO_ABRIR) {
    
  }

  broker.loop();

  delay(1000);
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  String comando;

  for (int i = 0; i < length; i++) {
    comando += (char)payload[i];
  }

  Serial.println(comando);

  executarComando = comando;
}
