/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <unordered_map>
#include "IComponent.hpp"

namespace nts {
    class Parser {
        public:
            Parser();
            ~Parser();
            std::unordered_map<std::string, IComponent *> parseFile(char *filename);
            bool isEmpty(const std::string &line) const;
            std::unordered_map<std::string, IComponent *> fillMap(std::stringstream &buff);
    };
}

#endif /* !PARSER_HPP_ */
