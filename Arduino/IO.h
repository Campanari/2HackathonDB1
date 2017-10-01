#include <SoftwareSerial.h>
#include "Sensores.h"

class IO {
public:
    IO(int inPort, int outPort);
    void registrar();
    bool disponivel();
    void enviar(Sensores sensor, int dados);
    void enviar(Sensores sensor, float dados);
    Sensores receber();

private:
    int _inPort;
    int _outPort;
    SoftwareSerial* _serial;
};
