/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include <unordered_map>
#include <functional>
#include "components/4001.hpp"
#include "components/4011.hpp"
#include "components/4030.hpp"
#include "components/4071.hpp"
#include "components/4081.hpp"
#include "components/Input.hpp"
#include "components/Output.hpp"
#include "components/True.hpp"
#include "components/False.hpp"
#include "components/Clock.hpp"
#include "parser/Factory.hpp"
#include "core/Error.hpp"

namespace nts {
    IComponent *Factory::createComponent(const std::string &type, const std::string &name) const
    {
        std::unordered_map<std::string, std::function<IComponent *(const std::string &)>> ctors {
            {"4071", [](const std::string &name) { return new OrComponent(name); }},
            {"4081", [](const std::string &name) { return new AndComponent(name); }},
            {"4011", [](const std::string &name) { return new NandComponent(name); }},
            {"4001", [](const std::string &name) { return new NorComponent(name); }},
            {"4030", [](const std::string &name) { return new XorComponent(name); }},
            {"output", [](const std::string &name) { return new Output(name); }},
            {"input", [](const std::string &name) { return new Input(name); }},
            {"true", [](const std::string &name) { return new True(name); }},
            {"false", [](const std::string &name) { return new False(name); }},
            {"clock", [](const std::string &name) { return new Clock(name); }},
        };
        auto it = ctors.find(type);
        if (it == ctors.end())
            throw Error("Create: Unknown type");
        return it->second(name);
    }
}