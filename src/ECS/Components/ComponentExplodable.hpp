/*
** EPITECH PROJECT, 2022
** ComponentExplodable.hpp
** File description:
** ComponentExplodable.hpp
*/

#pragma once

#include <string>
#include "IComponent.hpp"

class ComponentExplodable : public ecs::IComponent {
  public:
    ComponentExplodable(std::size_t blastRange = 2) : _blastRange(blastRange){};
    ~ComponentExplodable() = default;

    std::size_t getBlastRange() const;

    void setBlastRange(std::size_t blastRange);

  private:
    std::size_t _blastRange;
};
