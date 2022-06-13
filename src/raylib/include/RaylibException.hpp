/*
** EPITECH PROJECT, 2022
** Raylib
** File description:
** Raylib
*/

#pragma once
#include <string>

namespace raylib
{
    class RaylibException : public std::exception {
      public:
        RaylibException(const std::string &message) : _message(message){};
        ~RaylibException() = default;

        const char *what() const noexcept override
        {
            return (_message.c_str());
        };

      protected:
      private:
        std::string _message;
    };
} // namespace raylib
