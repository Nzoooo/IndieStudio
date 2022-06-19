/*
** EPITECH PROJECT, 2022
** SystemIA.cpp
** File description:
** SystemIA.cpp
*/

#include "SystemIA.hpp"
#include "raylib/include/BoundingBox.hpp"
#include <algorithm>
#include <experimental/random>
#include <cmath>

SystemIA::SystemIA(ecs::Core &core, std::string modelPath, raylib::Vector3 pos, ComponentMovable::Direction dir) : _ia(new ecs::IEntity), _core(core)
{
    _ia->add<ComponentMovable>(dir, 0.03f);
    _ia->add<ComponentDrawable>(false, true);
    _ia->add<ComponentKillable>();
    _ia->add<ComponentModel>(modelPath, pos, raylib::Vector3(0.3f, 0.3f, 0.3f));
    _ia->get<ComponentModel>()->setRotateAngle(dir);
    _ia->add<ComponentCollider>();
    _ia->add<ComponentKills>();
    _ia->add<ComponentExplodable>();
    _ia->add<ComponentBombs>(2);
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
        if (e->has<ComponentModel>() && e->has<ComponentCollider>() &&
            e->get<ComponentTransform>()->getPosX() == posX && e->get<ComponentTransform>()->getPosY() == posY) {
            return (true);
        }
    }
    return (false);
}

void SystemIA::udpdate()
{
    ecs::IEntity *bomb = nullptr;

    // bomb = getBombInRange();
    // if (bomb) {
    //     if ((std::chrono::system_clock::now() - _timeInBombRange) >= std::chrono::seconds(3))
    //         _timeInBombRange = std::chrono::system_clock::now();
    // } else {
    //     if (isKillableBlockInRange())
    //         // put bomb
    //         ;
    // }
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
    _ia->get<ComponentModel>()->setRotateAngle(_ia->get<ComponentMovable>()->getDirection());
    _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x + getMovement().at("x"),
                                        _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + getMovement().at("z")));
    raylib::Vector3 min(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 max(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox box(min, max);
    if (ecs::SystemCollision::checkCollision(box, _core.getEntities())) {
        _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x - getMovement().at("x"),
                                            _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - getMovement().at("z")));
    }
}

void SystemIA::move()
{
    std::vector<ComponentMovable::Direction> possibleDirection;
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    possibleDirection = getPossibleDirection();
    _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x + getMovement().at("x"),
                                        _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + getMovement().at("z")));
    raylib::Vector3 min(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 max(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox box(min, max);
    if (ecs::SystemCollision::checkCollision(box, _core.getEntities())) {
        _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x - getMovement().at("x"),
                                            _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - getMovement().at("z")));
        _ia->get<ComponentMovable>()->setDirection(possibleDirection.at(std::experimental::randint(std::size_t(1), possibleDirection.size()) - 1));
        _ia->get<ComponentModel>()->setRotateAngle(_ia->get<ComponentMovable>()->getDirection());
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
    raylib::Vector3 minBoxUp(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f + speed);
    raylib::Vector3 maxBoxUp(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f + speed);
    raylib::BoundingBox boxUp(minBoxUp, maxBoxUp);
    raylib::Vector3 minBoxDown(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f - speed);
    raylib::Vector3 maxBoxDown(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f - speed);
    raylib::BoundingBox boxDown(minBoxDown, maxBoxDown);
    raylib::Vector3 minBoxLeft(_ia->get<ComponentModel>()->getPos().x - 0.3f + speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 maxBoxLeft(_ia->get<ComponentModel>()->getPos().x + 0.3f + speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox boxLeft(minBoxLeft, maxBoxLeft);
    raylib::Vector3 minBoxRight(_ia->get<ComponentModel>()->getPos().x - 0.3f - speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f - speed);
    raylib::Vector3 maxBoxRight(_ia->get<ComponentModel>()->getPos().x + 0.3f - speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f - speed);
    raylib::BoundingBox boxRight(minBoxRight, maxBoxRight);
    if (ecs::SystemCollision::checkCollision(boxUp, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollision(boxDown, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollision(boxLeft, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollision(boxRight, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::RIGHT) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::RIGHT);
            possibleDirection.erase(it);
        }
    }
}

ecs::IEntity *SystemIA::getBombInRange()
{
    for (auto *e : _core.getEntities()) {
        if (e->has<ComponentExplodable>() && e->has<ComponentModel>() && e->has<ComponentDroppable>()) {
            if ((std::ceil(e->get<ComponentTransform>()->getPosX()) == std::ceil(_ia->get<ComponentTransform>()->getPosX()) &&
                abs(e->get<ComponentTransform>()->getPosY() - _ia->get<ComponentTransform>()->getPosY()) <= e->get<ComponentExplodable>()->getBlastRange()) ||
                (std::ceil(e->get<ComponentTransform>()->getPosY()) == std::ceil(_ia->get<ComponentTransform>()->getPosY()) &&
                abs(e->get<ComponentTransform>()->getPosX() - _ia->get<ComponentTransform>()->getPosX()) <= e->get<ComponentExplodable>()->getBlastRange()))
                return (e);
        }
    }
    return (nullptr);
}

ComponentMovable::Direction SystemIA::getDirectionOfTheBomb(ecs::IEntity *bomb)
{
    if (!bomb->has<ComponentModel>())
        return (_ia->get<ComponentMovable>()->getDirection());
    if (std::ceil(bomb->get<ComponentModel>()->getPos().x) == std::ceil(_ia->get<ComponentModel>()->getPos().x)) {
        if (bomb->get<ComponentModel>()->getPos().z - _ia->get<ComponentModel>()->getPos().z >= 0) {
            return (ComponentMovable::Direction::DOWN);
        }
        if (bomb->get<ComponentModel>()->getPos().x - _ia->get<ComponentModel>()->getPos().z < 0) {
            return (ComponentMovable::Direction::UP);
        }
    } else {
        if (bomb->get<ComponentModel>()->getPos().x - _ia->get<ComponentModel>()->getPos().x >= 0) {
            return (ComponentMovable::Direction::RIGHT);
        }
        if (bomb->get<ComponentModel>()->getPos().x - _ia->get<ComponentModel>()->getPos().x < 0) {
            return (ComponentMovable::Direction::LEFT);
        }
    }
    return (_ia->get<ComponentMovable>()->getDirection());
}

bool SystemIA::isKillableBlockInRange() const
{
    // float speed = _ia->get<ComponentMovable>()->getSpeed();

    // for (auto *b : _core.getEntities()) {
    //     if (b->has<ComponentKillable>() && b->has<ComponentTransform>() && b->has<ComponentCollider>()) {
    //         if (b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() && b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() + speed ||
    //             b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() && b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() - speed ||
    //             b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() && b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() + speed ||
    //             b->get<ComponentTransform>()->getPosY() == _ia->get<ComponentTransform>()->getPosY() && b->get<ComponentTransform>()->getPosX() == _ia->get<ComponentTransform>()->getPosX() - speed)
    //             return (true);
    //     }
    // }
    return (false);
}

std::map<std::string, float> SystemIA::getMovement()
{
    std::map<std::string, float> movement = {{"x", 0}, {"z", 0}};
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    if (direction == ComponentMovable::Direction::UP) {
        movement.at("z") += speed;
    }
    if (direction == ComponentMovable::Direction::DOWN) {
        movement.at("z") -= speed;
    }
    if (direction == ComponentMovable::Direction::LEFT) {
        movement.at("x") += speed;
    }
    if (direction == ComponentMovable::Direction::RIGHT) {
        movement.at("x") -= speed;
    }
    return(movement);
}
