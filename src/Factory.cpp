/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include <unordered_map>
#include "Factory.hpp"
#include "Error.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "Input.hpp"
#include "Output.hpp"

namespace nts {
    Factory::Factory()
    {
    }

    Factory::~Factory()
    {
    }

    IComponent *Factory::create4071(const std::string &name)
    {
        return new OrComponent(name);
    }

    IComponent *Factory::create4081(const std::string &name)
    {
        return new AndComponent(name);
    }

    IComponent *Factory::createOutput(const std::string &name)
    {
        return new Output(name);
    }

    IComponent *Factory::createInput(const std::string &name)
    {
        return new Input(name);
    }

    IComponent *Factory::createComponent(const std::string &type,
    const std::string &name)
    {
        std::unordered_map<std::string, IComponent *(*)(const std::string &)> ctors {
            {"4071", &create4071},
            {"4081", &create4081},
            {"output", &createOutput},
            {"input", &createInput}
        };
        auto it = ctors.find(type);
        if (it == ctors.end())
            throw Error("Create: Unknown type");
        return (*it->second)(name);
    }
}