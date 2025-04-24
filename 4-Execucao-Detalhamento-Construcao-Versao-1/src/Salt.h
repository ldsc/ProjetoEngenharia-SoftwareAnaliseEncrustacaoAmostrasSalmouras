#ifndef SALT_H
#define SALT_H

#include "CreateIons.h"

/**
 * @brief 
 *
 * @param name 
 * @param Ksp 
 * @param ion1 
 * @param ion2 
 * @param coef1 
 * @param coef2 
 */
class Salt {
   
    public:

        Salt();

        /**
         * @brief
         * 
         * @param _name 
         * @param ksp 
         * @param _ion1 
         * @param _ion2 
         * @param c1 
         * @param c2 
         */
        Salt(std::string _name, double ksp, ion _ion1, ion _ion2, int c1, int c2)
            : name(_name), Ksp(ksp), ion1(_ion1), ion2(_ion2), coef1(c1), coef2(c2) {}

        /**
         * @brief 
         * 
         * @return 
         */
        double calculateIonicProduct() const;

        /**
         * @brief 
         * 
         * @return 
         */
        bool willPrecipitate() const;

       
        std::string getName() const;

        double getKsp() const;

        ion getIon1() const;

        ion getIon2() const;

        int getCoef1() const;

        int getCoef2() const;

        void setName(std::string _name);

    
        void setKsp(double _Kps);

        
        void setIon1(ion _ion1);

  
        void setIon2(ion _ion2);

        void setCoef1(int _coef1);

        void setCoef2(int _coef2);


        ~Salt();
    
    protected:

        std::string name;  
        double Ksp;        
        ion ion1;          
        ion ion2;          
        int coef1;         
        int coef2;         
};

#endif 
