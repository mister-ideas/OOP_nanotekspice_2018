/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Class
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {
    class AndComponent : public nts::AComponent {
        public:
            AndComponent();
            ~AndComponent();
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !ANDCOMPONENT_HPP_ */
