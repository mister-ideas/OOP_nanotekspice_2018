/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include <unordered_map>
#include <functional>
#include "components/4071.hpp"
#include "components/4081.hpp"
#include "components/Input.hpp"
#include "components/Output.hpp"
#include "parser/Factory.hpp"
#include "core/Error.hpp"

namespace nts {
    IComponent *Factory::createComponent(const std::string &type, const std::string &name) const
    {
        std::unordered_map<std::string, std::function<IComponent *(const std::string &)>> ctors {
            {"4071", [](const std::string &name) { return new OrComponent(name); }},
            {"4081", [](const std::string &name) { return new AndComponent(name); }},
            {"output", [](const std::string &name) { return new Output(name); }},
            {"input", [](const std::string &name) { return new Input(name); }},
        };
        auto it = ctors.find(type);
        if (it == ctors.end())
            throw Error("Create: Unknown type");
        return it->second(name);
    }
}