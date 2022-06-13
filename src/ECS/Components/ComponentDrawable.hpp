/*
** EPITECH PROJECT, 2022
** ComponentDrawable
** File description:
** ComponentDrawable
*/

#pragma once

#include "IComponent.hpp"

class ComponentDrawable : public ecs::IComponent {
  public:
    ComponentDrawable(bool isDrawable2D = false, bool isDrawable3D = false) : _isDrawable2D(isDrawable2D), _isDrawable3D(isDrawable3D){};
    ComponentDrawable(const ComponentDrawable &other) = default;
    ~ComponentDrawable() = default;
    ComponentDrawable &operator=(const ComponentDrawable &other) = default;

    bool getIsDrawable2D() const;
    void setIsDrawable2D(bool);
    bool getIsDrawable3D() const;
    void setIsDrawable3D(bool);

  private:
    bool _isDrawable2D;
    bool _isDrawable3D;
};
