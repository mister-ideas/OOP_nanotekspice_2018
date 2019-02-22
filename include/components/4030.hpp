/*
** EPITECH PROJECT, 2019
** XorComponent.hpp
** File description:
** Class
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class XorComponent : public nts::AComponent {
        public:
            XorComponent(const std::string &name);
            ~XorComponent() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !NORCOMPONENT_HPP_ */
