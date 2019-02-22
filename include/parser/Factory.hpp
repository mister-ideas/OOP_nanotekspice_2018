/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "components/IComponent.hpp"

namespace nts {
    class Factory {
        public:
            Factory() = default;
            ~Factory() = default;
            IComponent *createComponent(const std::string &type, const std::string &name) const;
    };
}

#endif /* !FACTORY_HPP_ */
