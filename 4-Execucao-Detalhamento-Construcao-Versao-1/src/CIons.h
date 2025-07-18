#ifndef CIONS_H
#define CIONS_H

#include <iostream>
#include <unordered_map>

/**
 * @brief Estrutura que representa um �on na solu��o qu�mica.
 * 
 * @param name Nome do �on (ex: "Ca2+").
 * @param charge Carga el�trica do �on.
 */

class CIon {
    public:

        /**
         * @brief Construtor da estrutura ion.
         * 
         * @param _name Nome do �on.
         * @param _charge Carga do �on.
         */
        CIon(std::string _nome = "", int _carga = 0);

        std::string getNome() const;
        int getCarga() const;


private:
    std::string nome;
    int carga;
};

/**
 * @brief Classe respons�vel pela cria��o e gerenciamento de �ons.
 * 
 * @param ions Mapa (`unordered_map`) que armazena os �ons criados.
 */
class CreateIons {
    public:

    // Construtor
    CreateIons();                                                           
    
    // Adiciona um �on ao mapa
    void addIon(const std::string& _name, int _charge);
    // Obt�m um �on do mapa 
    CIon getIon(const std::string& _name);                                    

    // Destrutor
    ~CreateIons();                                                          

    protected:
    // Cont�iner de �ons armazenados
    std::unordered_map<std::string, CIon> ions;                              

};

#endif