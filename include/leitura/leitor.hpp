#ifndef LEITOR
#define LEITOR

#include <string>
#include <vector>
#include <string>
#include <fstream>

#include "grafo/vertice.hpp"

namespace leitura {
    class Leitor {
        private:
            std::string caminhoArquivo;
            int tipoTarefa;
            int numeroVertices;
            int numeroTrilhas;
            std::vector<grafo::Vertice> vertices;

        public:
            Leitor(std::string tipoTarefa, std::string caminhoArquivo);

            void lerArquivo();

            int getTipoTarefa();
            int getNumeroVertices();
            int getNumeroTrilhas();
            std::vector<grafo::Vertice> getVertices();
    };

}

#endif