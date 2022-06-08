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
    ComponentExplodable(std::size_t blastRange = 1, bool ableToExplode = false) : _blastRange(blastRange), _ableToExplode(ableToExplode){};
    ~ComponentExplodable() = default;

    std::size_t getBlastRange() const;
    bool getAbleToExplode() const;

    void setBlastRange(std::size_t blastRange);
    void setAbleToExplode(bool ableToExplode);

  private:
    std::size_t _blastRange;
    bool _ableToExplode;
};
