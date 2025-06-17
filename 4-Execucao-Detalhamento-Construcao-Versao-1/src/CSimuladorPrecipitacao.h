#ifndef CSIMULADORPRECIPITACAO_H
#define CSIMULADORPRECIPITACAO_H

#include "CMisturaSalmouras.h"
#include "CSalt.h"
#include "CThermodynamicConditions.h"
#include <vector>

/**
 * @class CSimuladorPrecipitacao
 * @brief Classe responsável por gerenciar a interação com o usuário e a execução da simulação química.
 *
 * Esta classe encapsula a lógica de iteração via terminal, coleta de dados como temperatura e pressão,
 * construção das salmouras, sais, e delega os cálculos de precipitação com base nas concentrações finais.
 */
class CSimuladorPrecipitacao {
private:
    /**
     * @brief Condições termodinâmicas da simulação (pressão e temperatura).
     */
    CthermodynamicConditions condicoes;

public:
    /**
     * @brief Executa a interface interativa de terminal com o usuário.
     *
     * Permite definir condições termodinâmicas, criar salmouras, sais e executar a simulação completa.
     */
    void executar();

    /**
     * @brief Executa a simulação de precipitação com base na mistura e nos sais fornecidos.
     * @param mistura Mistura de salmouras criada pelo usuário.
     * @param sais Vetor de sais a serem analisados quanto à possibilidade de precipitação.
     */
    void simular(const CMisturaSalmouras& mistura, const std::vector<CSalt>& sais);
};

#endif
