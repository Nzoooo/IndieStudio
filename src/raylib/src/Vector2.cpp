/*
** EPITECH PROJECT, 2022
** Vector2.cpp
** File description:
** Vector2
*/

#include "../include/Vector2.hpp"
#include "../include/RaylibException.hpp"

raylib::Vector2::Vector2(::Vector2 vec)
{
    _setVector2(vec);
}

raylib::Vector2::Vector2(const raylib::Vector2 &other)
{
    x = other.x;
    y = other.y;
}

raylib::Vector2::Vector2(float _x, float _y) : ::Vector2{_x, _y}
{
}

raylib::Vector2::Vector2() : ::Vector2{0.0f, 0.0f}
{
}

raylib::Vector2 &raylib::Vector2::operator=(const Vector2 &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

void raylib::Vector2::_setVector2(::Vector2 &vec)
{
    x = vec.x;
    y = vec.y;
}

std::ostream &operator<<(std::ostream &os, const raylib::Vector2 &v)
{
    return os << "(" << v.x << "; " << v.y << ")";
}
