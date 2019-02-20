/*
** EPITECH PROJECT, 2019
** Output.cpp
** File description:
** Class
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
    class Output : public AComponent {
        public:
            Output();
            ~Output();
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !OUTPUT_HPP_ */