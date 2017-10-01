#include "Sensores.h"
#include "Abastecimento.h"
#include "Planta.h"
#include "Dashboard.h"

class IO {
  public:
    struct Retorno {
      Sensores sensor;
      
      char* resultado;
    };
  
    IO();
    bool disponivel();
    void enviar(Sensores sensor, int dados);
    void enviar(Sensores sensor);
    Dashboard obterDashboard();
    Planta obterPlanta(int id);
    Abastecimento obterAbastecimento();

  private:
    
};

