#include <SoftwareSerial.h>
#include "Sensores.h"

class IO {
public:
    IO(int inPort, int outPort);
    registrar();
    enviar(Sensores sensor,int dados);
    Sensores receber();

private:
    int _inPort;
    int _outPort;
    SoftwareSerial* _serial;
};
