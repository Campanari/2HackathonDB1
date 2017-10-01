#include <ESP8266WiFi.h>
#include "ModuloWifi.h"
#include "Broker.h"

#define LED_PORT LED_BUILTIN
#define SSID "DB1TALK"
#define PASSWORD "12345678"

#define BROKER_MQTT "iot.eclipse.org"
#define BROKER_PORT 1883
#define TOPICO_SUBSCRIBE "AirdDUDV_S"
#define TOPICO_PUBLISH "AirdDUDV_P"
#define ID_MQTT "AirdDUDV"

ModuloWifi* wifi;
WiFiClient client;
Broker broker(client, BROKER_MQTT, BROKER_PORT);

void setup()
{
  Serial.begin(115200);

  wifi = new ModuloWifi("DB1TALK", PASSWORD);
  wifi->conectar();
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

void loop()
{
  wifi->conectar();

  broker.conectar(ID_MQTT, TOPICO_SUBSCRIBE);

  Serial.println("sajhgh");

  if (!broker.conectado()) {
    Serial.println("sajhgh2");
    
    broker.conectar(ID_MQTT, TOPICO_SUBSCRIBE);
  }

  Serial.println("sajhgh3");

  broker.enviar(TOPICO_PUBLISH, "SAMIR VIADO");

  broker.loop();

  delay(1000);
}
