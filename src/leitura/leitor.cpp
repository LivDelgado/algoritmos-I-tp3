#include "leitura/leitor.hpp"

using namespace leitura;

Leitor::Leitor(std::string tipoTarefa, std::string caminhoArquivo) {
    this->caminhoArquivo = caminhoArquivo;
    this->tipoTarefa = tipoTarefa.back() - '0';

    this->numeroTrilhas = 0;
    this->numeroTrilhas = 0;
    this->trilhas = std::vector<grafo::Trilha*>();
    this->vilas = std::vector<grafo::Vila*>();
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
                inicializarVilas();
            } else {
                if (contador > this->numeroTrilhas) {
                    throw "Número de linhas é maior que o desejado!";
                }
                grafo::Trilha* novaTrilha = new grafo::Trilha(primeiroValor, segundoValor);
                this->trilhas.push_back(novaTrilha);

                this->vilas[primeiroValor]->adicionarVilaAdjacente(this->vilas[segundoValor]);
                this->vilas[segundoValor]->adicionarVilaAdjacente(this->vilas[primeiroValor]);

            }

            contador++;
        }

        arquivo.close();
    }
}

void Leitor::inicializarVilas() {
    for (int i = 0; i < this->numeroVilas; i++) {
        this->vilas.push_back(new grafo::Vila(i));
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

std::vector<grafo::Trilha*> Leitor::getTrilhas() {
    return this->trilhas;
}

std::vector<grafo::Vila*> Leitor::getVilas() {
    return this->vilas;
}
