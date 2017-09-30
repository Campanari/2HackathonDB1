#include "Arduino.h"
#include "Led.h"

Led::Led(int port) {
    this->_port = port;
};

Led::registrar() {
    pinMode(_port, OUTPUT);
}

Led::ligar() {
    digitalWrite(_port, HIGH);

    Serial.println("ligado");
}

Led::desligar() {
    digitalWrite(_port, LOW);

    Serial.println("desligado");
}
