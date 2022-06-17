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
    enum side { NORTH, SOUTH, EAST, WEST };

    ComponentCollider()
    {
        _direction.reserve(4);
        for (std::size_t i = 0; i < 4; i++)
            _direction.push_back(false);
    };
    ~ComponentCollider() = default;

    raylib::BoundingBox &getCollision();
    void setCollision(raylib::BoundingBox collision);

    void add_vector(bool direct);
    bool getVector(side direct);
    void clearVector();

  private:
    raylib::BoundingBox _collision;
    std::vector<bool> _direction;
};
