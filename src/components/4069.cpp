/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "components/4069.hpp"
#include "core/Error.hpp"

namespace nts {
    InverterComponent::InverterComponent(const std::string &name)
    {
        _name = name;
        _type = "4069";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::VSS));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::VDD));
    }

    nts::Tristate InverterComponent::compute(std::size_t pin)
    {
        int input;

        if (pin == 2 || pin == 4 || pin == 6) {
            input = pin - 2;
        } else if (pin == 8 || pin == 10 || pin == 12) {
            input = pin;
        } else
            throw Error("Compute: Tried to compute an invalid pin");
        if (_pins[input]->getLinkedComponent()->compute(_pins[input]->getLinkedPin()) == nts::UNDEFINED)
            _pins[pin - 1]->setValue(nts::UNDEFINED);
        else if (_pins[input]->getLinkedComponent()->compute(_pins[input]->getLinkedPin()) == nts::FALSE)
            _pins[pin - 1]->setValue(nts::TRUE);
        else
            _pins[pin - 1]->setValue(nts::FALSE);
        return _pins[pin - 1]->getValue();
    }
}
