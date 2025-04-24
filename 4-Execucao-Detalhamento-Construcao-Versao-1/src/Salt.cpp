#include "Salt.h"
#include <cmath>

Salt::Salt()
{

    name = " ";
    Ksp = 0.0;
    ion1 = ion();
    ion2 = ion();
    coef1 = 0;
    coef2 = 0;

}

double Salt::calculateIonicProduct() const
{
    return std::pow(ion1.concentration, coef1) * std::pow(ion2.concentration, coef2);
}

bool Salt::willPrecipitate() const
{
    return calculateIonicProduct() > Ksp;
}

std::string Salt::getName() const
{
    return name;
}

double Salt::getKsp() const
{
    return Ksp;
}

ion Salt::getIon1() const
{
    return ion1;
}

ion Salt::getIon2() const
{
    return ion2;
}

int Salt::getCoef1() const
{
    return coef1;
}

int Salt::getCoef2() const
{
    return coef2;
}

void Salt::setName(std::string _name)
{
    name = _name;
}

void Salt::setKsp(double _Kps)
{
    Ksp = _Kps;
}

void Salt::setIon1(ion _ion1)
{
    ion1 = _ion1;
}

void Salt::setIon2(ion _ion2)
{
    ion2 = _ion2;
}

void Salt::setCoef1(int _coef1)
{
    coef1 = _coef1;
}

void Salt::setCoef2(int _coef2)
{
    coef2 = _coef2;
}

Salt::~Salt()
{

}
