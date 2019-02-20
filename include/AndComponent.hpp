/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Class
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_

#include "AComponent.hpp"

class AndComponent : public nts::AComponent {
public:
    AndComponent();
    ~AndComponent();
    nts::Tristate compute(std::size_t pin = 1);

protected:
private:
};

#endif /* !ANDCOMPONENT_HPP_ */
