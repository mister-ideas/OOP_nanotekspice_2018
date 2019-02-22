/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Pin
*/

#include "Pin.hpp"

namespace nts {
    Pin::Pin(PIN_TYPE type) : _type(type), _value(UNDEFINED),
    _linked_component(nullptr), _linked_pin(-1)
    {
    }

    Pin::PIN_TYPE Pin::getType() const noexcept
    {
        return _type;
    }

    Tristate Pin::getValue() const noexcept
    {
        return _value;
    }

    IComponent *Pin::getLinkedComponent() const noexcept
    {
        return _linked_component;
    }

    int Pin::getLinkedPin() const noexcept
    {
        return _linked_pin;
    }

    void Pin::setType(Pin::PIN_TYPE type) noexcept
    {
        _type = type;
    }

    void Pin::setValue(Tristate value) noexcept
    {
        _value = value;
    }

    void Pin::setLinkedComponent(IComponent *component) noexcept
    {
        _linked_component = component;
    }

    void Pin::setLinkedPin(int pin) noexcept
    {
        _linked_pin = pin;
    }
}
