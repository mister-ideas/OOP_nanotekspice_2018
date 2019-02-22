/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class False : public AComponent {
        public:
            False(const std::string &name);
            ~False() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
}

#endif /* !FALSE_HPP_ */
