/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "4071.hpp"

namespace nts {
    OrComponent::OrComponent(const std::string &name)
    {
        _name = name;
        _type = "4071";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::VSS));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::VDD));
    }

    OrComponent::~OrComponent()
    {
    }

    nts::Tristate OrComponent::compute(std::size_t pin)
    {
        if (_pins[0]->getLinkedComponent()->compute() == nts::UNDEFINED || _pins[1]->getLinkedComponent()->compute() == nts::UNDEFINED)
            return nts::UNDEFINED;
        else if (_pins[0]->getLinkedComponent()->compute() == nts::FALSE && _pins[1]->getLinkedComponent()->compute() == nts::FALSE)
            return nts::FALSE;
        return nts::TRUE;
    }
}