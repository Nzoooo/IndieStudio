/*
** EPITECH PROJECT, 2022
** SystemRender
** File description:
** SystemRender
*/

#pragma once

#include "ISystem.hpp"

class SystemRender : ecs::ISystem {
  public:
    SystemRender() = default;
    SystemRender(const SystemRender &other) = delete;
    ~SystemRender() = default;
    SystemRender &operator=(const SystemRender &other) = delete;

  protected:
  private:
};
