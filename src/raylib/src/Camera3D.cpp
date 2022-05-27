/*
** EPITECH PROJECT, 2022
** Camera3D.cpp
** File description:
** Camera3D
*/

#include "../include/Camera3D.hpp"

raylib::Camera3D::Camera3D(::Vector3 _position, ::Vector3 _target, ::Vector3 _up, float _fovy) :
::Camera3D{_position, _target, _up, _fovy, CAMERA_PERSPECTIVE}
{
}

raylib::Camera3D::Camera3D(const ::Camera3D &cam)
{
    _setCamera3D(cam);
}

void raylib::Camera3D::BeginMode()
{
    ::BeginMode3D(*this);
}

void raylib::Camera3D::EndMode()
{
    ::EndMode3D();
}

void raylib::Camera3D::Update()
{
    ::UpdateCamera(this);
}

void raylib::Camera3D::SetMode(int mode) {
    ::SetCameraMode(*this, mode);
}

void raylib::Camera3D::_setCamera3D(const ::Camera3D &cam) {
        position = cam.position;
        target = cam.target;
        up = cam.up;
        fovy = cam.fovy;
        projection = cam.projection;
}