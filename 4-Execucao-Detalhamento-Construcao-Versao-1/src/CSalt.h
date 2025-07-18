#ifndef CSALT_H
#define CSALT_H

#include "CIons.h"
#include <vector>
#include <string>
#include <unordered_map>

/**
 * @brief Classe respons�vel por modelar um sal e calcular sua solubilidade.
 * 
 * Um sal � formado por uma combina��o de �ons com coeficientes estequiom�tricos conhecidos.
 * Sua precipita��o depende do produto i�nico comparado ao Ksp (constante de solubilidade).
 */
class CSalt {

public:

    /**
     * @brief Construtor completo do sal.
     * @param nome Nome do sal
     * @param kspRef Ksp de refer�ncia
     * @param deltaH ?H� de dissolu��o (J/mol)
     * @param temperaturaRef Temperatura de refer�ncia (K)
     * @param ions Vetor de �ons
     * @param coeficientes Coeficientes estequiom�tricos
     */
    CSalt(std::string nome, double kspRef, double deltaH, double temperaturaRef, const std::vector<CIon>& ions, const std::vector<int>& coeficientes);

     /**
     * @brief Corrige o Ksp com base na temperatura atual.
     * @param temperatura Temperatura (K)
     * @return Ksp corrigido
     */
    double KspCorrigido(double temperatura) const;

    /**
     * @brief Calcula o produto i�nico Q do sal com base nas concentra��es fornecidas.
     * 
     * @param concentracoes Mapa nome-do-�on ? concentra��o (mol/L)
     * @return Valor de Q (produto i�nico)
     */
    double calculateIonicProduct(const std::unordered_map<std::string, double>& concentracoes) const;

    /**
     * @brief Verifica se o sal ir� precipitar.
     * @param concentracoes Mapa de concentra��o molar por �on
     * @param temperatura Temperatura (K)
     * @return true se Q > Ksp_corrigido
     */
    bool willPrecipitate(const std::unordered_map<std::string, double>& concentracoes, double temperatura) const;

    /// @return Nome do sal.
    std::string getName() const;

    /// @return Produto de solubilidade do sal (Ksp).
    double getKsp() const;

    /// @return Vetor de �ons que comp�em o sal.
    std::vector<CIon> getIons() const;

    /// @return Vetor de coeficientes estequiom�tricos.
    std::vector<int> getCoeficientes() const;

    /// Define o nome do sal.
    void setName(std::string nome);

    /// Define o valor do Ksp.
    void setKsp(double ksp);

    /// Define os �ons do sal.
    void setIons(const std::vector<CIon>& ions);

    /// Define os coeficientes dos �ons.
    void setCoeficientes(const std::vector<int>& coeficientes);

    /// Destrutor.
    ~CSalt();

private:
    std::string name;               // Nome do sal
    double kspRef;                  // Ksp de refer�ncia (em temperaturaRef)
    double deltaH;                  // ?H� de dissolu��o (J/mol)
    double temperaturaRef;          // Temperatura de refer�ncia (K)
    std::vector<CIon> ions;         // �ons que comp�em o sal
    std::vector<int> coeficientes;  // Coeficientes estequiom�tricos
};

#endif