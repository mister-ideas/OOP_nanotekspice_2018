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
            ~Pin();
            const PIN_TYPE getType() const;
            const Tristate getValue() const;
            const IComponent *getLinkedComponent() const;
            const int getLinkedPin() const;
            void setType(PIN_TYPE type);
            void setValue(Tristate value);
            void setLinkedComponent(IComponent *component);
            void setLinkedPin(int pin);

        private:
            PIN_TYPE _type;
            Tristate _value;
            IComponent *_linked_component;
            int _linked_pin;
    };
}

#endif /* !PIN_HPP_ */
