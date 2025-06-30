#ifndef CTABELA_PROPRIEDADES_IONS_H
#define CTABELA_PROPRIEDADES_IONS_H

#include "CIons.h"
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @brief Classe responsável por carregar, armazenar e fornecer acesso a íons conhecidos da literatura.
 * 
 * Essa tabela é persistente e pode ser carregada de ou salva em arquivos do disco, contendo dados como nome e carga do íon.
 */
class CTabelaPropriedadesIons {

public:

    /**
     * @brief Construtor padrão da tabela de íons.
     */
    CTabelaPropriedadesIons();

    /**
     * @brief Carrega os íons de um arquivo texto (formato CSV: nome;carga).
     * 
     * @param caminho Caminho para o arquivo a ser lido.
     */
    void carregarDeArquivo(const std::string& caminho);

    /**
     * @brief Salva os íons da tabela em um arquivo texto (formato CSV: nome;carga).
     * 
     * @param caminho Caminho para o arquivo de destino.
     */
    void salvarParaArquivo(const std::string& caminho) const;

    /**
     * @brief Adiciona um novo íon à tabela.
     * 
     * @param ion Objeto CIon contendo nome e carga do íon.
     */
    void adicionarIon(const CIon& ion);

    /**
     * @brief Retorna um íon a partir de seu nome.
     * 
     * @param nome Nome do íon a ser buscado.
     * @return Objeto CIon correspondente (ou vazio, caso não exista).
     */
    CIon obterIon(const std::string& nome) const;

    /**
     * @brief Retorna todos os íons da tabela como um map.
     * 
     * @return mapa contendo todos os íons armazenados.
     */
    const std::unordered_map<std::string, CIon>& getMapa() const;

private:
    std::unordered_map<std::string, CIon> m_ions; /**< Mapa de íons: nome -> CIon */
};

#endif
