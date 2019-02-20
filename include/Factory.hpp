/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "IComponent.hpp"

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory();
            IComponent *createComponent(const std::string &type,
            const std::string &name);
            static IComponent *create4071(const std::string &name);
            static IComponent *create4081(const std::string &name);
            static IComponent *createOutput(const std::string &name);
            static IComponent *createInput(const std::string &name);
    };
}

#endif /* !FACTORY_HPP_ */
