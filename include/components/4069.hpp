/*
** EPITECH PROJECT, 2019
** InverterComponent.hpp
** File description:
** Class
*/

#ifndef INVERTERCOMPONENT_HPP_
#define INVERTERCOMPONENT_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class InverterComponent : public nts::AComponent {
        public:
            InverterComponent(const std::string &name);
            ~InverterComponent() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !INVERTERCOMPONENT_HPP_ */
