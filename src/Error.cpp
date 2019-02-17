/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &msg) : _msg(msg)
{
}

Error::~Error()
{
}

const char *Error::what() const noexcept
{
    return _msg.c_str();
}
