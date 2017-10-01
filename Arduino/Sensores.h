#ifndef SENSORES_H
#define SENSORES_H

enum Sensores {
    Nenhum = 0,
    Chuva = 1,
    Luminosidade = 2,
    Proximidade = 4,
    Temperatura = 8,
    UmidadeSolo = 16,
    Todos = Chuva | Luminosidade | Proximidade | Temperatura | UmidadeSolo
};
#endif
