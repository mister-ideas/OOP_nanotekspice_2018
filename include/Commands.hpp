/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Commands
*/

#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include <string>
#include <unordered_map>
#include "IComponent.hpp"

namespace nts {
    class Commands {
        public:
            Commands() = default;
            ~Commands() = default;
            void changeInputValue(std::unordered_map<std::string, IComponent *> _components, const std::string &name, int value);
            void checkParameters(std::unordered_map<std::string, IComponent *> components, char **av);
            void simulate(std::unordered_map<std::string, IComponent *> components) const;
            void display(std::unordered_map<std::string, IComponent *> components) const;
    };
}

#endif /* !COMMANDS_HPP_ */
