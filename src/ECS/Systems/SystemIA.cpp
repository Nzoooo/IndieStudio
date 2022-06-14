/*
** EPITECH PROJECT, 2022
** SystemIA.cpp
** File description:
** SystemIA.cpp
*/

#include "SystemIA.hpp"

SystemIA::SystemIA() : _ia(new ecs::IEntity)
{
    if (/* entoure de deux murs en x-1, y-1 || x+1, y-1 */)
        _ia->add<ComponentMovable>(ComponentMovable::Direction::DOWN, 0.1);
    if (/* entoure de deux murs en x-1, y+1 || x+1, y+1 */)
        _ia->add<ComponentMovable>(ComponentMovable::Direction::UP, 0.1);
    _ia->add<ComponentDrawable>(false, true);
    _ia->add<ComponentKillable>();
    _ia->add<ComponentTransform>(50, 50, 50, 50);
    _ia->add<ComponentCollider>();
}

SystemIA::~SystemIA()
{
    if (_ia)
        delete _ia;
}

ecs::IComponent *SystemIA::getBombInRange(ecs::IComponent *bomb) const
{
    if ((bomb->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() &&
        abs(bomb->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY()) <= bomb->get<ComponentExplodable>()->getBlastRange()) ||
        (bomb->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() &&
        abs(bomb->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX()) <= bomb->get<ComponentExplodable>()->getBlastRange()))
        return (bomb);
    return (nullptr);
}

void SystemIA::setDirectionWithBomb(ecs::IComponent *bomb)
{
    if (bomb->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX()) {
        if (bomb->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY() >= 0) {
            _ia->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::UP);
        }
        if (bomb->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY() < 0) {
            _ia->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::DOWN);
        }
    } else {
        if (bomb->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX() >= 0) {
            _ia->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::LEFT);
        }
        if (bomb->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX() < 0) {
            _ia->get<ComponentMovable>()->setDirection(ComponentMovable::Direction::RIGHT);
        }
    }
}

bool SystemIA::isKillableBlockInRange() const
{
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    for (auto *b : blocks) {
        if (b->has<ComponentKillable>() && b->has<ComponentTransform>()) {
            if (b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() && b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() + speed ||
                b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() && b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() - speed ||
                b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() && b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() + speed ||
                b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() && b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() - speed)
                return (true);
        }
    }
    return (false);
}
