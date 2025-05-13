#ifndef CSIMULADORPRECIPITACAO_H
#define CSIMULADORPRECIPITACAO_H

#include "CTabelaPropriedadesIons.h"
#include "CMisturaSalmouras.h"
#include <string>

/**
 * @brief Classe principal responsável por gerenciar a simulação de precipitação química.
 */
class CSimuladorPrecipitacao {
public:
    /**
     * @brief Executa a simulação completa com base nas salmouras fornecidas.
     */
    void executar();

private:
    /**
     * @brief Cria uma salmoura simples para teste.
     */
    CSalmoura criarSalmouraTeste1() const;

    /**
     * @brief Cria uma segunda salmoura simples para teste.
     */
    CSalmoura criarSalmouraTeste2() const;
};

#endif