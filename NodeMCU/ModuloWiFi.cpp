#include "ModuloWifi.h"
#include <ESP8266WiFi.h>

ModuloWifi::ModuloWifi(const char* ssid, const char* senha) {
    _ssid = ssid;
    _senha = senha;
}

void ModuloWifi::conectar() {
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }

    WiFi.begin(_ssid, _senha);

    while (WiFi.status() != WL_CONNECTED) 
    {
        delay(100);
    }

    Serial.println("Conectado");
    Serial.println(WiFi.localIP());
}

void ModuloWifi::desconectar() {
    
}

int ModuloWifi::obterStatus() {
    return WiFi.status();
}
