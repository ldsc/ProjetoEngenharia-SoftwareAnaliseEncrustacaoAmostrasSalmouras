#ifndef CSIMULADORPRECIPITACAO_H
#define CSIMULADORPRECIPITACAO_H

#include "CMisturaSalmouras.h"
#include "CSalt.h"
#include "CTabelaPropriedadesIons.h"
#include "CPlotConfig.h"
#include <vector>

/**
 * @class CSimuladorPrecipitacao
 * @brief Classe respons�vel por gerenciar a intera��o com o usu�rio e a execu��o da simula��o qu�mica.
 *
 * Esta classe encapsula a l�gica de itera��o via terminal, coleta de dados como temperatura e press�o,
 * constru��o das salmouras, sais, e delega os c�lculos de precipita��o com base nas concentra��es finais.
 */
class CSimuladorPrecipitacao {
private:
    CTabelaPropriedadesIons tabelaIons;
    std::vector<CSalt> saisDisponiveis;
    size_t m_Quality = 1;
    QualidadePlot qualidade = QualidadePlot::Alta;

    void ConstruirSalmoura(CSalmoura& s) const;
    void CarregarSais(const std::string& caminhoArquivo);
    void ListarArquivosTxt(const std::string& titulo, std::string& selecionado) const;

public:
    /**
     * @brief Executa a interface interativa de terminal com o usu�rio.
     *
     * Permite definir condi��es termodin�micas, criar salmouras, sais e executar a simula��o completa.
     */
    void executar();

    /**
     * @brief Executa a simula��o de precipita��o com base na mistura e nos sais fornecidos.
     * @param mistura Mistura de salmouras criada pelo usu�rio.
     */
    void simular(const CMisturaSalmouras& mistura);
};

#endif
