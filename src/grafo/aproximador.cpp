#include "grafo/aproximador.hpp"

using namespace grafo;

Aproximador::Aproximador(std::vector<Trilha> trilhas) {
    this->trilhas = trilhas;
}

std::set<int> Aproximador::getVilasParaConstruirDeposito() {
    Trilha trilha;
    int u, v;

    while (!this->trilhas.empty()) {
        trilha = this->trilhas.front();

        u = trilha.getU();
        v = trilha.getV();

        this->vilasComDeposito.insert(u);
        this->vilasComDeposito.insert(v);

        this->removerTrilhasIncidentesAVilasAdicionadas(u, v);
    }

    return this->vilasComDeposito;
}

void Aproximador::removerTrilhasIncidentesAVilasAdicionadas(int u, int v) {
    std::vector<Trilha> novasTrilhas;

    for (Trilha trilha : this->trilhas) {
        if (trilha.getU() != u && trilha.getU() != v && trilha.getU() != v && trilha.getV() != v) {
            novasTrilhas.push_back(trilha);
        }
    }

    this->trilhas = novasTrilhas;
}