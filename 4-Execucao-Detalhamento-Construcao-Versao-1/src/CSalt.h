#ifndef CSALT_H
#define CSALT_H

#include "CIons.h"
#include <vector>
#include <string>
#include <unordered_map>

/**
 * @brief Classe responsável por modelar um sal e calcular sua solubilidade.
 * 
 * Um sal é formado por uma combinação de íons com coeficientes estequiométricos conhecidos.
 * Sua precipitação depende do produto iônico comparado ao Ksp (constante de solubilidade).
 */
class CSalt {

public:

    /**
     * @brief Construtor completo do sal.
     * @param nome Nome do sal
     * @param kspRef Ksp de referência
     * @param deltaH ?Hº de dissolução (J/mol)
     * @param temperaturaRef Temperatura de referência (K)
     * @param ions Vetor de íons
     * @param coeficientes Coeficientes estequiométricos
     */
    CSalt(std::string nome, double kspRef, double deltaH, double temperaturaRef, const std::vector<CIon>& ions, const std::vector<int>& coeficientes);

     /**
     * @brief Corrige o Ksp com base na temperatura atual.
     * @param temperatura Temperatura (K)
     * @return Ksp corrigido
     */
    double KspCorrigido(double temperatura) const;

    /**
     * @brief Calcula o produto iônico Q do sal com base nas concentrações fornecidas.
     * 
     * @param concentracoes Mapa nome-do-íon ? concentração (mol/L)
     * @return Valor de Q (produto iônico)
     */
    double calculateIonicProduct(const std::unordered_map<std::string, double>& concentracoes) const;

    /**
     * @brief Verifica se o sal irá precipitar.
     * @param concentracoes Mapa de concentração molar por íon
     * @param temperatura Temperatura (K)
     * @return true se Q > Ksp_corrigido
     */
    bool willPrecipitate(const std::unordered_map<std::string, double>& concentracoes, double temperatura) const;

    /// @return Nome do sal.
    std::string getName() const;

    /// @return Produto de solubilidade do sal (Ksp).
    double getKsp() const;

    /// @return Vetor de íons que compõem o sal.
    std::vector<CIon> getIons() const;

    /// @return Vetor de coeficientes estequiométricos.
    std::vector<int> getCoeficientes() const;

    /// Define o nome do sal.
    void setName(std::string nome);

    /// Define o valor do Ksp.
    void setKsp(double ksp);

    /// Define os íons do sal.
    void setIons(const std::vector<CIon>& ions);

    /// Define os coeficientes dos íons.
    void setCoeficientes(const std::vector<int>& coeficientes);

    /// Destrutor.
    ~CSalt();

private:
    std::string name;               // Nome do sal
    double kspRef;                  // Ksp de referência (em temperaturaRef)
    double deltaH;                  // ?Hº de dissolução (J/mol)
    double temperaturaRef;          // Temperatura de referência (K)
    std::vector<CIon> ions;         // Íons que compõem o sal
    std::vector<int> coeficientes;  // Coeficientes estequiométricos
};

#endif