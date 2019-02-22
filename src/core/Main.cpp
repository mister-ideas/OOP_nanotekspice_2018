/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Main
*/

#include <iostream>
#include "core/Main.hpp"
#include "core/Error.hpp"
#include "core/Commands.hpp"
#include "parser/Parser.hpp"

namespace nts {
    int Main::core(int ac, char **av) noexcept
    {
        Parser parser;
        Commands commands;

        if (ac < 2) {
            std::cerr << "Error: Call: Not enough arguments" << std::endl;
            return 84;
        }
        try {
            _components = parser.parseFile(av[1]);
            commands.checkParameters(_components, av);
            commands.simulate(_components);
            commands.display(_components);
            while (1)
                commands.readInput(_components);
        } catch (Error &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 84;
        }
        return 0;
    }
}

int main(int ac, char **av)
{
    nts::Main main;
    return main.core(ac, av);
}
