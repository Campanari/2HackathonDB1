#include "Arduino.h"
#include "SensorUmidadeSolo.h"

SensorUmidadeSolo::SensorUmidadeSolo(int port, int switchPort) {
    _port = port;
    _switchPort = switchPort;
}

void SensorUmidadeSolo::registrar() {
    pinMode(_port, INPUT);
    pinMode(_switchPort, OUTPUT);

    digitalWrite(_switchPort, LOW);
}

int SensorUmidadeSolo::ler() {
    digitalWrite(_switchPort, HIGH);

    delay(500);

    int valor = analogRead(_port);

    digitalWrite(_switchPort, LOW);

    return 1023 - valor;
}
