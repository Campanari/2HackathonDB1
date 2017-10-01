#include <Thermistor.h> 

class SensorTemperatura {
public:
    SensorTemperatura(int port);
    void registrar();
    int ler();

private:
    int _port;
    Thermistor* _thermistor;
};
