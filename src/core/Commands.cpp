/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Commands
*/

#include <regex>
#include "core/Commands.hpp"
#include "core/Error.hpp"
#include "components/AComponent.hpp"

namespace nts {
    void Commands::changeInputValue(std::unordered_map<std::string, IComponent *> components, const std::string &name, int value, int mode) const
    {
        auto it = components.find(name);
        if (it == components.end())
            throw Error("Init: Unknown input name");
        if (mode == 1 && !strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Clock"))
            throw Error("Init: Tried to change value of a clock component during execution");
        if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Input")
        || !strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Clock"))
            dynamic_cast<AComponent *>(it->second)->getPins()[0]->setValue(value ? Tristate::TRUE : Tristate::FALSE);
        else
            throw Error("Init: Tried to change value for a non-input/clock component");
    }

    void Commands::checkParameters(std::unordered_map<std::string, IComponent *> components, char **av) const
    {
        std::string parameter;
        static std::regex const regex("^([[:alnum:]]+)(={1})(0{1}|1{1})$");
        std::smatch match;

        for (int i = 2; av[i]; i++) {
            parameter = av[i];
            if (std::regex_search(parameter, match, regex))
                changeInputValue(components, match[1], stoi(match[3]), 0);
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

    void Commands::readInput(std::unordered_map<std::string, IComponent *> components) const noexcept
    {
        static std::regex const regex("^([[:alnum:]]+)(={1})(0{1}|1{1})$");
        std::smatch match;
        std::string input;

        std::cout << "> ";
        try {
            if (std::getline(std::cin, input)) {
                if (input.empty())
                    return;
                if (!strcmp(input.c_str(), "exit"))
                    exit(0);
                else if (!strcmp(input.c_str(), "display"))
                    display(components);
                else if (!strcmp(input.c_str(), "simulate"))
                    simulate(components);
                else if (!strcmp(input.c_str(), "loop"))
                    loop(components);
                else if (!strcmp(input.c_str(), "dump"))
                    dump(components);
                else {
                    if (std::regex_search(input, match, regex))
                        changeInputValue(components, match[1], stoi(match[3]), 1);
                    else
                        throw Error("Init: Wrong command/input value change");
                }
            } else {
                std::cout << std::endl;
                exit(0);
            }
        } catch (Error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void Commands::display(std::unordered_map<std::string, IComponent *> components) const noexcept
    {
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++) {
            if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Output")) {
                Tristate value = dynamic_cast<AComponent *>(it->second)->getPins()[0]->getValue();
                std::cout << dynamic_cast<AComponent *>(it->second)->getName().c_str() << '=' << (value == Tristate::UNDEFINED ? 'U' : value) << std::endl;
            }
        }
    }

    void Commands::simulate(std::unordered_map<std::string, IComponent *> components) const noexcept
    {
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++) {
            if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Output"))
                it->second->compute(1);
            else if (!strcmp(dynamic_cast<AComponent *>(it->second)->getType().c_str(), "Clock")) {
                Tristate value = dynamic_cast<AComponent *>(it->second)->getPins()[0]->getValue();
                dynamic_cast<AComponent *>(it->second)->getPins()[0]->setValue(value == Tristate::TRUE ? Tristate::FALSE : Tristate::TRUE);
            }
        }
    }

    void Commands::loop(std::unordered_map<std::string, IComponent *> components) const noexcept
    {
        while (true) {
            simulate(components);
            display(components);
        }
    }

    void Commands::dump(std::unordered_map<std::string, IComponent *> components) const noexcept
    {
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++)
            it->second->dump();
    }
}
