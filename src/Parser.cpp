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
        static std::regex const regex("^(([[:alnum:]]+)(:{1})([[:alnum:]]+))(\\s+)(([[:alnum:]]+)(:{1})([[:alnum:]]+))(\\s*)((#)(.*))?$");
        std::smatch match;
        std::unordered_map<std::string, IComponent *>::iterator component1;
        std::unordered_map<std::string, IComponent *>::iterator component2;

        while (std::getline(buff, line)) {
            if (std::regex_search(line, match, regex)) {
                component1 = components.find(match[2]);
                component2 = components.find(match[7]);
                if (component1 == components.end() || component2 == components.end())
                    throw Error("Link: Unknown component name");
                else {
                    component1->second->setLink(stoi(match[4]), *(component2->second), stoi(match[9]));
                    component2->second->setLink(stoi(match[9]), *(component1->second), stoi(match[4]));
                }
            }
        }
        for (std::unordered_map<std::string, IComponent *>::iterator it = components.begin(); it != components.end(); it++) {
            std::vector<Pin *> pins = dynamic_cast<AComponent *>(it->second)->getPins();
            int nb = 0;
            for (int i = 0; i < pins.size(); i++) {
                if (pins[i]->getLinkedComponent() == nullptr || pins[i]->getLinkedPin() == -1)
                    nb++;
            }
            if (nb == pins.size())
                throw Error("Link: One or multiple component(s) pin(s) don't have linked component and/or linked pin");
        }
    }

    std::unordered_map<std::string, IComponent *> Parser::fillMap(std::stringstream &buff)
    {
        Factory factory;
        std::unordered_map<std::string, IComponent *> components;
        std::string line;
        static std::regex const regex("^([[:alnum:]]+)(\\s+)([[:alnum:]]+)(\\s*)((#)(.*))?$");
        std::smatch match;

        while (std::getline(buff, line) && line.find(".links:") == std::string::npos) {
            if (std::regex_search(line, match, regex)) {
                if (components.find(match[3]) == components.end()) {
                    IComponent *temp = factory.createComponent(match[1], match[3]);
                    components[match[3]] = temp;
                } else
                    throw Error("Create: Component name already used");
            } else
                throw Error("Create: Invalid component line");
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
        file.close();
        std::getline(buff, line);
        if (line.find(".chipsets:") != std::string::npos)
            return fillMap(buff);
        else
            throw Error("Create: No chipsets line");
        return (*(new std::unordered_map<std::string, IComponent *>));
    }
}
