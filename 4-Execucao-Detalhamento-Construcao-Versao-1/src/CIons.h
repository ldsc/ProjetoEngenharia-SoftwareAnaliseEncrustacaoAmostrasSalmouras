#ifndef CIONS_H
#define CIONS_H

#include <iostream>
#include <unordered_map>

/**
 * @brief Estrutura que representa um íon na solução química.
 * 
 * @param name Nome do íon (ex: "Ca2+").
 * @param charge Carga elétrica do íon.
 */

class CIon {
    public:

        /**
         * @brief Construtor da estrutura ion.
         * 
         * @param name Nome do íon.
         * @param charge Carga do íon.
         */
        CIon(std::string nome = "", int carga = 0);

        std::string getNome() const;
        int getCarga() const;

        void setNome(const std::string& nome);
        void setCarga(int carga);

private:
    std::string m_nome;
    int m_carga;
};

/**
 * @brief Classe responsável pela criação e gerenciamento de íons.
 * 
 * @param ions Mapa (`unordered_map`) que armazena os íons criados.
 */
class CreateIons {

    public:

    // Construtor
    CreateIons();                                                           
    
    // Adiciona um íon ao mapa
    void addIon(const std::string& name, int charge);
    // Obtém um íon do mapa 
    CIon getIon(const std::string& name);                                    

    // Destrutor
    ~CreateIons();                                                          

    protected:
    // Contêiner de íons armazenados
    std::unordered_map<std::string, CIon> ions;                              

};

#endif