/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <string>
#include <vector>
#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts {
    class AComponent : public nts::IComponent {
        public:
            virtual ~AComponent() = default;
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            const std::string &getName() const;
            const std::string &getType() const;
            std::vector<Pin *> getPins() const;
            void setName(const std::string &name);
            void setType(const std::string &type);

        protected:
            std::vector<Pin *> _pins;
            std::string _name;
            std::string _type;
    };
}

#endif /* !ACOMPONENT_HPP_ */
