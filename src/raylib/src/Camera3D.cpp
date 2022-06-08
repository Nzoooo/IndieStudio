/*
** EPITECH PROJECT, 2022
** Camera3D.cpp
** File description:
** Camera3D
*/

#include "../include/Camera3D.hpp"

raylib::Camera3D::Camera3D(::Vector3 _position, ::Vector3 _target, ::Vector3 _up, float _fovy) : ::Camera3D{_position, _target, _up, _fovy, CAMERA_PERSPECTIVE}
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

void raylib::Camera3D::SetMode(CameraMode mode)
{
    ::SetCameraMode(*this, mode);
}

void raylib::Camera3D::_setCamera3D(const ::Camera3D &cam)
{
    position = cam.position;
    target = cam.target;
    up = cam.up;
    fovy = cam.fovy;
    projection = cam.projection;
}

CameraMode raylib::Camera3D::CameraCustom()
{
    return (CAMERA_CUSTOM);
}

CameraMode raylib::Camera3D::CameraFree()
{
    return (CAMERA_FREE);
}

CameraMode raylib::Camera3D::CameraOrbital()
{
    return (CAMERA_ORBITAL);
}

CameraMode raylib::Camera3D::CameraFirstPerson()
{
    return (CAMERA_FIRST_PERSON);
}

CameraMode raylib::Camera3D::CameraThirdPerson()
{
    return (CAMERA_THIRD_PERSON);
}
