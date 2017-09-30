class Led {
    public:
        Led(int port);
        registrar();
        ligar();
        desligar();

    private:
        int _port;
};
