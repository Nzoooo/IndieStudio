/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentBombs
*/

#pragma once

#include <string>
#include "IComponent.hpp"

class ComponentBombs : public ecs::IComponent {
  public:
    ComponentBombs(std::size_t nb_bombs) : _nb_bombs(nb_bombs){};
    ~ComponentBombs() = default;

    std::size_t getNbBombs() const;
    void setNbBombs(std::size_t nb_bombs);

  private:
    std::size_t _nb_bombs;
};
