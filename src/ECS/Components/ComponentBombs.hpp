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
    ComponentBombs(std::size_t max_bombs, std::size_t curr_bombs = 0) : _max_bombs(max_bombs), _curr_bombs(curr_bombs){};
    ~ComponentBombs() = default;

    std::size_t getNbMaxBombs() const;
    void setNbMaxBombs(std::size_t max_bombs);
    std::size_t getNbCurrBombs() const;
    void setNbCurrBombs(std::size_t curr_bombs);

  private:
    std::size_t _max_bombs;
    std::size_t _curr_bombs;
};
