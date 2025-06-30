#ifndef CSIMULADORPRECIPITACAO_H
#define CSIMULADORPRECIPITACAO_H

#include "CMisturaSalmouras.h"
#include "CSalt.h"
#include "CTabelaPropriedadesIons.h"
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
    CTabelaPropriedadesIons tabelaIons;
    std::vector<CSalt> saisDisponiveis;

    void ConstruirSalmoura(CSalmoura& s) const;
    void CarregarSais(const std::string& caminhoArquivo);
    void ListarArquivosTxt(const std::string& titulo, std::string& selecionado) const;

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
     */
    void simular(const CMisturaSalmouras& mistura);
};

#endif
