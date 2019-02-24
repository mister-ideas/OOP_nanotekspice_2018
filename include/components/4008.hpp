/*
** EPITECH PROJECT, 2019
** OrComponent.hpp
** File description:
** Class
*/

#ifndef ADDERCOMPONENT_HPP_
#define ADDERCOMPONENT_HPP_

#include "components/AComponent.hpp"

namespace nts {
    class AdderComponent : public nts::AComponent {
        public:
            AdderComponent(const std::string &name);
            ~AdderComponent() = default;
            nts::Tristate compute(std::size_t pin = 1);
        private:
            bool _isUndefined;
    };
};

#endif /* !ADDERCOMPONENT_HPP_ */
