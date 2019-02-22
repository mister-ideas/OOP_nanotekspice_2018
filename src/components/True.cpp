/*
** EPITECH PROJECT, 2019
** True.cpp
** File description:
** Methods
*/

#include "components/True.hpp"
#include "components/Pin.hpp"
#include "core/Error.hpp"

namespace nts {
    True::True(const std::string &name)
    {
        _name = name;
        _type = "True";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
        _pins[0]->setValue(Tristate::TRUE);
    }

    nts::Tristate True::compute(std::size_t pin)
    {
        if (pin != 1)
            throw Error("Compute: Tried to compute an invalid pin");
        return _pins[0]->getValue();
    }
}
