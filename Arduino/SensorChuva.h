class SensorChuva {
public:
    SensorChuva(int port);
    void registrar();
    bool ler();

private:
    int _port;
};
