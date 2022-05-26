/*
** EPITECH PROJECT, 2022
** Camera2D.cpp
** File description:
** Camera2D
*/

#include "Camera2D.hpp"

raylib::Camera2D::Camera2D()
{
}

raylib::Camera2D::Camera2D(const ::Camera2D& camera)
{
    _setCamera2D(camera);
}

raylib::Camera2D::Camera2D(::Vector2 _offset, ::Vector2 _target)
{
    offset = _offset;
    target = _target;
    rotation = 0.0f
    zoom = 1.0f;
}

void raylib::Camera2D::beginMode()
{
    ::BeginMode2D(*this);
}

void raylib::Camera2D::endMode()
{
    ::EndMode2D();
}

void raylib::Camera2D::_setCamera2D(const ::Camera2D& cam) {
    offset = cam.offset;
    target = cam.target;
    rotation = cam.rotation;
    zoom = cam.zoom;
}