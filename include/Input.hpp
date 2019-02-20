/*
** EPITECH PROJECT, 2019
** Input.cpp
** File description:
** Class
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "AComponent.hpp"

namespace nts {
class Input : public AComponent {
public:
    Input();
    ~Input();
    nts::Tristate compute(std::size_t pin = 1);
    void setLink(std::size_t pin, nts::IComponent &other,
        std::size_t otherPin);
    void dump() const;

protected:
private:
};
}

#endif /* !INPUT_HPP_ */
