/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <map>
#include "components/IComponent.hpp"

namespace nts {
    class Parser {
        public:
            Parser() = default;
            ~Parser() = default;
            bool isEmpty(const std::string &line) const noexcept;
            void fillLinks(std::stringstream &buff, std::map<std::string, IComponent *> components) const;
            std::map<std::string, IComponent *> fillMap(std::stringstream &buff) const;
            std::map<std::string, IComponent *> parseFile(char *filename) const;
    };
}

#endif /* !PARSER_HPP_ */
