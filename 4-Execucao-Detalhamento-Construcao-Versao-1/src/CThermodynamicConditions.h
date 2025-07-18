#ifndef THERMODYNAMICS_H
#define THERMODYNAMICS_H

/**
 * @brief Classe responsável por armazenar e gerenciar as condições termodinâmicas do sistema.
 * 
 * @param temperature Temperatura do sistema (em Kelvin).
 * @param pressure Pressão do sistema (em atm).
 */
class CthermodynamicConditions {

    public:
        
        //Construtor padrão: inicializa pressão e temperatura com valores padrão.
        CthermodynamicConditions();

        /**
         * @brief Construtor parametrizado: permite definir valores iniciais de pressão e temperatura.
         * 
         * @param press Pressão inicial (em atm).
         * @param temp Temperatura inicial (em Kelvin).
         */
        CthermodynamicConditions(double press, double temp);

        //Define o valor da pressão do sistema. 
        void setPressure(double press);

        // Obtém o valor da pressão do sistema.
        double getPressure() const;

        //Define o valor da temperatura do sistema.
        void setTemperature(double temp);

        //Obtém o valor da temperatura do sistema.
        double getTemperature() const;

        /**
         * @brief Destrutor da classe `thermodynamicConditions`.
         */
        ~CthermodynamicConditions();                           

    protected:

        double pressure;                                    // Pressão em atm
        double temperature;                                 // Temperatura em Kelvin
 
};

#endif