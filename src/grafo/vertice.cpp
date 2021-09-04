#include "grafo/vertice.hpp"

using namespace grafo;

Vertice::Vertice() : Vertice(0, 0) {
}

Vertice::Vertice(int u, int v) {
    this->u = u;
    this-> v = v;
}

int Vertice::getU() {
    return this->u;
}

int Vertice::getV() {
    return this->v;
}

void Vertice::setU(int u) {
    this->u = u;
}

void Vertice::setV(int v) {
    this->v = v;
}
