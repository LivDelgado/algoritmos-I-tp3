#include "leitura/leitor.hpp"

using namespace leitura;

Leitor::Leitor(std::string tipoTarefa, std::string caminhoArquivo) {
    this->caminhoArquivo = caminhoArquivo;
    this->tipoTarefa = tipoTarefa.back() - '0';

    this->numeroTrilhas = 0;
    this->numeroTrilhas = 0;
    this->trilhas = std::vector<grafo::Trilha>();
}

void Leitor::lerArquivo() {
    std::ifstream arquivo(this->caminhoArquivo);
    std::string linha;

    int primeiroValor;
    int segundoValor;

    int contador = 0;

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            int indiceEspaco = linha.find(' ');
            primeiroValor = std::stoi(linha.substr(0, indiceEspaco));
            segundoValor = std::stoi(linha.substr(indiceEspaco));

            if (contador == 0) {
                this->numeroVilas = primeiroValor;
                this->numeroTrilhas = segundoValor;
            } else {
                if (contador > this->numeroTrilhas) {
                    throw "Número de linhas é maior que o desejado!";
                }
                grafo::Trilha novaTrilha = grafo::Trilha(primeiroValor, segundoValor);
                this->trilhas.push_back(novaTrilha);
            }

            contador++;
        }

        arquivo.close();
    }
}

int Leitor::getTipoTarefa() {
    return this->tipoTarefa;
}

int Leitor::getNumeroVilas() {
    return this->numeroVilas;
}

int Leitor::getNumeroTrilhas() {
    return this->numeroTrilhas;
}

std::vector<grafo::Trilha> Leitor::getTrilhas() {
    return this->trilhas;
}
