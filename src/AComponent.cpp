/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Error.hpp"

namespace nts {
    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        if (pin < 1 || pin > _pins.size()
        || dynamic_cast<AComponent *>(&other)->getPins()[otherPin - 1]->getType() == Pin::PIN_TYPE::VDD
        || dynamic_cast<AComponent *>(&other)->getPins()[otherPin - 1]->getType() == Pin::PIN_TYPE::VSS)
            throw Error("Link: Unknown or unlinkable pin");
        _pins[pin - 1]->setLinkedComponent(&other);
        _pins[pin - 1]->setLinkedPin(otherPin);
    }

    void AComponent::dump() const
    {
        std::cout << _name << " - " << _type << std::endl;
    }

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
