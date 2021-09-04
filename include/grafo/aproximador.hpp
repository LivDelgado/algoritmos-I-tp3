#ifndef APROXIMADOR
#define APROXIMADOR

#include <set>
#include <vector>

#include "grafo/trilha.hpp"

namespace grafo {
    class Aproximador {
        private:
            std::set<int> vilasComDeposito;
            std::vector<Trilha> trilhas;

            void removerTrilhasIncidentesAVilasAdicionadas(int u, int v);

        public:
            Aproximador(std::vector<Trilha> trilhas);

            std::set<int> getVilasParaConstruirDeposito();
    };
}

#endif