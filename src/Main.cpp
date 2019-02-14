/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Main
*/

#include <iostream>
#include "Main.hpp"
#include "Parser.hpp"

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
            std::cerr << "Error: Not enough arguments" << std::endl;
            return (1);
        }
        Parser parser;
        try {
            _components = parser.parse_file(av[1]);
            //...
        } catch (Error &e) {
            //need to implement Error class
            std::cerr << "Error: " << e.what() << std::endl;
            return (1);
        }
        return (0);
    }

    int main(int ac,  char **av)
    {
        return (Main::core(ac, av));
    }
}
