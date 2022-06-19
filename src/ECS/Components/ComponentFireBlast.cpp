/*
** EPITECH PROJECT, 2022
** ComponentFireBlast.cpp
** File description:
** ComponentFireBlast.cpp
*/

#include "ComponentFireBlast.hpp"

ComponentFireBlast::ComponentFireBlast(ComponentFireBlast::Direction side, raylib::Vector3 pos, raylib::Vector3 size, float time)
    : _pos(pos), _size(size), _time(time)
{
    raylib::Image image;
    image.Load("assets/flamme.png");
    if (side == Direction::North) {
        image.ImageRotateCW();
        image.ImageRotateCW();
    } else if (side == Direction::West)
        image.ImageRotateCW();
    else if (side == Direction::East) {
        image.ImageRotateCW();
        image.ImageRotateCW();
        image.ImageRotateCW();
    }
    _texture.Load(image);
}

void ComponentFireBlast::timer(float time)
{
    this->_time -= time;
}

float ComponentFireBlast::getTimer()
{
    return (this->_time);
}

void ComponentFireBlast::Draw()
{
    this->_pos.DrawCubeTexture(this->_texture, this->_size.x, this->_size.y, this->_size.z, raylib::Color::White());
}

raylib::Vector3 ComponentFireBlast::getPos() const
{
    return (_pos);
}

raylib::Vector3 ComponentFireBlast::getSize() const
{
    return (_size);
}

void ComponentFireBlast::setSize(raylib::Vector3 size)
{
    _size = size;
}
