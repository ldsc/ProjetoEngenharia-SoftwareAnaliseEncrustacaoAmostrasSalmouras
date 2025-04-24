#include "ThermodynamicConditions.h"
#include "CreateIons.h"
#include "Salt.h"
#include "PrecipitationCalculator.h"
#include <vector>
#include <iostream>

int main() {
    thermodynamicConditions conditions(298.15, 1.0); // 25°C e 1 atm

    
    CreateIons ionFactory;

    ionFactory.addIon("Ca2+", 0.01, 2);
    ionFactory.addIon("CO3_2-", 0.01, -2);
    
    ion Ca2 = ionFactory.getIon("Ca2+");
    ion CO3_2 = ionFactory.getIon("CO3_2-");

    Salt calcita("Calcita (CaCO3)", 3.36e-9, Ca2, CO3_2, 1, 1);

    std::cout << "Nome do sal antes: " << calcita.getName() << "\n";
    calcita.setName("Carbonato de Calcio");
    std::cout << "Nome do sal depois: " << calcita.getName() << "\n";

    std::vector<Salt> salts = {calcita};

    PrecipitationCalculator::analyzePrecipitation(salts);

    return 0;
}
