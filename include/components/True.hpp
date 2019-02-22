/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class True : public AComponent {
        public:
            True(const std::string &name);
            ~True() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
}

#endif /* !TRUE_HPP_ */
