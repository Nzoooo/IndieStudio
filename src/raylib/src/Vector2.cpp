/*
** EPITECH PROJECT, 2022
** Vector2.cpp
** File description:
** Vector2
*/

#include "include/Vector2.hpp"
#include "include/RaylibException.hpp"

raylib::Vector2::Vector2(::Vector2 &vec)
{
    _setVector2(vec);
}

raylib::Vector2::Vector2(const Vector2 &other)
{
    x = other.x;
    y = other.y;
}

raylib::Vector2::Vector2 &operator=(const Vector2 &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

raylib::Vector2::Vector2(float _x, float _y)
{
    x = _x;
    y = _y;
}

raylib::Vector2::Vector2()
{
    x = 0;
    y = 0;
}

raylib::Vector2::Vector2 &operator=(::Vector2 &vector2)
{
    _setVector2(vector2);
    return *this;
}

void raylib::Vector2::_setVector2(::Vector2 &vec)
{
    x = vec.x;
    y = vec.y;
}