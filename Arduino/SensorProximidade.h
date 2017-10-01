#include <Ultrasonic.h>

class SensorProximidade {
public:
    SensorProximidade(int triggerPort, int echoPort);
    void registrar();
    int ler();

private:
    int _triggerPort;
    int _echoPort;
    Ultrasonic* _ultrasonic;
};
