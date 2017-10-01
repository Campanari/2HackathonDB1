#include "Arduino.h"
#include "SensorChuva.h"

SensorChuva::SensorChuva(int port) {
    _port = port;
}

void SensorChuva::registrar() {
    pinMode(_port, INPUT);
}

bool SensorChuva::ler() {
    return digitalRead(_port) > 0;
}
