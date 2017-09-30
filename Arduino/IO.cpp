#include "Arduino.h"
#include "IO.h"

IO::IO(int inPort, int outPort) {
    _inPort = inPort;
    _outPort = outPort;
}

IO::registrar() {
    _serial = new SoftwareSerial(_inPort, _outPort);
}

IO::enviar(Sensores sensor, int dados) {
    _serial->print("");
}

Sensores IO::receber() {

}
