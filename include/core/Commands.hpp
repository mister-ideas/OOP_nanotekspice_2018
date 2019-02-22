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
            void changeInputValue(std::unordered_map<std::string, IComponent *> _components, const std::string &name, int value) const;
            void checkParameters(std::unordered_map<std::string, IComponent *> components, char **av) const;
            void simulate(std::unordered_map<std::string, IComponent *> components) const noexcept;
            void display(std::unordered_map<std::string, IComponent *> components) const noexcept;
    };
}

#endif /* !COMMANDS_HPP_ */
