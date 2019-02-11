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
}
