/*
** EPITECH PROJECT, 2022
** ComponentFireBlast.hpp
** File description:
** ComponentFireBlast.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Image.hpp"
#include "raylib/include/Texture.hpp"
#include "raylib/include/Vector3.hpp"

class ComponentFireBlast : public ecs::IComponent {
  public:
    enum Direction { North, South, East, West };
    ComponentFireBlast(Direction direction, raylib::Vector3 pos, raylib::Vector3 size, float time = 2.0);
    ~ComponentFireBlast() = default;

    void timer(float);
    float getTimer();

    raylib::Vector3 getPos() const;
    raylib::Vector3 getSize() const;
    void setSize(raylib::Vector3 size);

    void Draw();

  private:
    raylib::Vector3 _pos;
    raylib::Texture _texture;
    raylib::Vector3 _size;
    float _time;
};
