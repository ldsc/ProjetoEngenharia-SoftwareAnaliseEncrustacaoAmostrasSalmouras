#include "PrecipitationCalculator.h"

PrecipitationCalculator::PrecipitationCalculator()
{
}

void PrecipitationCalculator::analyzePrecipitation(const std::vector<Salt> &salts)
{
    for (const auto& salt : salts) {
            double Q = salt.calculateIonicProduct();
            std::cout << "Sal: " << salt.getName() << " - Produto Iônico (Q): " << Q
                    << " | Ksp: " << salt.getKsp();
        if (salt.willPrecipitate()) {
            std::cout << " → Precipitacao ocorre!\n";
        } else {
            std::cout << " → Solucao estável.\n";
        }
    }
}

PrecipitationCalculator::~PrecipitationCalculator()
{
}
