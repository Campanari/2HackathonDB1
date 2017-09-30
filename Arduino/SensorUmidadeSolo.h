class SensorUmidadeSolo {
public:
    SensorUmidadeSolo(int port);
    registrar();
    int ler();

private:
    int _port;
};