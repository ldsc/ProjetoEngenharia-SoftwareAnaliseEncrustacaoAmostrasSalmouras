#include "CSalt.h"
#include <cmath>
#include <iostream>

CSalt::CSalt()
    : name(""), Ksp(0.0), ions(), coeficientes() {}

CSalt::CSalt(std::string nome, double ksp, const std::vector<CIon>& ions_, const std::vector<int>& coef_)
    : name(nome), Ksp(ksp), ions(ions_), coeficientes(coef_) {}

double CSalt::calculateIonicProduct(const std::unordered_map<std::string, double>& concentracoes) const {
    double Q = 1.0;

    for (size_t i = 0; i < ions.size(); ++i) {
        std::string nomeIon = ions[i].getNome();
        auto it = concentracoes.find(nomeIon);
        if (it != concentracoes.end()) {
            Q *= std::pow(it->second, coeficientes[i]);
        } else {
            std::cerr << "Aviso: concentração para ion " << nomeIon << " nao encontrada. Q = 0\n";
            return 0.0;
        }
    }

    return Q;
}

bool CSalt::willPrecipitate(const std::unordered_map<std::string, double>& concentracoes) const {
    return calculateIonicProduct(concentracoes) > Ksp;
}

std::string CSalt::getName() const {
    return name;
}

double CSalt::getKsp() const {
    return Ksp;
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
    Ksp = _Kps;
}

void CSalt::setIons(const std::vector<CIon>& _ions) {
    ions = _ions;
}

void CSalt::setCoeficientes(const std::vector<int>& _coef) {
    coeficientes = _coef;
}

CSalt::~CSalt() {}
