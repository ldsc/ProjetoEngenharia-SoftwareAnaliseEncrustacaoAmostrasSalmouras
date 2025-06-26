#ifndef CSALMOURA_H
#define CSALMOURA_H

#include "CSalt.h"
#include "CIons.h"
#include <unordered_map>
#include <vector>
#include <string>

/**
 * @brief Representa uma amostra de salmoura composta por água e sais dissolvidos.
 *
 * Contém informações sobre o volume total da água, os sais adicionados e a quantidade (em mols) de cada íon presente.
 */
class CSalmoura {

public:

    /**
     * @brief Construtor padrão.
     */
    CSalmoura();

    /**
     * @brief Construtor parametrizado.
     *
     * @param volume Volume da salmoura em litros.
     */
    CSalmoura(double volume);

    /**
     * @brief Define a quantidade (em mols) de um íon na solução.
     *
     * @param nomeIon Nome do íon (ex: "Na").
     * @param quantidade Número de mols adicionados.
     */
    void adicionarIon(const std::string& nomeIon, double quantidade);

    /**
     * @brief Adiciona um sal à salmoura.
     *
     * @param sal Objeto `CSalt` a ser adicionado.
     */
    void adicionarSal(const CSalt& sal);

    /**
     * @brief Obtém todos os íons e suas quantidades (mols).
     *
     * @return Mapa nome-do-íon → número de mols.
     */
    std::unordered_map<std::string, double> getMapaIonsMols() const;

    /**
     * @brief Obtém o volume da salmoura (em litros).
     */
    double getVolume() const;//eliminar set/get

    /**
     * @brief Define o volume da salmoura.
     *
     * @param volume Volume em litros.
     */
    void setVolume(double volume);

    /**
     * @brief Retorna a lista de sais adicionados.
     */
    std::vector<CSalt> getSais() const;

    ~CSalmoura();

private:
    double quantidadeLiquido;  /**< Volume total da água em litros */ // use volumeLiquido
    std::vector<CSalt> sais;   /**< Sais adicionados à salmoura */
    std::unordered_map<std::string, double> concentracoesMols; /**< Quantidade de mols de cada íon */
};

#endif
