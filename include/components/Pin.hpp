/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "IComponent.hpp"

namespace nts {
    class Pin {
        public:
            enum PIN_TYPE {
                UNKNOWN,
                INPUT,
                OUTPUT,
                VSS,
                VDD
            };
            Pin(PIN_TYPE type = UNKNOWN);
            ~Pin() = default;
            PIN_TYPE getType() const noexcept;
            Tristate getValue() const noexcept;
            IComponent *getLinkedComponent() const noexcept;
            int getLinkedPin() const noexcept;
            void setType(PIN_TYPE type) noexcept;
            void setValue(Tristate value) noexcept;
            void setLinkedComponent(IComponent *component) noexcept;
            void setLinkedPin(int pin) noexcept;

        private:
            PIN_TYPE _type;
            Tristate _value;
            IComponent *_linked_component;
            int _linked_pin;
    };
}

#endif /* !PIN_HPP_ */
