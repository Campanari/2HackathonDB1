class SensorChuva {
public:
    SensorChuva(int port);
    registrar();
    int ler();

private:
    int _port;
};