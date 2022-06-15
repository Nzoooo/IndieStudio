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
    ComponentExplodable(std::size_t blastRange = 3, bool readyToExplode = false, float timeLeft = 3.0)
        : _blastRange(blastRange), _readyToExplode(readyToExplode), _timeLeft(timeLeft){};
    ~ComponentExplodable() = default;

    std::size_t getBlastRange() const;
    bool getReadyToExplode() const;
    float getTimeLeft() const;

    void setBlastRange(std::size_t blastRange);
    void setReadyToExplode(bool readyToExplode);
    void setTimeLeft(float timeLeft);

  private:
    std::size_t _blastRange;
    bool _readyToExplode;
    float _timeLeft;
};
