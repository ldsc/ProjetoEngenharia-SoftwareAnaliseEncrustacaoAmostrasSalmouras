#include "CSalmoura.h"

CSalmoura::CSalmoura()
    : quantidadeLiquido(1.0) {}

CSalmoura::CSalmoura(double volume)
    : quantidadeLiquido(volume) {}

void CSalmoura::adicionarIon(const std::string& nomeIon, double mols) {
    concentracoesMols[nomeIon] += mols;
}

void CSalmoura::DefinirCondicoes(double temperaturaK, double pressaoAtm) {
    temperatura = temperaturaK;
    pressao = pressaoAtm;
}

std::unordered_map<std::string, double> CSalmoura::getMapaIonsMols() const {
    return concentracoesMols;
}

double CSalmoura::getVolume() const {
    return quantidadeLiquido;
}

double CSalmoura::getTemperatura() const
{
    return temperatura;
}

void CSalmoura::setVolume(double volume) {
    quantidadeLiquido = volume;
}

CSalmoura::~CSalmoura() {}
