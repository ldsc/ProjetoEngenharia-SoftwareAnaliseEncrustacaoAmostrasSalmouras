#include "CIons.h"

CIon::CIon(std::string nome, int carga) : nome(nome), carga(carga) 
{
}

std::string CIon::getNome() const
{
    return nome;
}

int CIon::getCarga() const
{
    return carga;
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
        std::cerr << "Erro: Íon '" << name << "' não encontrado!\n";
        return CIon(); // Retorna um íon vazio
    }
}

CreateIons::~CreateIons()
{

}