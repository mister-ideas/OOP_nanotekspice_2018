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

namespace nts {
    Main::Main()
    {
    }

    Main::~Main()
    {
    }

    int Main::core(int ac, char **av)
    {
        if (ac < 2) {
            std::cerr << "Error: Call: Not enough arguments" << std::endl;
            return 84;
        }
        Parser parser;
        try {
            _components = parser.parseFile(av[1]);
            //...
        } catch (Error &e) {
            //need to implement Error class
            std::cerr << "Error: " << e.what() << std::endl;
            return 84;
        }
        return 0;
    }
}

int main(int ac,  char **av)
{
    nts::Main main;
    return main.core(ac, av);
}
