#include "Arduino.h"
#include "Led.h"

Led::Led(int port) {
    this->_port = port;
};

void Led::registrar() {
    pinMode(_port, OUTPUT);
}

void Led::ligar() {
    digitalWrite(_port, HIGH);

    Serial.println("ligado");
}

void Led::desligar() {
    digitalWrite(_port, LOW);

    Serial.println("desligado");
}
