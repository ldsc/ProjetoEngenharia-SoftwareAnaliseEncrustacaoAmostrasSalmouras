#include "CThermodynamicConditions.h"

CthermodynamicConditions::CthermodynamicConditions()
{
    pressure    = 0.0;
    temperature = 0.0;
}

CthermodynamicConditions::CthermodynamicConditions(double press, double temp)
{
    pressure    = press;
    temperature = temp;
}

void CthermodynamicConditions::setPressure(double press)
{
    pressure = press;
}

double CthermodynamicConditions::getPressure() const
{
    return pressure;
}

void CthermodynamicConditions::setTemperature(double temp)
{
    temperature = temp;
}

double CthermodynamicConditions::getTemperature() const
{
    return temperature;
}

CthermodynamicConditions::~CthermodynamicConditions()
{

}
