/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Class
*/

#ifndef NANDCOMPONENT_HPP_
#define NANDCOMPONENT_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class NandComponent : public nts::AComponent {
        public:
            NandComponent(const std::string &name);
            ~NandComponent() = default;
            nts::Tristate compute(std::size_t pin = 1);
    };
};

#endif /* !NANDCOMPONENT_HPP_ */
