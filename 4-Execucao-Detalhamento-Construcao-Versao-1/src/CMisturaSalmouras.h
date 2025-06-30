#ifndef CMISTURA_SALMOURAS_H
#define CMISTURA_SALMOURAS_H

#include "CSalmoura.h"
#include <vector>
#include <string>

/**
 * @brief Representa uma mistura de várias amostras de salmouras com diferentes volumes.
 * 
 * Combina as contribuições de cada salmoura e permite cálculo das concentrações finais de íons.
 */
class CMisturaSalmouras {

public:

    /**
     * @brief Construtor padrão.
     */
    CMisturaSalmouras();

    const std::vector<CSalmoura>& getSalmouras() const;

    /**
     * @brief Adiciona uma salmoura à mistura.
     * 
     * @param salmoura Objeto `CSalmoura`.
     */
    void adicionarSalmoura(const CSalmoura& salmoura);

    /**
     * @brief Retorna um mapa de concentrações finais (mol/L) de cada íon na mistura.
     */
    std::unordered_map<std::string, double> calcularConcentracoesFinais() const;

    ~CMisturaSalmouras();

private:
    std::vector<CSalmoura> salmouras; /**< Lista de salmouras adicionadas */
};

#endif
