/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Pin
*/

#include "Pin.hpp"

namespace nts {
    Pin::Pin(PIN_TYPE type) : _type(type), _value(UNDEFINED),
    _linked_component(NULL), _linked_pin(0)
    {
    }

    Pin::~Pin()
    {
    }

    const Pin::PIN_TYPE Pin::getType() const
    {
        return _type;
    }

    const Tristate Pin::getValue() const
    {
        return _value;
    }

    const IComponent *Pin::getLinkedComponent() const
    {
        return _linked_component;
    }

    const int Pin::getLinkedPin() const
    {
        return _linked_pin;
    }

    void Pin::setType(Pin::PIN_TYPE type)
    {
        _type = type;
    }

    void Pin::setValue(Tristate value)
    {
        _value = value;
    }

    void Pin::setLinkedComponent(IComponent *component)
    {
        _linked_component = component;
    }

    void Pin::setLinkedPin(int pin)
    {
        _linked_pin = pin;
    }
}
