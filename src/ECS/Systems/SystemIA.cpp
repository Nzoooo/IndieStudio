/*
** EPITECH PROJECT, 2022
** SystemIA.cpp
** File description:
** SystemIA.cpp
*/

#include "SystemIA.hpp"
#include <algorithm>
#include <experimental/random>

SystemIA::SystemIA(ecs::Core &core, std::string modelPath, raylib::Vector3 pos) : _ia(new ecs::IEntity), _core(core)
{
    _ia->add<ComponentMovable>(ComponentMovable::Direction::UP, 0.1);
    _ia->add<ComponentDrawable>(false, true);
    _ia->add<ComponentKillable>();
    _ia->add<ComponentModel>(modelPath, pos, raylib::Vector3(0.7f, 0.7f, 0.7f));
    _ia->add<ComponentCollider>();
    _ia->add<ComponentKills>();
    _ia->add<ComponentExplodable>();
    _ia->add<ComponentBombs>(2);
    _blastRange = 1;
    _timeInBombRange = std::chrono::system_clock::now();
}

SystemIA::~SystemIA()
{
    if (_ia)
        delete _ia;
}

bool SystemIA::checkCollisionAt(int posX, int posY) const
{
    for (auto *e : _core.getEntities()) {
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
    if (bomb) {
        if ((std::chrono::system_clock::now() - _timeInBombRange) >= std::chrono::seconds(3))
            _timeInBombRange = std::chrono::system_clock::now();
    } else {
        if (isKillableBlockInRange())
            // put bomb
            ;
    }
    move(bomb);
}

void SystemIA::move(ecs::IEntity *bomb)
{
    std::vector<ComponentMovable::Direction> possibleDirection;
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    if (!bomb) {
        if ((std::chrono::system_clock::now() - _timeInBombRange) >= std::chrono::seconds(3))
            move();
        return;
    }
    possibleDirection = getPossibleDirection(bomb);
    _ia->get<ComponentMovable>()->setDirection(possibleDirection.at(std::experimental::randint(std::size_t(1), possibleDirection.size()) - 1));
}

void SystemIA::move()
{
    std::vector<ComponentMovable::Direction> possibleDirection;
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    possibleDirection = getPossibleDirection();
    switch (direction) {
        case ComponentMovable::Direction::DOWN:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX(), _ia->get<ComponentTransform>()->getPosY() + speed))
                _ia->get<ComponentTransform>()->setPosY(_ia->get<ComponentTransform>()->getPosY() + speed);
            else
                _ia->get<ComponentMovable>()->setDirection(possibleDirection.at(std::experimental::randint(std::size_t(1), possibleDirection.size()) - 1));
            break;
        case ComponentMovable::Direction::UP:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX(), _ia->get<ComponentTransform>()->getPosY() - speed))
                _ia->get<ComponentTransform>()->setPosY(_ia->get<ComponentTransform>()->getPosY() - speed);
            else
                _ia->get<ComponentMovable>()->setDirection(possibleDirection.at(std::experimental::randint(std::size_t(1), possibleDirection.size()) - 1));
            break;
        case ComponentMovable::Direction::LEFT:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX() - speed, _ia->get<ComponentTransform>()->getPosY()))
                _ia->get<ComponentTransform>()->setPosX(_ia->get<ComponentTransform>()->getPosX() - speed);
            else
                _ia->get<ComponentMovable>()->setDirection(possibleDirection.at(std::experimental::randint(std::size_t(1), possibleDirection.size()) - 1));
            break;
        case ComponentMovable::Direction::RIGHT:
            if (!checkCollisionAt(_ia->get<ComponentTransform>()->getPosX() + speed, _ia->get<ComponentTransform>()->getPosY()))
                _ia->get<ComponentTransform>()->setPosX(_ia->get<ComponentTransform>()->getPosX() + speed);
            else
                _ia->get<ComponentMovable>()->setDirection(possibleDirection.at(std::experimental::randint(std::size_t(1), possibleDirection.size()) - 1));
            break;
        default:
            break;
    }
}

std::vector<ComponentMovable::Direction> SystemIA::getPossibleDirection(ecs::IEntity *bomb)
{
    std::vector<ComponentMovable::Direction> possibleDirection = { ComponentMovable::Direction::DOWN, ComponentMovable::Direction::UP,
                                                                    ComponentMovable::Direction::LEFT, ComponentMovable::Direction::RIGHT };
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    if (bomb && std::find(possibleDirection.begin(), possibleDirection.end(), getDirectionOfTheBomb(bomb)) != possibleDirection.end()) {
        auto it = std::find(possibleDirection.begin(), possibleDirection.end(), getDirectionOfTheBomb(bomb));
        possibleDirection.erase(it);
    }
    switch (direction) {
        case ComponentMovable::Direction::DOWN:
            if (checkCollisionAt(_ia->get<ComponentTransform>()->getPosX(), _ia->get<ComponentTransform>()->getPosY() + speed)) {
                if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN) != possibleDirection.end()) {
                    auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN);
                    possibleDirection.erase(it);
                }
            }
            break;
        case ComponentMovable::Direction::UP:
            if (checkCollisionAt(_ia->get<ComponentTransform>()->getPosX(), _ia->get<ComponentTransform>()->getPosY() - speed)) {
                if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP) != possibleDirection.end()) {
                    auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP);
                    possibleDirection.erase(it);
                }
            }
            break;
        case ComponentMovable::Direction::LEFT:
            if (checkCollisionAt(_ia->get<ComponentTransform>()->getPosX() - speed, _ia->get<ComponentTransform>()->getPosY())) {
                if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT) != possibleDirection.end()) {
                    auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT);
                    possibleDirection.erase(it);
                }
            }
            break;
        case ComponentMovable::Direction::RIGHT:
            if (checkCollisionAt(_ia->get<ComponentTransform>()->getPosX() + speed, _ia->get<ComponentTransform>()->getPosY())) {
                if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT) != possibleDirection.end()) {
                    auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT);
                    possibleDirection.erase(it);
                }
            }
            break;
        default:
            break;
    }
}

ecs::IEntity *SystemIA::getBombInRange()
{
    for (auto *e : _core.getEntities()) {
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

ComponentMovable::Direction SystemIA::getDirectionOfTheBomb(ecs::IEntity *bomb)
{
    if (!bomb->has<ComponentTransform>())
        return (_ia->get<ComponentMovable>()->getDirection());
    if (bomb->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX()) {
        if (bomb->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY() >= 0) {
            return (ComponentMovable::Direction::UP);
        }
        if (bomb->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY() < 0) {
            return (ComponentMovable::Direction::DOWN);
        }
    } else {
        if (bomb->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX() >= 0) {
            return (ComponentMovable::Direction::LEFT);
        }
        if (bomb->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX() < 0) {
            return (ComponentMovable::Direction::RIGHT);
        }
    }
    return (_ia->get<ComponentMovable>()->getDirection());
}

bool SystemIA::isKillableBlockInRange() const
{
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    for (auto *b : _core.getEntities()) {
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
