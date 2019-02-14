/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Main
*/

#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <unordered_map>
#include "IComponent.hpp"

namespace nts {
    class Main {
        public:
            Main();
            ~Main();
            static int core(int ac, char **av);

        private:
            static std::unordered_map<std::string, IComponent *> _components;
    };
}

#endif /* !MAIN_HPP_ */
