/*
** EPITECH PROJECT, 2022
** Vector3.cpp
** File description:
** Vector3
*/

#include "../include/Vector3.hpp"
#include "../include/RaylibException.hpp"

raylib::Vector3::Vector3(::Vector3 &vec)
{
    _setVector3(vec);
}

raylib::Vector3::Vector3(const raylib::Vector3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
}

raylib::Vector3 &raylib::Vector3::operator=(const raylib::Vector3 &other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

raylib::Vector3::Vector3(float _x, float _y, float _z) : ::Vector3{_x, _y, _z}
{
}

raylib::Vector3::Vector3() : ::Vector3{0.0f, 0.0f, 0.0f}
{
}

void raylib::Vector3::_setVector3(::Vector3 &vec)
{
    x = vec.x;
    y = vec.y;
    z = vec.z;
}

void raylib::Vector3::DrawCube(float width, float height, float length, ::Color color)
{
    ::DrawCube(*this, width, height, length, color);
}

void raylib::Vector3::DrawCube(const ::Vector3 &size, ::Color color)
{
    ::DrawCubeV(*this, size, color);
}

void raylib::Vector3::DrawCubeWires(float width, float height, float length, ::Color color)
{
    ::DrawCubeWires(*this, width, height, length, color);
}

void raylib::Vector3::DrawCubeWires(const ::Vector3 &size, ::Color color)
{
    ::DrawCubeWiresV(*this, size, color);
}

void raylib::Vector3::DrawCubeTexture(const ::Texture &texture, float width, float height, float length, ::Color color)
{
    ::DrawCubeTexture(texture, *this, width, height, length, color);
}

std::ostream &operator<<(std::ostream &os, const raylib::Vector3 &v)
{
    return os << "(" << v.x << "; " << v.y << "; " << v.z << ")";
}
