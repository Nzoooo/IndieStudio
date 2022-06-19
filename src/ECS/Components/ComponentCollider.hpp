/*
** EPITECH PROJECT, 2022
** ComponentCollider.hpp
** File description:
** ComponentCollider.hpp
*/

#pragma once

#include <chrono>
#include "IComponent.hpp"

class ComponentCollider : public ecs::IComponent {
  public:
    ComponentCollider(bool isAbleToCollide = true) : _isAbleToCollide(isAbleToCollide){};
    ~ComponentCollider() = default;

    bool getIsAbleToCollide() const;
    void setIsAbleToCollide(bool isAbleToCollide);
    void setTimeNonCollide();
    std::chrono::time_point<std::chrono::system_clock> getTimeNonCollide() const;

  private:
    bool _isAbleToCollide;
    std::chrono::time_point<std::chrono::system_clock> _timeNonCollide;
};
