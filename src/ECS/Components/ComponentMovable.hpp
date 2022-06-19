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

    ComponentMovable(Direction direction = Direction::LEFT, float speed = 0) : _direction(direction), _speed(speed){};
    ~ComponentMovable() = default;

    Direction getDirection() const;
    float getSpeed() const;

    void setDirection(Direction direction);
    void setSpeed(float speed);

  private:
    Direction _direction;
    float _speed;
    bool _ableToMove;
};

#endif /* !COMPONENTMOVABLE_HPP_ */
