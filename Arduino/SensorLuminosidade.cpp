#include "Arduino.h"
#include "SensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade(int port) {
    _port = port;
}

SensorLuminosidade::registrar() {
    pinMode(_port, INPUT);
}

int SensorLuminosidade::ler() {
    return 1023 - analogRead(_port);
}
