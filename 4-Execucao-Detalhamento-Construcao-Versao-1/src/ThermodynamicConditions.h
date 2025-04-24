#ifndef THERMODYNAMICS_H
#define THERMODYNAMICS_H

/**
 * @brief 
 * @param temperature #Celsius
 * @param pressure #atm
 */
class thermodynamicConditions {

    public:
        
        thermodynamicConditions();

        /**
         * @brief 
         * 
         * @param press 
         * @param temp 
         */
        thermodynamicConditions(double press, double temp);

        void setPressure(double press);

        double getPressure() const;

        void setTemperature(double temp);

        double getTemperature() const;

        /**
         * @brief 
         */
        ~thermodynamicConditions();                           

    protected:

        double pressure;                                   
        double temperature;                                 
};

#endif