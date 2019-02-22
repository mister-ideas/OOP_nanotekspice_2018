/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "components/4081.hpp"
#include "core/Error.hpp"

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

    nts::Tristate AndComponent::compute(std::size_t pin)
    {
        int input1;
        int input2;

        if (pin == 3 || pin == 10) {
            input1 = pin - 3;
            input2 = pin - 2;
        } else if (pin == 4 || pin == 11) {
            input1 = pin;
            input2 = pin + 1;
        } else
            throw Error("Compute: Tried to compute an invalid pin");
        if (_pins[input1]->getLinkedComponent()->compute(_pins[input1]->getLinkedPin()) == nts::UNDEFINED
        || _pins[input2]->getLinkedComponent()->compute(_pins[input2]->getLinkedPin()) == nts::UNDEFINED)
            _pins[pin - 1]->setValue(nts::UNDEFINED);
        else if (_pins[input1]->getLinkedComponent()->compute(_pins[input1]->getLinkedPin()) == nts::TRUE
        && _pins[input2]->getLinkedComponent()->compute(_pins[input2]->getLinkedPin()) == nts::TRUE)
            _pins[pin - 1]->setValue(nts::TRUE);
        else
            _pins[pin - 1]->setValue(nts::FALSE);
        return _pins[pin - 1]->getValue();
    }
}
