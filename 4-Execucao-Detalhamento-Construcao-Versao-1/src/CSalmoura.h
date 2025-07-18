#ifndef CSALMOURA_H
#define CSALMOURA_H

#include "CSalt.h"
#include <unordered_map>
#include <vector>
#include <string>

/**
 * @brief Representa uma amostra de salmoura composta por �gua e sais dissolvidos.
 * 
 * Cont�m informa��es sobre o volume total da �gua, os sais adicionados e a quantidade (em mols) de cada �on presente.
 */
class CSalmoura {

public:

    /**
     * @brief Construtor padr�o.
     */
    CSalmoura();

    /**
     * @brief Construtor parametrizado.
     * 
     * @param volume Volume da salmoura em litros.
     */
    CSalmoura(double volume);

    /**
     * @brief Define condi��es termodinamicas.
     * 
     * @param temperaturaK temperatura em keven
     * @param quantidade pressao atm.
     */
    void DefinirCondicoes(double temperaturaK, double pressaoAtm);

    /**
     * @brief Define a quantidade (em mols) de um �on na solu��o.
     * 
     * @param nomeIon Nome do �on (ex: "Na").
     * @param quantidade N�mero de mols adicionados.
     */
    void adicionarIon(const std::string& nomeIon, double mols);

    /**
     * @brief Obt�m todos os �ons e suas quantidades (mols).
     * 
     * @return Mapa nome-do-�on ? n�mero de mols.
     */
    std::unordered_map<std::string, double> getMapaIonsMols() const;

    /**
     * @brief Obt�m o volume da salmoura (em litros).
     */
    double getVolume() const;

    /**
     * @brief Obt�m a temperatura da salmoura (em litros).
     */
    double getTemperatura() const;

    /**
     * @brief Define o volume da salmoura.
     * 
     * @param volume Volume em litros.
     */
    void setVolume(double volume);

    ~CSalmoura();

private:
    double quantidadeLiquido;  /**< Volume total da �gua em litros */
    double temperatura;  ///< Temperatura da salmoura (em Kelvin)
    double pressao;      ///< Press�o da salmoura (em atm)
    std::unordered_map<std::string, double> concentracoesMols; /**< Quantidade de mols de cada �on */
};

#endif
