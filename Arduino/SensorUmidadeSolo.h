class SensorUmidadeSolo {
public:
    SensorUmidadeSolo(int port, int switchPort);
    registrar();
    int ler();

private:
    int _port;
    int _switchPort;
};