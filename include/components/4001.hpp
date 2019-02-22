/*
** EPITECH PROJECT, 2019
** NOrComponent.hpp
** File description:
** Class
*/

#ifndef NORCOMPONENT_HPP_
#define NORCOMPONENT_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class NorComponent : public nts::AComponent {
        public:
            NorComponent(const std::string &name);
            ~NorComponent() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !NORCOMPONENT_HPP_ */
