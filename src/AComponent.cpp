/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** AComponent
*/

#include "AComponent.hpp"

namespace nts {
    const std::string &AComponent::getName() const
    {
        return _name;
    }

    const std::string &AComponent::getType() const
    {
        return _type;
    }

    std::vector<Pin *> AComponent::getPins() const
    {
        return _pins;
    }

    void AComponent::setName(const std::string &name)
    {
        _name = name;
    }

    void AComponent::setType(const std::string &type)
    {
        _type = type;
    }
}
