#include <iostream>

#include "leitura/leitor.hpp"
#include "grafo/resolvedor.hpp"
#include "grafo/vila.hpp"
#include "grafo/aproximador.hpp"

#include <vector>
#include <set>

int main (int argc, char* argv[]) {
    try {

        if (argc < 3) {
            std::cout << "Número de parâmetros insuficiente!" << std::endl;
            std::cout << "Devem ser informados o tipo de tarefa e o caminho do arquivo com os dados das vilas." << std::endl;
            return 1;
        }
        
        leitura::Leitor leitor = leitura::Leitor(argv[1], argv[2]);
        leitor.lerArquivo();

        //if (leitor.getTipoTarefa() == 1) {
            grafo::Resolvedor resolvedor = grafo::Resolvedor(leitor.getTrilhas(), leitor.getNumeroVilas());
            std::vector<grafo::Vila> vilas = resolvedor.getVilasParaConstruirDeposito();

            std::cout << vilas.size() << std::endl;
        /*
        } else {
            grafo::Aproximador aproximador = grafo::Aproximador(leitor.getTrilhas());
            std::set<int> vilas = aproximador.getVilasParaConstruirDeposito();

            std::cout << vilas.size() << std::endl;
            for (grafo::Vila vila : vilas) {
                std::cout << vila.getIndice() << std::endl;
            }
        }*/

        if (leitor.getTipoTarefa() == 2) {
            for (grafo::Vila vila : vilas) {
                std::cout << vila.getIndice() << std::endl;
            }
        }
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}