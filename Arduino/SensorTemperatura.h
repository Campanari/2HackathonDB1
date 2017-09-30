#include <Thermistor.h> 

class SensorTemperatura {
public:
    SensorTemperatura(int port);
    registrar();
    int ler();

private:
    int _port;
    Thermistor* _thermistor;
};
