#include "CreateIons.h"

CreateIons::CreateIons()
{
    
}

void CreateIons::addIon(const std::string &name, double concentration, int charge)
{
    ions[name] = ion(name, concentration, charge);
}

ion CreateIons::getIon(const std::string &name)
{
    if (ions.find(name) != ions.end()) {
        return ions[name];
    } else {
        std::cerr << "Erro: Íon '" << name << "' não encontrado!\n";
        return ion(); 
    }
}

CreateIons::~CreateIons()
{

}
