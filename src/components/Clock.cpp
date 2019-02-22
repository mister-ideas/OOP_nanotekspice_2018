/*
** EPITECH PROJECT, 2019
** Clock.cpp
** File description:
** Methods
*/

#include "components/Clock.hpp"
#include "components/Pin.hpp"
#include "core/Error.hpp"

namespace nts {
    Clock::Clock(const std::string &name)
    {
        _name = name;
        _type = "Clock";
        _pins.push_back(new Pin(Pin::PIN_TYPE::INPUT));
    }

    nts::Tristate Clock::compute(std::size_t pin)
    {
        if (pin != 1)
            throw Error("Compute: Tried to compute an invalid pin");
        return _pins[0]->getValue();
    }
}
