#include "Arduino.h"
#include "IO.h"

IO::IO(int inPort, int outPort) {
    _inPort = inPort;
    _outPort = outPort;
}

void IO::registrar() {
    _serial = new SoftwareSerial(_inPort, _outPort);
}

bool IO::disponivel() {
    return _serial->available();
}

void IO::enviar(Sensores sensor, int dados) {
    _serial->print("Sensor ");
    _serial->print(sensor);
    _serial->print(": ");
    _serial->println(dados);
}

void IO::enviar(Sensores sensor, float dados) {
    _serial->print("Sensor ");
    _serial->print(sensor);
    _serial->print(": ");
    _serial->println(dados);
}

Sensores IO::receber() {
  return (Sensores)_serial->read();
}
