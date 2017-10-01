class Led {
    public:
        Led(int port);
        void registrar();
        void ligar();
        void desligar();

    private:
        int _port;
        bool _ligado;
};
