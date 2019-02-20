/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "4081.hpp"

namespace nts {
    AndComponent::AndComponent(const std::string &name)
    {
        _name = name;
        _type = "4081";
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

    AndComponent::~AndComponent()
    {
    }

    nts::Tristate AndComponent::compute(std::size_t pin)
    {
        if (_pins[0]->getLinkedComponent()->compute() == nts::UNDEFINED || _pins[1]->getLinkedComponent()->compute() == nts::UNDEFINED)
            return nts::UNDEFINED;
        else if (_pins[0]->getLinkedComponent()->compute() == nts::TRUE && _pins[1]->getLinkedComponent()->compute() == nts::TRUE)
            return nts::TRUE;
        return nts::FALSE;
    }
}