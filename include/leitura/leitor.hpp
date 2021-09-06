#ifndef LEITOR
#define LEITOR

#include <string>
#include <vector>
#include <string>
#include <fstream>

#include "grafo/trilha.hpp"
#include "grafo/vila.hpp"

namespace leitura {
    class Leitor {
        private:
            std::string caminhoArquivo;
            int tipoTarefa;
            int numeroTrilhas;
            int numeroVilas;
            std::vector<grafo::Trilha*> trilhas;
            std::vector<grafo::Vila*> vilas;

            void inicializarVilas();

        public:
            Leitor(std::string tipoTarefa, std::string caminhoArquivo);

            void lerArquivo();

            int getTipoTarefa();
            int getNumeroVilas();
            int getNumeroTrilhas();
            std::vector<grafo::Trilha*> getTrilhas();
            std::vector<grafo::Vila*> getVilas();
    };

}

#endif