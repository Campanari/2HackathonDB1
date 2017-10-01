#include "Broker.h"
#include <ESP8266WiFi.h>

void mqtt_callback(char* topic, byte* payload, unsigned int length);

Broker::Broker(WiFiClient client, const char* mqtt,uint16_t port) {
  _mqtt = mqtt;
  _port = port;

  _client = new PubSubClient(client);

  Serial.println(_mqtt);
  Serial.println(_port);

  _client->setServer(_mqtt, _port);
  _client->setCallback(mqtt_callback); 
}

void Broker::conectar(const char* id, const char* topico) {
  while (!conectado()) {
      Serial.println("Não conectado ao Broker");
    
      Serial.println(id);
          
      if (_client->connect(id)) {
          Serial.println("Conectado ao Broker");
          Serial.println(topico);
          
          _client->subscribe(topico); 

          Serial.println("Tópico OK");
      } else {
          delay(2000);
      }
  }

  Serial.println("Conectado ao Broker");
}

bool Broker::conectado() {
  return _client->connected();
}

void Broker::enviar(const char* topico, const char* dados) {
  _client->publish(topico, dados);

  Serial.println("Enviado");

  delay(1000);
}

void Broker::loop() {
  _client->loop();
}

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  String msg;

  //obtem a string do payload recebido
  for(int i = 0; i < length; i++) 
  {
    char c = (char)payload[i];
    msg += c;
  }

  if (msg.equals("L"))
  {
      //digitalWrite(D0, LOW);
      //EstadoSaida = '1';
  }

  //verifica se deve colocar nivel alto de tensão na saída D0:
  if (msg.equals("D"))
  {
      //digitalWrite(D0, HIGH);
      //EstadoSaida = '0';
  } 
}
