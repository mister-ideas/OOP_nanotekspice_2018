/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "OrComponent.hpp"

OrComponent::OrComponent()
{
}

OrComponent::~OrComponent()
{
}

nts::Tristate OrComponent::compute(std::size_t pin)
{
    if (_pins[0]->getLinkedComponent()->compute() == nts::UNDEFINED || _pins[1]->getLinkedComponent()->compute() == nts::UNDEFINED)
        return nts::UNDEFINED;
    else if (_pins[0]->getLinkedComponent()->compute() == nts::FALSE && _pins[1]->getLinkedComponent()->compute() == nts::FALSE)
        return nts::FALSE;
    return nts::TRUE;
}