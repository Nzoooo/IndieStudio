/*
** EPITECH PROJECT, 2022
** ComponentExplosion.hpp
** File description:
** ComponentExplosion.hpp
*/

#pragma once

#include <string>
#include "IComponent.hpp"

class ComponentExplosion : public ecs::IComponent {
  public:
    ComponentExplosion(std::string labelPlayerOfBomb, bool readyToExplode = false, float timeLeft = 3.0)
        : _labelPlayerOfBomb(labelPlayerOfBomb), _readyToExplode(readyToExplode), _timeLeft(timeLeft){};
    ~ComponentExplosion() = default;

    std::string getLabelPlayerOfBomb();
    bool getReadyToExplode() const;
    float getTimeLeft() const;
    void setReadyToExplode(bool readyToExplode);
    void setTimeLeft(float timeLeft);

  private:
    std::string _labelPlayerOfBomb;
    bool _readyToExplode;
    float _timeLeft;
};
