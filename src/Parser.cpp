/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice
** File description:
** Parser
*/

#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include "Parser.hpp"
#include "Factory.hpp"
#include "AComponent.hpp"

namespace nts {
    Parser::Parser()
    {
    }

    Parser::~Parser()
    {
    }

    bool Parser::isEmpty(const std::string &line) const
    {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ' || line[i] != '\t')
                return false;
        }
        return true;
    }

    std::unordered_map<std::string, IComponent *> Parser::fillMap(std::stringstream &buff)
    {
        Factory factory;
        std::unordered_map<std::string, IComponent *> components;
        std::string line;
        std::regex regex("^([[:alnum:]]+)(\s+)([[:alnum:]]+)(\s+)((#)(.*))?$");
        std::smatch match;

        while (std::getline(buff, line) && line.find(".links:")) {
            if (std::regex_search(line, match, regex)) {
                if (components.find(match[2]) == components.end()) {
                    IComponent *temp = factory.createComponent(match[0], match[2]);
                    dynamic_cast<AComponent *>(temp)->setType(match[0]);
                    dynamic_cast<AComponent *>(temp)->setName(match[2]);
                    components[match[2]] = temp;
                } else {
                    //throw error
                }
            } else {
                //throw
            }
        }
    }

    std::unordered_map<std::string, IComponent *> Parser::parseFile(char *filename)
    {
        std::ifstream file(filename);
        std::string line;
        std::stringstream buff;

        if (!file)
            //throw error
        while (std::getline(file, line)) {
            if (isEmpty(line) || line[0] == '#')
                continue;
            buff << line << std::endl;
        }
        if (!line.find(".chipsets:"))
            return fillMap(buff);
        else
            //throw error
        return (*(new std::unordered_map<std::string, IComponent *>));
    }
}
