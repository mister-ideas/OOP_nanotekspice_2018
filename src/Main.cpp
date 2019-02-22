/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Main
*/

#include <iostream>
#include "Main.hpp"
#include "Parser.hpp"
#include "Error.hpp"
#include "Commands.hpp"

namespace nts {
    int Main::core(int ac, char **av)
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
            //listen std::cin
            //...
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
