/*
** EPITECH PROJECT, 2022
** ComponentControllable
** File description:
** ComponentControllable
*/

#pragma once

#include "IComponent.hpp"

class ComponentControllable : public ecs::IComponent {
  public:
    ComponentControllable() = default;
    ~ComponentControllable() = default;

    void setGamepadId(int gamepadNumber);
    int getGamepadId();

  protected:
  private:
    int _gamepadId = -1;
};
