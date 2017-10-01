#include "ModuloWifi.h"
#include "Broker.h"

#define LED_PORT LED_BUILTIN
#define SSID_ "DB1TALK"
#define PASSWORD "12345678"

#define BROKER_MQTT "iot.eclipse.org"
#define BROKER_PORT 1883
#define TOPICO_SUBSCRIBE "AirdDUDV_S"
#define TOPICO_PUBLISH "AirdDUDV_P"
#define ID_MQTT "AirdDUDV"

ModuloWifi* wifi;
Broker* broker;

void setup() 
{
  Serial.begin(115200);
  
  wifi = new ModuloWifi(SSID_, PASSWORD);
  broker = new Broker(BROKER_MQTT, BROKER_PORT);
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
  
    if (!broker->conectado()) {
        broker->conectar(ID_MQTT, TOPICO_SUBSCRIBE);
    }

    //EnviaEstadoOutputMQTT();
 
    broker->loop();
}
