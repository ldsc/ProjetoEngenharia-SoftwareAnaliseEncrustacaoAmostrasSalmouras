#ifndef IONS_H
#define IONS_H

#include <iostream>
#include <unordered_map>

/**
 * @brief
 *
 * @param name
 * @param concentration
 * @param charge
 */
struct ion {


    std::string name;
    double concentration;
    int charge;

/**
 * @brief
 *
 * @param _name
 * @param _concentration
 * @param _charge
 */
    ion(std::string _name = "", double _concentration = 0.0, int _charge = 0)
        : name(_name), concentration(_concentration), charge(_charge) {}

};

/**
 * @brief
 *
 * @param ions
 */
class CreateIons {

    public:

    CreateIons();

    void addIon(const std::string& name, double concentration, int charge);
    ion getIon(const std::string& name);

    ~CreateIons();

    protected:
    std::unordered_map<std::string, ion> ions;

};

#endif
