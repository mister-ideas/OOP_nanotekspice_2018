/*
** EPITECH PROJECT, 2019
** False.cpp
** File description:
** Methods
*/

#include "components/False.hpp"
#include "components/Pin.hpp"
#include "core/Error.hpp"

namespace nts {
    False::False(const std::string &name)
    {
        _name = name;
        _type = "False";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins[0]->setValue(Tristate::FALSE);
    }

    nts::Tristate False::compute(std::size_t pin)
    {
        if (pin != 1)
            throw Error("Compute: Tried to compute an invalid pin");
        return _pins[0]->getValue();
    }
}
