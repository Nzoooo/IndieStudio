/*
** EPITECH PROJECT, 2022
** ComponentCollider.hpp
** File description:
** ComponentCollider.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/BoundingBox.hpp"
#include "vector"

class ComponentCollider : public ecs::IComponent {
  public:
    typedef enum direction { NORTH, SOUTH, EAST, WEST };
    ComponentCollider()
    {
        _direction.reserve(4);
    };
    ~ComponentCollider() = default;

    raylib::BoundingBox &getCollision();
    void setCollision(raylib::BoundingBox collision);

    void add_vector(bool direction);
    bool getVector(direction direct);

  private:
    raylib::BoundingBox _collision;
    std::vector<bool> _direction;
};
