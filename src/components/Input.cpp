/*
** EPITECH PROJECT, 2019
** Input.cpp
** File description:
** Methods
*/

#include "Input.hpp"
#include "Pin.hpp"
#include "Error.hpp"

namespace nts {
    Input::Input(const std::string &name)
    {
        _name = name;
        _type = "Input";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
    }

    nts::Tristate Input::compute(std::size_t pin)
    {
        if (pin != 1)
            throw Error("Compute: Tried to compute an invalid pin");
        IComponent *component = _pins[0]->getLinkedComponent();
        int linked_pin = _pins[0]->getLinkedPin();

        dynamic_cast<AComponent *>(component)->getPins()[linked_pin]->setValue(_pins[0]->getValue());
        return _pins[0]->getValue();
    }
}
