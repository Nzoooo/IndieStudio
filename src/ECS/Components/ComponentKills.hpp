/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ComponentKills
*/

#pragma once

#include <string>
#include "IComponent.hpp"

class ComponentKills : public ecs::IComponent {
  public:
    ComponentKills();
    ~ComponentKills() = default;

    std::size_t getNbKills() const;
    void incrNbKills();

  private:
    std::size_t _nb_kills;
};
