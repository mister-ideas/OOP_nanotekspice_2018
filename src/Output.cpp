/*
** EPITECH PROJECT, 2019
** Output.cpp
** File description:
** Methods
*/

#include "Output.hpp"
#include "Pin.hpp"
#include "Error.hpp"

namespace nts {
    Output::Output(const std::string &name)
    {
        _name = name;
        _type = "Output";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
    }

    nts::Tristate Output::compute(std::size_t pin)
    {
        if (pin != 1)
            throw Error("Compute: Tried to compute an invalid pin");
        IComponent *component = _pins[0]->getLinkedComponent();
        int linked_pin = _pins[0]->getLinkedPin();

        dynamic_cast<AComponent *>(component)->compute(linked_pin);
        _pins[0]->setValue(dynamic_cast<AComponent *>(component)->getPins()[linked_pin]->getValue());
        return _pins[0]->getValue();
    }
}
