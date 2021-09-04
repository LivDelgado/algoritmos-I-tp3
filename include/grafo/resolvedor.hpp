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
            std::vector<Trilha> trilhas;
            std::vector<Vila> vilas;

            std::vector<Vila> vilasOrdenadas;

            void resolverVilasAdjacentes();
            void ordenarVilasPeloNumeroDeTrilhas();
            void selecionarVilasParaConstruirDeposito();

            bool vilaExiste(Vila vila);
            std::vector<Vila>::iterator encontrarIndiceVila(Vila vila);
            void resolver();
        
        public:
            Resolvedor(std::vector<Trilha> trilhas, int numeroVilas);

            std::vector<Vila> getVilasParaConstruirDeposito();
    };
}

#endif