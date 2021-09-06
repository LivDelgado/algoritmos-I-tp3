#include <iostream>

#include "leitura/leitor.hpp"
#include "grafo/resolvedor.hpp"
#include "grafo/vila.hpp"
#include "grafo/aproximador.hpp"

#include <vector>
#include <set>

#include <time.h>

int executarPrograma (int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Número de parâmetros insuficiente!" << std::endl;
        std::cout << "Devem ser informados o tipo de tarefa e o caminho do arquivo com os dados das vilas." << std::endl;
        return 1;
    }
    
    leitura::Leitor leitor = leitura::Leitor(argv[1], argv[2]);
    leitor.lerArquivo();

    grafo::Resolvedor resolvedor = grafo::Resolvedor(leitor.getTrilhas(), leitor.getVilas());
    std::vector<grafo::Vila*> vilas = resolvedor.getVilasParaConstruirDeposito();

    //std::cout << vilas.size() << std::endl;

    if (leitor.getTipoTarefa() == 2) {
        for (grafo::Vila* vila : vilas) {
            std::cout << vila->getIndice() << std::endl;
        }
    }

    return 0;
}


int main (int argc, char* argv[]) {
    try {
        clock_t t;
        t = clock();

        int resultado = executarPrograma(argc, argv);

        t = clock() - t;

        std::cout << "Tempo de execução: " << ((float)t)/CLOCKS_PER_SEC << " segundos" << std::endl;

        return resultado;

    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}