#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class Broker {
  public:
    Broker(WiFiClient client, const char* mqtt, uint16_t port);
    void conectar(const char* id, const char* topico);
    bool conectado();
    void enviar(const char* topico, const char* dados);
    void receber();
    void loop();

  private:
    PubSubClient* _client;
    const char* _mqtt;
    uint16_t _port;
};

