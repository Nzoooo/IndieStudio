/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentSpeed
*/

#pragma once

#include <string>
#include "IComponent.hpp"

class ComponentSpeed : public ecs::IComponent {
  public:
    ComponentSpeed(std::size_t speed) : _speed(speed){};
    ~ComponentSpeed() = default;

    std::size_t getSpeed() const;
    void setSpeed(std::size_t speed);

  private:
    std::size_t _speed;
};
