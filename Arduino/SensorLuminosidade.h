class SensorLuminosidade {
public:
    SensorLuminosidade(int port);
    registrar();
    int ler();

private:
    int _port;
};