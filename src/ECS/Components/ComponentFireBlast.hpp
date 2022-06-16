/*
** EPITECH PROJECT, 2022
** ComponentFireBlast.hpp
** File description:
** ComponentFireBlast.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Vector3.hpp"

class ComponentFireBlast : public ecs::IComponent {
    enum Direction { North, Eats, South, West };

  public:
    ComponentFireBlast(Direction direction, raylib::Vector3 pos, raylib::Vector3 size);
    ~ComponentFireBlast() = default;

    void draw();

  private:
    raylib::Vector3 _pos;
    raylib::Vector3 _size;
};
