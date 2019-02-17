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
#include "Error.hpp"

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

    void Parser::fillLinks(std::stringstream &buff, std::unordered_map<std::string, IComponent *> components)
    {
        std::string line;
        std::regex regex("^(([[:alnum:]]+)(:{1})([[:alnum:]]+))(\s+)(([[:alnum:]]+)(:{1})([[:alnum:]]+))(\s*)((#)(.*))?$");
        std::smatch match;
        std::unordered_map<std::string, IComponent *>::iterator component1;
        std::unordered_map<std::string, IComponent *>::iterator component2;

        while (std::getline(buff, line)) {
            if (std::regex_search(line, match, regex)) {
                component1 = components.find(match[1]);
                component2 = components.find(match[6]);
                if (component1 == components.end() || component2 == components.end())
                    throw Error("Link: Unknown component name");
                else {
                    component1->second->setLink(stoi(match[3]), *(component2->second), stoi(match[8]));
                    component2->second->setLink(stoi(match[8]), *(component1->second), stoi(match[3]));
                }
            }
        }
    }

    std::unordered_map<std::string, IComponent *> Parser::fillMap(std::stringstream &buff)
    {
        Factory factory;
        std::unordered_map<std::string, IComponent *> components;
        std::string line;
        std::regex regex("^([[:alnum:]]+)(\s+)([[:alnum:]]+)(\s*)((#)(.*))?$");
        std::smatch match;

        while (std::getline(buff, line) && line.find(".links:") == std::string::npos) {
            if (std::regex_search(line, match, regex)) {
                if (components.find(match[2]) == components.end()) {
                    IComponent *temp = factory.createComponent(match[0], match[2]);
                    dynamic_cast<AComponent *>(temp)->setType(match[0]);
                    dynamic_cast<AComponent *>(temp)->setName(match[2]);
                    components[match[2]] = temp;
                } else
                    throw Error("Create: Component name already used");
            } else
                throw Error("Create: No components");
        }
        if (line.find(".links:") != std::string::npos)
            fillLinks(buff, components);
        return components;
    }

    std::unordered_map<std::string, IComponent *> Parser::parseFile(char *filename)
    {
        std::ifstream file(filename);
        std::string line;
        std::stringstream buff;

        if (!file)
            throw Error("File: No such file");
        while (std::getline(file, line)) {
            if (isEmpty(line) || line[0] == '#')
                continue;
            buff << line << std::endl;
        }
        if (line.find(".chipsets:") != std::string::npos)
            return fillMap(buff);
        else
            throw Error("Create: No chipsets line");
        return (*(new std::unordered_map<std::string, IComponent *>));
    }
}
