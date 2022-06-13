/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentTransparency
*/

#pragma once

#include <string>
#include "IComponent.hpp"
#include "raylib/include/Color.hpp"

class ComponentTransparency : public ecs::IComponent {
  public:
    ComponentTransparency(std::size_t transparency = 0) : _transparency(transparency){};
    ~ComponentTransparency() = default;

    std::size_t getTransparency() const;
    void setTransparency(std::size_t transparency);

    raylib::Color sumWithColor(raylib::Color color) const;

  private:
    std::size_t _transparency;
};
