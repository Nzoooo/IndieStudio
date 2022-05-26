/*
** EPITECH PROJECT, 2022
** Camera3D.cpp
** File description:
** Camera3D
*/

#include "Camera3D.hpp"

raylib::Camera3D::Camera3D()
{
}

raylib::Camera3D::Camera3D(const ::Camera3D &cam)
{
    _setCamera3D(cam);
}

raylib::Camera3D::Camera3D(::Vector3 _position)
{
    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    target.x = 0.0f;
    target.y = 0.0f;
    target.z = 0.0f;
    position = _position;
    fovy = 0;
    projection = CAMERA_PERSPECTIVE;
}

void raylib::Camera3D::beginMode()
{
    ::BeginMode3D(*this);
}

void raylib::Camera3D::endMode()
{
    ::EndMode3D();
}

void raylib::Camera3D::update()
{
    ::UpdateCamera(this);
}

void raylib::Camera3D::setMode(int mode) {
    ::SetCameraMode(*this, mode);
}

void raylib::Camera3D::_setCamera3D(const ::Camera3D &cam) {
        position = cam.position;
        target = cam.target;
        up = cam.up;
        fovy = cam.fovy;
        projection = cam.projection;
}