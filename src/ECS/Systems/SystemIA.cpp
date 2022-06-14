/*
** EPITECH PROJECT, 2022
** SystemIA.cpp
** File description:
** SystemIA.cpp
*/

#include "SystemIA.hpp"

SystemIA::SystemIA(ecs::Core &core, int posX, int posY) : _ia(new ecs::IEntity), _core(&core)
{
    if (checkCollisionAt(posX - 1, posY - 1) || checkCollisionAt(posX + 1, posY - 1))
        _ia->add<ComponentMovable>(ComponentMovable::Direction::DOWN, 0.1);
    if (checkCollisionAt(posX - 1, posY + 1) || checkCollisionAt(posX + 1, posY + 1))
        _ia->add<ComponentMovable>(ComponentMovable::Direction::UP, 0.1);
    _ia->add<ComponentDrawable>(false, true);
    _ia->add<ComponentKillable>();
    _ia->add<ComponentTransform>(50, 50, posX, posY);
    _ia->add<ComponentCollider>();
    _blastRange = 1;
}

SystemIA::~SystemIA()
{
    if (_ia)
        delete _ia;
}

bool SystemIA::checkCollisionAt(int posX, int posY) const
{
    for (auto *e : _core->getEntities()) {
        if (e->has<ComponentTransform>() && e->has<ComponentCollider>() &&
            e->get<ComponentTransform>()->getPosX() == posX && e->get<ComponentTransform>()->getPosY() == posY) {
            return (true);
        }
    }
    return (false);
}

void SystemIA::udpdate()
{
    ecs::IEntity *bomb = nullptr;

    bomb = getBombInRange();
    if (bomb)
        setDirectionWithBomb(bomb);
    if (isKillableBlockInRange())
        // put bomb
    move();
}

void SystemIA::move()
{
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    switch (direction) {
        case ComponentMovable::Direction::DOWN:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX(), _ia->get<ComponentTransform>()->getPosY() + speed))
                _ia->get<ComponentTransform>()->setPosY(_ia->get<ComponentTransform>()->getPosY() + speed);
            break;
        case ComponentMovable::Direction::UP:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX(), _ia->get<ComponentTransform>()->getPosY() - speed))
                _ia->get<ComponentTransform>()->setPosY(_ia->get<ComponentTransform>()->getPosY() - speed);
            break;
        case ComponentMovable::Direction::LEFT:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX() - speed, _ia->get<ComponentTransform>()->getPosY()))
                _ia->get<ComponentTransform>()->setPosX(_ia->get<ComponentTransform>()->getPosX() - speed);
            break;
        case ComponentMovable::Direction::RIGHT:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX() + speed, _ia->get<ComponentTransform>()->getPosY()))
                _ia->get<ComponentTransform>()->setPosX(_ia->get<ComponentTransform>()->getPosX() + speed);
            break;
        default:
            break;
    }
}

ecs::IEntity *SystemIA::getBombInRange()
{
    for (auto *e : _core->getEntities()) {
        if (e->has<ComponentExplodable>() && e->has<ComponentTransform>() && e->has<ComponentDroppable>()) {
            if ((e->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() &&
                abs(e->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY()) <= e->get<ComponentExplodable>()->getBlastRange()) ||
                (e->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() &&
                abs(e->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX()) <= e->get<ComponentExplodable>()->getBlastRange()))
                return (e);
        }
    }
    return (nullptr);
}

void SystemIA::setDirectionWithBomb(ecs::IEntity *bomb)
{
    if (!bomb->has<ComponentTransform>())
        return;
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

    for (auto *b : _core->getEntities()) {
        if (b->has<ComponentKillable>() && b->has<ComponentTransform>() && b->has<ComponentCollider>()) {
            if (b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() && b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() + speed ||
                b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() && b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() - speed ||
                b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() && b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() + speed ||
                b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() && b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() - speed)
                return (true);
        }
    }
    return (false);
}
