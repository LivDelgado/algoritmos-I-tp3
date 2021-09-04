#include <iostream>

#include "leitura/leitor.hpp"

int main (int argc, char* argv[]) {
    try {

        if (argc < 3) {
            std::cout << "Número de parâmetros insuficiente!" << std::endl;
            std::cout << "Devem ser informados o tipo de tarefa e o caminho do arquivo com os dados das vilas." << std::endl;
            return 1;
        }
        
        leitura::Leitor leitor = leitura::Leitor(argv[1], argv[2]);
        leitor.lerArquivo();
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}