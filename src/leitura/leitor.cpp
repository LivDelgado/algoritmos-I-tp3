#include "leitura/leitor.hpp"

using namespace leitura;

Leitor::Leitor(std::string tipoTarefa, std::string caminhoArquivo) {
    this->caminhoArquivo = caminhoArquivo;
    this->tipoTarefa = tipoTarefa.back() - '0';

    this->numeroVertices = 0;
    this->numeroTrilhas = 0;
    this->vertices = std::vector<grafo::Vertice>();
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
                this->numeroVertices = primeiroValor;
                this->numeroTrilhas = segundoValor;
            } else {
                if (contador > this->numeroTrilhas) {
                    throw "Número de linhas é maior que o desejado!";
                }
                grafo::Vertice novoVertice = grafo::Vertice(primeiroValor, segundoValor);
                this->vertices.push_back(novoVertice);
            }

            contador++;
        }

        arquivo.close();
    }
}

int Leitor::getTipoTarefa() {
    return this->tipoTarefa;
}

int Leitor::getNumeroVertices() {
    return this->numeroVertices;
}

int Leitor::getNumeroTrilhas() {
    return this->numeroTrilhas;
}

std::vector<grafo::Vertice> Leitor::getVertices() {
    return this->vertices;
}
