#include "Arduino.h"
#include <Thermistor.h> 
#include "SensorTemperatura.h"

SensorTemperatura::SensorTemperatura(int port) {
    _port = port;
}

SensorTemperatura::registrar() {
    pinMode(_port, INPUT);

    _thermistor = new Thermistor(_port);
}

int SensorTemperatura::ler() {
    return _thermistor->getTemp();
}
