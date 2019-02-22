/*
** EPITECH PROJECT, 2019
** Input.cpp
** File description:
** Class
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class Input : public AComponent {
        public:
            Input(const std::string &name);
            ~Input() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !INPUT_HPP_ */
