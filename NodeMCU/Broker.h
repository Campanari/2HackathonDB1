#include <PubSubClient.h>

class Broker {
  public:
    Broker(const char* mqtt, uint16_t port);
    void connectar(const char* id, const char* topico);
    bool conectado();
    void enviar(char* topico, char* dados);
    void receber();
    void loop();

  private:
    PubSubClient* _client;
    const char* _mqtt;
    uint16_t _port;
};

