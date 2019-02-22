/*
** EPITECH PROJECT, 2019
** Clock.cpp
** File description:
** Class
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
        public:
            Clock(const std::string &name);
            ~Clock() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !CLOCK_HPP_ */
