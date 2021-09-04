#include "grafo/vila.hpp"

using namespace grafo;

Vila::Vila(int indice) {
    this->indice = indice;
}

int Vila::getIndice() {
    return this->indice;
}

int Vila::getGrau() {
    return this->vilasAdjacentes.size();
}

std::vector<Vila> Vila::getVilasAdjacentes() {
    return this->vilasAdjacentes;
}

void Vila::adicionarVilaAdjacente(Vila vilaAdjacente) {
    this->vilasAdjacentes.push_back(vilaAdjacente);
}

bool Vila::operator==(const Vila& vila1) {
    return indice == vila1.indice;
}
