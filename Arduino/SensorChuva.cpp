#include "Arduino.h"
#include "SensorChuva.h"

SensorChuva::SensorChuva(int port) {
    _port = port;
}

SensorChuva::registrar() {
    pinMode(_port, INPUT);
}

int SensorChuva::ler() {
    return digitalRead(_port);
}
