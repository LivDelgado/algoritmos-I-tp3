#ifndef VILA
#define VILA

#include <vector>

namespace grafo {
    class Vila {
        private:
            int indice;
            bool deletada;
            std::vector<Vila*> vilasAdjacentes;

        public:
            Vila(int indice);

            void setDeletada(bool deletada);

            int getIndice();
            bool getDeletada();
            int getGrau();
            std::vector<Vila*> getVilasAdjacentes();
            
            void adicionarVilaAdjacente(Vila* vilaAdjacente);

            bool operator==(const Vila&);
    };
}

#endif