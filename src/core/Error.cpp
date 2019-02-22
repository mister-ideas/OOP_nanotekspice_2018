/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Error
*/

#include "core/Error.hpp"

namespace nts {
    Error::Error(const std::string &msg) : _msg(msg)
    {
    }

    const char *Error::what() const noexcept
    {
        return _msg.c_str();
    }
}
