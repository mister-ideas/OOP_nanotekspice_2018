/*
** EPITECH PROJECT, 2019
** Input.cpp
** File description:
** Methods
*/

#include "Input.hpp"
#include "Pin.hpp"

namespace nts {
    Input::Input()
    {
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
    }

    Input::~Input()
    {
    }

    nts::Tristate Input::compute(size_t)
    {
        IComponent *component = _pins[0]->getLinkedComponent();
        int pin = _pins[0]->getLinkedPin();

        dynamic_cast<AComponent *>(component)->getPins()[pin]->setValue(_pins[0]->getValue());
        return _pins[0]->getValue();
    }
}