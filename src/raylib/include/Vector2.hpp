/*
** EPITECH PROJECT, 2022
** Vector2.hpp
** File description:
** Vector2.hpp
*/

#pragma once

#include <ostream>
#include "raylib.hpp"

namespace raylib
{
    class Vector2 : public ::Vector2 {
      public:
        Vector2();
        Vector2(::Vector2 &vec);
        Vector2(const Vector2 &other);
        Vector2 &operator=(::Vector2 &vector2);
        Vector2(float _x, float _y);
        ~Vector2() = default;
        friend std::ostream &operator<<(std::ostream &os, const Vector2 &v);

      private:
        void _setVector2(::Vector2 &vec);
    };
} // namespace raylib
