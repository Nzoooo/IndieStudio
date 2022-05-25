/*
** EPITECH PROJECT, 2022
** Vector3.cpp
** File description:
** Vector3
*/

#include "include/Vector3.hpp"
#include "include/RaylibException.hpp"

raylib::Vector3::Vector3(::Vector3 &vec)
{
    _setVector3(vec);
}

raylib::Vector3::Vector3(const Vector3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

raylib::Vector3::Vector3 &operator=(const Vector3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

raylib::Vector3::Vector3(float _x, float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
}

raylib::Vector3::Vector3(float _x, float _y)
{
    x = _x;
    y = _y;
    z = 0;
}

raylib::Vector3::Vector3(float _x)
{
    x = _x;
    y = 0;
    z = 0;
}

void raylib::Vector3::_setVector3(::Vector3 &vec) {
    x = vec.x;
    y = vec.y;
    z = vec.z;
}