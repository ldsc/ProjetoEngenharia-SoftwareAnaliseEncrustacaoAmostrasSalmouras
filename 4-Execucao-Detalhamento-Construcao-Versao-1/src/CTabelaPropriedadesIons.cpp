#include "CTabelaPropriedadesIons.h"
#include <fstream>
#include <sstream>
#include <iostream>

CTabelaPropriedadesIons::CTabelaPropriedadesIons() {}

void CTabelaPropriedadesIons::carregarDeArquivo(const std::string& caminho) {
    std::ifstream arquivo("./dados/" + caminho);
    if (!arquivo.is_open()) return;

    std::string linha;
    while (std::getline(arquivo, linha)) {
        if (linha.empty() || linha[0] == '#') continue;
        std::istringstream iss(linha);
        std::string nome;
        int carga;
        if (iss >> nome >> carga) {
            m_ions[nome] = CIon(nome, carga);
        }
    }
}

void CTabelaPropriedadesIons::salvarParaArquivo(const std::string& caminho) const {
    std::ofstream arquivo("./dados/" + caminho);
    for (const auto& [nome, ion] : m_ions) {
        arquivo << nome << "\t" << ion.getCarga() << "\n";
    }
}

void CTabelaPropriedadesIons::adicionarIon(const CIon& ion) {
    m_ions[ion.getNome()] = ion;
}

CIon CTabelaPropriedadesIons::obterIon(const std::string& nome) const {
    auto it = m_ions.find(nome);
    if (it != m_ions.end()) {
        return it->second;
    }
    std::cerr << "Íon não encontrado: " << nome << "\n";
    return CIon();
}

const std::unordered_map<std::string, CIon>& CTabelaPropriedadesIons::getMapa() const {
    return m_ions;
}
