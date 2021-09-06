#ifndef RESOLVEDOR
#define RESOLVEDOR

#include <vector>
#include <map>
#include <algorithm>

#include "grafo/trilha.hpp"
#include "grafo/vila.hpp"

namespace grafo {
    class Resolvedor {
        private:
            std::vector<Trilha*> trilhas;
            std::vector<Vila*> vilas;

            std::vector<Vila*> vilasOrdenadas;

            std::vector<Vila*> vilasComDeposito;

            void ordenarVilasPeloNumeroDeTrilhas();
            void selecionarVilasParaConstruirDeposito();

            bool vilaExiste(Vila* vila);
            std::vector<Vila*>::iterator encontrarIndiceVila(Vila* vila);
            void resolver();
        
        public:
            Resolvedor(std::vector<Trilha*> trilhas, std::vector<Vila*> vilas);

            std::vector<Vila*> getVilasParaConstruirDeposito();
    };
}

#endif