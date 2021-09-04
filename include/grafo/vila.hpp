#ifndef VILA
#define VILA

#include <vector>

namespace grafo {
    class Vila {
        private:
            int indice;
            std::vector<Vila> vilasAdjacentes;

        public:
            Vila(int indice);

            int getIndice();
            int getGrau();
            std::vector<Vila> getVilasAdjacentes();
            
            void adicionarVilaAdjacente(Vila vilaAdjacente);

            bool operator==(const Vila&);
    };
}

#endif