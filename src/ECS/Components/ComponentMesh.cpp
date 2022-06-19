/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMesh
*/

#include "ComponentMesh.hpp"

ComponentMesh::~ComponentMesh()
{
}

void ComponentMesh::setPos(raylib::Vector3 initialPos)
{
    _initialPos = initialPos;
}

raylib::Vector3 ComponentMesh::getPos() const
{
    return (_initialPos);
}

void ComponentMesh::setSize(raylib::Vector3 size)
{
    _size = size;
}

raylib::Vector3 ComponentMesh::getSize() const
{
    return (_size);
}

raylib::Color ComponentMesh::getColor() const
{
    return (_color);
}

void ComponentMesh::Draw()
{
    DrawModel(_model, _initialPos, 1.0f, _color);
}
