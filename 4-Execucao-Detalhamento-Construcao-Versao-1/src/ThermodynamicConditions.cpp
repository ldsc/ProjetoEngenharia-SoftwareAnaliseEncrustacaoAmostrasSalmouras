#include "ThermodynamicConditions.h"

thermodynamicConditions::thermodynamicConditions()
{
    pressure    = 0.0;
    temperature = 0.0;
}

thermodynamicConditions::thermodynamicConditions(double press, double temp)
{
    pressure    = press;
    temperature = temp;
}

void thermodynamicConditions::setPressure(double press)
{
    pressure = press;
}

double thermodynamicConditions::getPressure() const
{
    return pressure;
}

void thermodynamicConditions::setTemperature(double temp)
{
    temperature = temp;
}

double thermodynamicConditions::getTemperature() const
{
    return temperature;
}

thermodynamicConditions::~thermodynamicConditions()
{

}
