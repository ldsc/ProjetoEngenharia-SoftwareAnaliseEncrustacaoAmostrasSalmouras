#include "CMisturaSalmouras.h"

CMisturaSalmouras::CMisturaSalmouras() {}

void CMisturaSalmouras::adicionarSalmoura(const CSalmoura& salmoura) {
    salmouras.push_back(salmoura);
}

std::unordered_map<std::string, double> CMisturaSalmouras::calcularConcentracoesFinais() const {
    std::unordered_map<std::string, double> acumulado;
    double totalVolume = 0.0;

    for (const auto& s : salmouras) {
        const auto mapa = s.getMapaIonsMols();
        double v = s.getVolume();
        totalVolume += v;

        for (const auto& [ion, mols] : mapa) {
            acumulado[ion] += mols;
        }
    }

    for (auto& [ion, totalMols] : acumulado) {
        totalMols /= totalVolume;
    }

    return acumulado;
}

const std::vector<CSalmoura>& CMisturaSalmouras::getSalmouras() const {
    return salmouras;
}

CMisturaSalmouras::~CMisturaSalmouras() {}
