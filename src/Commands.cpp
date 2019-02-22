/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Commands
*/

#include <regex>
#include "Commands.hpp"
#include "Error.hpp"
#include "AComponent.hpp"

namespace nts {
    void Commands::changeInputValue(std::unordered_map<std::string, IComponent *> components, const std::string &name, int value)
    {
        auto it = components.find(name);
        if (it == components.end())
            throw Error("Init: Unknown input name");
        if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Input")
        || !strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Clock"))
            dynamic_cast<AComponent *>(it->second)->getPins()[0]->setValue(value ? Tristate::TRUE : Tristate::FALSE);
        else
            throw Error("Init: Tried to init other component type than input or clock");
    }

    void Commands::checkParameters(std::unordered_map<std::string, IComponent *> components, char **av)
    {
        std::string parameter;
        static std::regex const regex("^([[:alnum:]]+)(={1})(0{1}|1{1})$");
        std::smatch match;

        for (int i = 2; av[i]; i++) {
            parameter = av[i];
            if (std::regex_search(parameter, match, regex))
                changeInputValue(components, match[1], stoi(match[3]));
            else
                throw Error("Init: Wrong input initialization");
        }
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++) {
            if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Input")
            || !strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Clock")) {
                if (dynamic_cast<AComponent *>(it->second)->getPins()[0]->getValue() == Tristate::UNDEFINED)
                    throw Error("Init: One or multiple input or clock component(s) are not init");
            }
        }
    }

    void Commands::simulate(std::unordered_map<std::string, IComponent *> components) const
    {
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++) {
            if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Output"))
                it->second->compute(1);
        }
    }

    void Commands::display(std::unordered_map<std::string, IComponent *> components) const
    {
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++) {
            if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Output"))
                std::cout << dynamic_cast<AComponent *>(it->second)->getName().c_str() << '=' << dynamic_cast<AComponent *>(it->second)->getPins()[0]->getValue() << std::endl;
        }
    }
}
