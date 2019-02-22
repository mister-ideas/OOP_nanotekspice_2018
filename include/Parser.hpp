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
            Parser() = default;
            ~Parser() = default;
            std::unordered_map<std::string, IComponent *> parseFile(char *filename);
            bool isEmpty(const std::string &line) const;
            std::unordered_map<std::string, IComponent *> fillMap(std::stringstream &buff);
            void fillLinks(std::stringstream &buff, std::unordered_map<std::string, IComponent *> components);
    };
}

#endif /* !PARSER_HPP_ */
