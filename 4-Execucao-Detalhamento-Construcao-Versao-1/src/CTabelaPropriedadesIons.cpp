#include "CTabelaPropriedadesIons.h"
#include <fstream>
#include <sstream>
#include <iostream>

CTabelaPropriedadesIons::CTabelaPropriedadesIons() {}

void CTabelaPropriedadesIons::carregarDeArquivo(const std::string& caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminho << "\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string nome, cargaStr;

        if (std::getline(iss, nome, ';') && std::getline(iss, cargaStr)) {
            int carga = std::stoi(cargaStr);
            adicionarIon(CIon(nome, carga));
        }
    }

    arquivo.close();
}

void CTabelaPropriedadesIons::salvarParaArquivo(const std::string& caminho) const {
    std::ofstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao salvar no arquivo: " << caminho << "\n";
        return;
    }

    for (const auto& [nome, ion] : m_ions) {
        arquivo << ion.getNome() << ";" << ion.getCarga() << "\n";//esta linha tem erros...
    }

    arquivo.close();
}

void CTabelaPropriedadesIons::adicionarIon(const CIon& ion) {
    m_ions[ion.getNome()] = ion;
}

CIon CTabelaPropriedadesIons::obterIon(const std::string& nome) const {
    auto it = m_ions.find(nome);
    if (it != m_ions.end()) {
        return it->second;
    }
    std::cerr << "Ion nao encontrado: " << nome << "\n";
    return CIon(); // precisa informar que retornou ion zerado; ou pedir dados e completar o que falta
}

std::vector<CIon> CTabelaPropriedadesIons::listarIons() const {
    std::vector<CIon> lista;
    for (const auto& [_, ion] : m_ions) {
        lista.push_back(ion);
    }
    return lista;
}
