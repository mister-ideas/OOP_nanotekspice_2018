/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include <unordered_map>
#include "Factory.hpp"
#include "Error.hpp"

namespace nts {
    Factory::Factory()
    {
    }

    Factory::~Factory()
    {
    }

    IComponent *Factory::create4071(const std::string &name)
    {
        //need to return new instance of component
        return nullptr;
    }

    IComponent *Factory::createComponent(const std::string &type,
    const std::string &name)
    {
        std::unordered_map<std::string, IComponent *(*)(const std::string &)> ctors {
            {"4071", &create4071}
            //other components...
        };
        auto it = ctors.find(type);
        if (it == ctors.end())
            throw Error("Create: Unknown type");
        return (*it->second)(name);
    }
}