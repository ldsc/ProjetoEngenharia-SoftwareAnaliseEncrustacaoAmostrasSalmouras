#ifndef PRECIPITATIONCALCULATOR_H
#define PRECIPITATIONCALCULATOR_H

#include "Salt.h"
#include <vector>
#include <iostream>

/**
 * @brief 
 */
class PrecipitationCalculator {

    public:

        
        PrecipitationCalculator(); 

        /**
         * @brief 
         * 
         * @param salts 
         */
        static void analyzePrecipitation(const std::vector<Salt>& salts);

        ~PrecipitationCalculator(); 

};

#endif 