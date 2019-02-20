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
    IComponent* compo = _pins[0]->getLinkedComponent();
    int pin = _pins[0]->getLinkedPin();

    dynamic_cast<AComponent*>(compo)->getPins()[pin]->setValue(_pins[0]->getValue());
    return _pins[0]->getValue();
}

void Input::dump() const
{
    std::cout << _name << " " << _type << std::endl;
}

void Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1)
        return;
    _pins[pin - 1]->setLinkedComponent(&other);
    _pins[pin - 1]->setLinkedPin(otherPin - 1);
}

}