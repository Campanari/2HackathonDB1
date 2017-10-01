#include "Arduino.h"
#include "SensorProximidade.h"

SensorProximidade::SensorProximidade(int triggerPort, int echoPort) {
    _triggerPort = triggerPort;
    _echoPort = echoPort;
}

void SensorProximidade::registrar() {
    _ultrasonic = new Ultrasonic(_triggerPort, _echoPort);
}

int SensorProximidade::ler() {
    return (int)_ultrasonic->convert(_ultrasonic->timing(), Ultrasonic::CM);
}
