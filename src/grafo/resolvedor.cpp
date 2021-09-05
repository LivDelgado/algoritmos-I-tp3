#include "grafo/resolvedor.hpp"

using namespace grafo;

Resolvedor::Resolvedor(std::vector<Trilha> trilhas, int numeroVilas) {
    this->trilhas = trilhas;

    for (int i = 0; i < numeroVilas; i++) {
        this->vilas.push_back(Vila(i));
    }

}

void Resolvedor::resolver() {
    this->resolverVilasAdjacentes();
    this->ordenarVilasPeloNumeroDeTrilhas();
    this->selecionarVilasParaConstruirDeposito();
}

void Resolvedor::resolverVilasAdjacentes() {
    int u = 0;
    int v = 0;

    for (Trilha trilha : this->trilhas) {
        u = trilha.getU();
        v = trilha.getV();

        this->vilas.at(u).adicionarVilaAdjacente(this->vilas.at(v));
        this->vilas.at(v).adicionarVilaAdjacente(this->vilas.at(u));

    }
}

bool compararVilaPeloGrau (Vila u, Vila v) {
    return (u.getGrau() < v.getGrau());
}

bool compararVilaPeloIndice (Vila u, Vila v) {
    return (u.getIndice() < v.getIndice());
}

void Resolvedor::ordenarVilasPeloNumeroDeTrilhas() {
    std::stable_sort(this->vilas.begin(), this->vilas.end(), compararVilaPeloGrau);
    this->vilasOrdenadas = this->vilas;
}

void Resolvedor::selecionarVilasParaConstruirDeposito() {
    bool deletarVila = true;

    for (Vila vila : this->vilasOrdenadas) {
        deletarVila = true;

        // deletar a vila se todas as vilas adjacentes ainda estão na lista
        for (Vila vilaAdjacente : vila.getVilasAdjacentes()) {
            bool vilaExiste = this->vilaExiste(vilaAdjacente);

            if (!vilaExiste) {
                deletarVila = false;
                break;
            }
        }

        if (deletarVila) {
            this->vilas.erase(encontrarIndiceVila(vila));
        }
    }
}

bool Resolvedor::vilaExiste(Vila vila) {
    return encontrarIndiceVila(vila) != this->vilas.end();
}

std::vector<Vila>::iterator Resolvedor::encontrarIndiceVila(Vila vila) {
    std::vector<Vila>::iterator it = std::find(this->vilas.begin(), this->vilas.end(), vila);
    return it;
}

std::vector<Vila> Resolvedor::getVilasParaConstruirDeposito() {
    this->resolver();
    std::sort(this->vilas.begin(), this->vilas.end(), compararVilaPeloIndice);
    return this->vilas;
}
