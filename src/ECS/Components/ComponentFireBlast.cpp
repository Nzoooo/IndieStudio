/*
** EPITECH PROJECT, 2022
** ComponentFireBlast.cpp
** File description:
** ComponentFireBlast.cpp
*/

#include "ComponentFireBlast.hpp"

ComponentFireBlast::ComponentFireBlast(ComponentFireBlast::Direction side, raylib::Vector3 pos, raylib::Vector3 size) : _pos(pos), _size(size)
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
};

void ComponentFireBlast::Draw()
{
    this->_pos.DrawCubeTexture(this->_texture, this->_size.x, this->_size.y, this->_size.z, raylib::Color::White());
}
