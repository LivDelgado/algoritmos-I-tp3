#include "grafo/trilha.hpp"

using namespace grafo;

Trilha::Trilha() : Trilha(0, 0) {
}

Trilha::Trilha(int u, int v) {
    this->u = u;
    this-> v = v;
}

int Trilha::getU() {
    return this->u;
}

int Trilha::getV() {
    return this->v;
}

void Trilha::setU(int u) {
    this->u = u;
}

void Trilha::setV(int v) {
    this->v = v;
}
