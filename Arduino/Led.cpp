#include "Arduino.h"
#include "Led.h"

Led::Led(int port) {
    _port = port;
    _ligado = false;
};

void Led::registrar() {
    pinMode(_port, OUTPUT);
}

void Led::ligar() {
    if (_ligado) {
        return;
    }

    digitalWrite(_port, HIGH);

    _ligado = true;
}

void Led::desligar() {
    if (!_ligado) {
        return;
    }
    
    digitalWrite(_port, LOW);

    _ligado = false;
}
