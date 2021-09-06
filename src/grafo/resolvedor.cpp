#include "grafo/resolvedor.hpp"

using namespace grafo;

bool compararVilaPeloGrau (Vila* u, Vila* v) {
    return (u->getGrau() < v->getGrau());
}

bool compararVilaPeloIndice (Vila* u, Vila* v) {
    return (u->getIndice() < v->getIndice());
}


Resolvedor::Resolvedor(std::vector<Trilha*> trilhas, std::vector<Vila*> vilas) {
    this->trilhas = trilhas;
    this->vilas = vilas;
    this->vilasComDeposito = std::vector<grafo::Vila*>();
}

void Resolvedor::resolver() {
    this->ordenarVilasPeloNumeroDeTrilhas();
    this->selecionarVilasParaConstruirDeposito();
}

void Resolvedor::ordenarVilasPeloNumeroDeTrilhas() {
    this->vilasOrdenadas = this->vilas;
    std::sort(this->vilasOrdenadas.begin(), this->vilasOrdenadas.end(), compararVilaPeloGrau);
}

void Resolvedor::selecionarVilasParaConstruirDeposito() {
    bool deletada = true;

    for (Vila* vila : this->vilasOrdenadas) {
        deletada = true;
        // deletar a vila se todas as vilas adjacentes ainda estão na lista
        for (Vila* vilaAdjacente : vila->getVilasAdjacentes()) {
            bool vilaExiste = this->vilaExiste(vilaAdjacente);

            if (!vilaExiste) {
                deletada = false;
                this->vilasComDeposito.push_back(vila);
                break;
            }
        }

        vila->setDeletada(deletada);
    }
}

bool Resolvedor::vilaExiste(Vila* vila) {
    return !this->vilas[vila->getIndice()]->getDeletada();
}

std::vector<Vila*>::iterator Resolvedor::encontrarIndiceVila(Vila* vila) {
    std::vector<Vila*>::iterator it = std::find(this->vilas.begin(), this->vilas.end(), vila);
    return it;
}

std::vector<Vila*> Resolvedor::getVilasParaConstruirDeposito() {
    this->resolver();
    std::sort(this->vilasComDeposito.begin(), this->vilasComDeposito.end(), compararVilaPeloIndice);
    return this->vilasComDeposito;
}
