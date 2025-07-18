#ifndef THERMODYNAMICS_H
#define THERMODYNAMICS_H

/**
 * @brief Classe respons�vel por armazenar e gerenciar as condi��es termodin�micas do sistema.
 * 
 * @param temperature Temperatura do sistema (em Kelvin).
 * @param pressure Press�o do sistema (em atm).
 */
class CthermodynamicConditions {

    public:
        
        //Construtor padr�o: inicializa press�o e temperatura com valores padr�o.
        CthermodynamicConditions();

        /**
         * @brief Construtor parametrizado: permite definir valores iniciais de press�o e temperatura.
         * 
         * @param press Press�o inicial (em atm).
         * @param temp Temperatura inicial (em Kelvin).
         */
        CthermodynamicConditions(double press, double temp);

        //Define o valor da press�o do sistema. 
        void setPressure(double press);

        // Obt�m o valor da press�o do sistema.
        double getPressure() const;

        //Define o valor da temperatura do sistema.
        void setTemperature(double temp);

        //Obt�m o valor da temperatura do sistema.
        double getTemperature() const;

        /**
         * @brief Destrutor da classe `thermodynamicConditions`.
         */
        ~CthermodynamicConditions();                           

    protected:

        double pressure;                                    // Press�o em atm
        double temperature;                                 // Temperatura em Kelvin
 
};

#endif