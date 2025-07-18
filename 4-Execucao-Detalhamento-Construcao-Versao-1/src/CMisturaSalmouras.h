#ifndef CMISTURA_SALMOURAS_H
#define CMISTURA_SALMOURAS_H

#include "CSalmoura.h"
#include <vector>
#include <string>

/**
 * @brief Representa uma mistura de v?rias amostras de salmouras com diferentes volumes.
 * 
 * Combina as contribui??es de cada salmoura e permite c?lculo das concentra??es finais de ?ons.
 */
class CMisturaSalmouras {

public:

    /**
     * @brief Construtor padr?o.
     */
    CMisturaSalmouras();

    const std::vector<CSalmoura>& getSalmouras() const;

    /**
     * @brief Adiciona uma salmoura ? mistura.
     * 
     * @param salmoura Objeto `CSalmoura`.
     */
    void adicionarSalmoura(const CSalmoura& salmoura);

    /**
     * @brief Retorna um mapa de concentra??es finais (mol/L) de cada ?on na mistura.
     */
    std::unordered_map<std::string, double> calcularConcentracoesFinais() const;

    ~CMisturaSalmouras();

private:
    std::vector<CSalmoura> salmouras; /**< Lista de salmouras adicionadas */
};

#endif
