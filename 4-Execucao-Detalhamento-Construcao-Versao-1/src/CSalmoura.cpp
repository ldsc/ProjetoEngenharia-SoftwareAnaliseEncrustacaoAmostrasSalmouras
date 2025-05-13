#include "CSalmoura.h"

CSalmoura::CSalmoura()
    : quantidadeLiquido(1.0) {}

CSalmoura::CSalmoura(double volume)
    : quantidadeLiquido(volume) {}

void CSalmoura::adicionarIon(const std::string& nomeIon, double quantidade) {
    concentracoesMols[nomeIon] += quantidade;
}

void CSalmoura::adicionarSal(const CSalt& sal) {
    sais.push_back(sal);
}

std::unordered_map<std::string, double> CSalmoura::getMapaIonsMols() const {
    return concentracoesMols;
}

double CSalmoura::getVolume() const {
    return quantidadeLiquido;
}

void CSalmoura::setVolume(double volume) {
    quantidadeLiquido = volume;
}

std::vector<CSalt> CSalmoura::getSais() const {
    return sais;
}

CSalmoura::~CSalmoura() {}
