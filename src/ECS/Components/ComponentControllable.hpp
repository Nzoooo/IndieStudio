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
    ComponentControllable(int gamepadId = -1) : _gamepadId(gamepadId){};
    ~ComponentControllable() = default;

    void setGamepadId(int gamepadId);
    int getGamepadId();

  protected:
  private:
    int _gamepadId = -1;
};
