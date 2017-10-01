class ModuloWifi {
public:
    ModuloWifi(const char* ssid, const char* senha);
    void conectar();
    void desconectar();
    int obterStatus();

private:
    const char* _ssid;
    const char* _senha;
};
