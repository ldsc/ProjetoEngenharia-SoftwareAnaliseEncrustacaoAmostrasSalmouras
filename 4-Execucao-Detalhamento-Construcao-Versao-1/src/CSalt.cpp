#include "CSalt.h"
#include <cmath>
#include <iostream>

CSalt::CSalt(std::string nome, double kspRef, double deltaH, double temperaturaRef,
             const std::vector<CIon>& ions, const std::vector<int>& coeficientes)
    : name(nome), kspRef(kspRef), deltaH(deltaH), temperaturaRef(temperaturaRef), ions(ions), coeficientes(coeficientes) {}

double CSalt::calculateIonicProduct(const std::unordered_map<std::string, double>& concentracoes) const {
    double Q = 1.0;

    for (size_t i = 0; i < ions.size(); ++i) {
        std::string nomeIon = ions[i].getNome();
        auto it = concentracoes.find(nomeIon);
        if (it != concentracoes.end()) {
            Q *= std::pow(it->second, coeficientes[i]);
        } else {
            std::cerr << "Aviso: concentração para íon " << nomeIon << " não encontrada. Q = 0\n";
            return 0.0;
        }
    }

    return Q;
}

double CSalt::KspCorrigido(double temperatura) const {
    constexpr double R = 8.314;
    double lnK = std::log(kspRef);
    double ajuste = -deltaH / R * (1.0 / temperatura - 1.0 / temperaturaRef);
    return std::exp(lnK + ajuste);
}

bool CSalt::willPrecipitate(const std::unordered_map<std::string, double>& concentracoes, double temperatura) const {
    double Q = calculateIonicProduct(concentracoes);
    double kspAtual = KspCorrigido(temperatura);
    
    return Q > kspAtual;
}

std::string CSalt::getName() const {
    return name;
}

double CSalt::getKsp() const {
    return kspRef;
}

std::vector<CIon> CSalt::getIons() const {
    return ions;
}

std::vector<int> CSalt::getCoeficientes() const {
    return coeficientes;
}

void CSalt::setName(std::string _name) {
    name = _name;
}

void CSalt::setKsp(double _Kps) {
    kspRef = _Kps;
}

void CSalt::setIons(const std::vector<CIon>& _ions) {
    ions = _ions;
}

void CSalt::setCoeficientes(const std::vector<int>& _coef) {
    coeficientes = _coef;
}

CSalt::~CSalt() {}
