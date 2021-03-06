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
#include "components/IComponent.hpp"
#include "components/Pin.hpp"

namespace nts {
    class AComponent : public nts::IComponent {
        public:
            virtual ~AComponent() = default;
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            void setLink(std::size_t pin, nts::IComponent &other,
            std::size_t otherPin);
            void dump() const noexcept;
            const std::string &getName() const noexcept;
            const std::string &getType() const noexcept;
            std::vector<Pin *> getPins() const noexcept;
            void setName(const std::string &name) noexcept;
            void setType(const std::string &type) noexcept;

        protected:
            std::vector<Pin *> _pins;
            std::string _name;
            std::string _type;
    };
}

#endif /* !ACOMPONENT_HPP_ */
