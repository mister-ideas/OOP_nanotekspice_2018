/*
** EPITECH PROJECT, 2019
** Output.cpp
** File description:
** Class
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include "AComponent.hpp"

namespace nts {
class Output : public AComponent {
public:
    Output();
    ~Output();
    nts::Tristate compute(std::size_t pin = 1);
    void setLink(std::size_t pin, nts::IComponent &other,
        std::size_t otherPin);
    void dump() const;

protected:
private:
};
}

#endif /* !OUTPUT_HPP_ */