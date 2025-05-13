#include "CMisturaSalmouras.h"

CMisturaSalmouras::CMisturaSalmouras() {}

void CMisturaSalmouras::adicionarSalmoura(const CSalmoura& salmoura) {
    salmouras.push_back(salmoura);
}

double CMisturaSalmouras::getVolumeTotal() const {
    double total = 0.0;
    for (const auto& s : salmouras) {
        total += s.getVolume();
    }
    return total;
}

std::vector<CSalt> CMisturaSalmouras::getTodosSais() const {
    std::vector<CSalt> todos;
    for (const auto& s : salmouras) {
        auto sais = s.getSais();
        todos.insert(todos.end(), sais.begin(), sais.end());
    }
    return todos;
}

std::unordered_map<std::string, double> CMisturaSalmouras::calcularConcentracoesFinais() const {
    std::unordered_map<std::string, double> molsTotais;
    double volumeTotal = getVolumeTotal();

    for (const auto& s : salmouras) {
        auto mols = s.getMapaIonsMols();
        for (const auto& [nome, quantidade] : mols) {
            molsTotais[nome] += quantidade;
        }
    }

    std::unordered_map<std::string, double> concentracoes;
    for (const auto& [nome, mols] : molsTotais) {
        concentracoes[nome] = mols / volumeTotal;
    }

    return concentracoes;
}

std::vector<CSalmoura> CMisturaSalmouras::getSalmouras() const {
    return salmouras;
}

CMisturaSalmouras::~CMisturaSalmouras() {}
