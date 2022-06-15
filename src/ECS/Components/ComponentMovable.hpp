/*
** EPITECH PROJECT, 2022
** ECS
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMovable
*/

#ifndef COMPONENTMOVABLE_HPP_
#define COMPONENTMOVABLE_HPP_

#include "IComponent.hpp"

class ComponentMovable : public ecs::IComponent {
  public:
    ComponentMovable(float speed = 0) : _speed(speed){};
    ~ComponentMovable() = default;

    float getSpeed() const;

    void setSpeed(int speed);

  private:
    float _speed;
};

#endif /* !COMPONENTMOVABLE_HPP_ */
