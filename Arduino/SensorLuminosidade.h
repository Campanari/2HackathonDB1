class SensorLuminosidade {
public:
    SensorLuminosidade(int port);
    void registrar();
    int ler();

private:
    int _port;
};
