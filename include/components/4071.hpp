/*
** EPITECH PROJECT, 2019
** OrComponent.hpp
** File description:
** Class
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class OrComponent : public nts::AComponent {
        public:
            OrComponent(const std::string &name);
            ~OrComponent() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !ORCOMPONENT_HPP_ */
