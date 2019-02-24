/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "components/4008.hpp"
#include "core/Error.hpp"

namespace nts {
    AdderComponent::AdderComponent(const std::string &name)
    {
        _name = name;
        _type = "4008";
        _isUndefined = false;
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::VSS));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::OUTPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins.push_back(new Pin(Pin::PIN_TYPE::VDD));
    }

    nts::Tristate AdderComponent::compute(std::size_t pin)
    {
        int input1;
        int input2;
        nts::Tristate carryIn;
        int total = 0;

        if (_pins[8]->getValue() == nts::UNDEFINED)
            carryIn = _pins[8]->getLinkedComponent()->compute(_pins[8]->getLinkedPin());
        else
            carryIn = _pins[8]->getValue();

        if (pin == 10) {
            input1 = pin - 4;
            input2 = pin - 5;
        } else if (pin == 11) {
            input1 = pin - 7;
            input2 = pin - 8;
        } else if (pin == 12) {
            input1 = pin - 10;
            input2 = pin - 11;
        } else if (pin == 13) {
            input1 = pin - 13;
            input2 = pin + 1;
        } else if (pin == 14) {
            return _pins[13]->getValue();
        } else if (pin == 9){
            return _pins[8]->getValue();
        } else
            throw Error("Compute: Tried to compute an invalid pin");
        if (_pins[input1]->getLinkedComponent()->compute(_pins[input1]->getLinkedPin()) == nts::UNDEFINED
        || _pins[input2]->getLinkedComponent()->compute(_pins[input2]->getLinkedPin()) == nts::UNDEFINED
        || carryIn == nts::UNDEFINED || _isUndefined == true) {
            _pins[pin - 1]->setValue(nts::UNDEFINED);
            _pins[8]->setValue(nts::UNDEFINED);
            _pins[13]->setValue(nts::UNDEFINED);
            _isUndefined = true;
        } else {
            if (_pins[input1]->getLinkedComponent()->compute(_pins[input1]->getLinkedPin()) == nts::TRUE)
                total++;
            if (_pins[input2]->getLinkedComponent()->compute(_pins[input1]->getLinkedPin()) == nts::TRUE)
                total++;
            if (carryIn == nts::TRUE)
                total++;
            if (total == 1) {
                _pins[pin - 1]->setValue(nts::TRUE);
                _pins[8]->setValue(nts::FALSE);
                _pins[13]->setValue(nts::FALSE);
            } else if (total == 2) {
                _pins[pin - 1]->setValue(nts::FALSE);
                _pins[8]->setValue(nts::TRUE);
                _pins[13]->setValue(nts::TRUE);
            } else if (total == 3) {
                _pins[pin - 1]->setValue(nts::TRUE);
                _pins[8]->setValue(nts::TRUE);
                _pins[13]->setValue(nts::TRUE);
            } else {
                _pins[pin - 1]->setValue(nts::FALSE);
                _pins[8]->setValue(nts::FALSE);
                _pins[13]->setValue(nts::FALSE);
            }
        }
        return _pins[pin - 1]->getValue();
    }
}
