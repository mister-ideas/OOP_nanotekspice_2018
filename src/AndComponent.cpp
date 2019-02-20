/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Methods
*/

#include "AndComponent.hpp"

AndComponent::AndComponent()
{
}

AndComponent::~AndComponent()
{
}

nts::Tristate AndComponent::compute(std::size_t pin)
{
    if (_pins[0]->getLinkedComponent()->compute() == nts::UNDEFINED || _pins[1]->getLinkedComponent()->compute() == nts::UNDEFINED)
        return nts::UNDEFINED;
    else if (_pins[0]->getLinkedComponent()->compute() == nts::TRUE && _pins[1]->getLinkedComponent()->compute() == nts::TRUE)
        return nts::TRUE;
    return nts::FALSE;
}