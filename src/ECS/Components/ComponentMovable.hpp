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
    enum Direction { LEFT, RIGHT, UP, DOWN };
    ComponentMovable(float speed = 0.1f) : _speed(speed){};
    ~ComponentMovable() = default;

    Direction getDirection() const;
    float getSpeed() const;

    void setSpeed(float speed);
    void setDirection(Direction direction);

  private:
    float _speed;
    Direction _direction;
};

#endif /* !COMPONENTMOVABLE_HPP_ */
