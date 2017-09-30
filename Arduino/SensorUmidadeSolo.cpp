#include "Arduino.h"
#include "SensorUmidadeSolo.h"

SensorUmidadeSolo::SensorUmidadeSolo(int port) {
    _port = port;
}

SensorUmidadeSolo::registrar() {
    pinMode(_port, INPUT);
}

int SensorUmidadeSolo::ler() {
    return digitalRead(_port);
}
