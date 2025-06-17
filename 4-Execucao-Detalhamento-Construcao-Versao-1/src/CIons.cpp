#include "CIons.h"

CIon::CIon(std::string nome, int carga) : m_nome(nome), m_carga(carga) 
{
}

std::string CIon::getNome() const
{
    return m_nome;
}

int CIon::getCarga() const
{
    return m_carga;
}

void CIon::setNome(const std::string &nome)
{
    m_nome = nome;
}

void CIon::setCarga(int carga)
{
    m_carga = carga;
}

CreateIons::CreateIons()
{
    
}

void CreateIons::addIon(const std::string &name, int charge)
{
    ions[name] = CIon(name, charge);
}

CIon CreateIons::getIon(const std::string &name)
{
    if (ions.find(name) != ions.end()) {
        return ions[name];
    } else {
        std::cerr << "Erro: Ion '" << name << "' nao encontrado!\n";
        return CIon(); // Retorna um íon vazio
    }
}

CreateIons::~CreateIons()
{

}