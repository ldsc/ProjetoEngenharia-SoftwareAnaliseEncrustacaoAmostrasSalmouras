#ifndef CSALMOURA_H
#define CSALMOURA_H

#include "CSalt.h"
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
     * @brief Define condições termodinamicas.
     * 
     * @param temperaturaK temperatura em keven
     * @param quantidade pressao atm.
     */
    void DefinirCondicoes(double temperaturaK, double pressaoAtm);

    /**
     * @brief Define a quantidade (em mols) de um íon na solução.
     * 
     * @param nomeIon Nome do íon (ex: "Na").
     * @param quantidade Número de mols adicionados.
     */
    void adicionarIon(const std::string& nomeIon, double mols);

    /**
     * @brief Obtém todos os íons e suas quantidades (mols).
     * 
     * @return Mapa nome-do-íon → número de mols.
     */
    std::unordered_map<std::string, double> getMapaIonsMols() const;

    /**
     * @brief Obtém o volume da salmoura (em litros).
     */
    double getVolume() const;

    /**
     * @brief Obtém a temperatura da salmoura (em litros).
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
    double quantidadeLiquido;  /**< Volume total da água em litros */
    double temperatura;  ///< Temperatura da salmoura (em Kelvin)
    double pressao;      ///< Pressão da salmoura (em atm)
    std::unordered_map<std::string, double> concentracoesMols; /**< Quantidade de mols de cada íon */
};

#endif
