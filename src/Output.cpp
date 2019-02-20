/*
** EPITECH PROJECT, 2019
** Output.cpp
** File description:
** Methods
*/

#include "Output.hpp"
#include "Pin.hpp"

namespace nts {
    Output::Output()
    {
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
    }

    Output::~Output()
    {
    }

    nts::Tristate Output::compute(size_t)
    {
        IComponent *component = _pins[0]->getLinkedComponent();
        int pin = _pins[0]->getLinkedPin();

        dynamic_cast<AComponent *>(component)->getPins()[pin]->setValue(_pins[0]->getValue());
        return _pins[0]->getValue();
    }
}