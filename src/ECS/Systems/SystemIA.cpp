/*
** EPITECH PROJECT, 2022
** SystemIA.cpp
** File description:
** SystemIA.cpp
*/

#include "SystemIA.hpp"
#include <algorithm>
#include <cmath>
#include "SystemCollision.hpp"
#include "raylib/include/BoundingBox.hpp"

void SystemIA::update(ecs::Core &_core)
{
    ecs::IEntity *bomb = nullptr;

    for (auto *e : _core.getEntities()) {
        if (e->has<ComponentKills>() && !e->has<ComponentControllable>()) {
            bomb = getBombInRange(e, _core);
            // if (isKillableBlockInRange(e, _core) && !bomb)
            //     /* place bomb */;
            move(e, _core, bomb);
        }
    }
}

void SystemIA::move(ecs::IEntity *_ia, ecs::Core &_core, ecs::IEntity *bomb)
{
    std::vector<ComponentMovable::Direction> possibleDirection = {
        ComponentMovable::Direction::DOWN, ComponentMovable::Direction::UP, ComponentMovable::Direction::LEFT, ComponentMovable::Direction::RIGHT};
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    if (!bomb) {
        move(_ia, _core);
        return;
    }
    /* possible direction */
    if (bomb && std::find(possibleDirection.begin(), possibleDirection.end(), getDirectionOfTheBomb(_ia, bomb)) != possibleDirection.end()) {
        auto it = std::find(possibleDirection.begin(), possibleDirection.end(), getDirectionOfTheBomb(_ia, bomb));
        possibleDirection.erase(it);
    }
    raylib::Vector3 minBoxUp(
        _ia->get<ComponentModel>()->getPos().x - 0.3f + speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 maxBoxUp(
        _ia->get<ComponentModel>()->getPos().x + 0.3f + speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox boxUp(minBoxUp, maxBoxUp);
    raylib::Vector3 minBoxDown(
        _ia->get<ComponentModel>()->getPos().x - 0.3f - speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 maxBoxDown(
        _ia->get<ComponentModel>()->getPos().x + 0.3f - speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox boxDown(minBoxDown, maxBoxDown);
    raylib::Vector3 minBoxLeft(
        _ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f - speed);
    raylib::Vector3 maxBoxLeft(
        _ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f - speed);
    raylib::BoundingBox boxLeft(minBoxLeft, maxBoxLeft);
    raylib::Vector3 minBoxRight(
        _ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f + speed);
    raylib::Vector3 maxBoxRight(
        _ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f + speed);
    raylib::BoundingBox boxRight(minBoxRight, maxBoxRight);
    if (ecs::SystemCollision::checkCollisions(boxUp, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollisions(boxDown, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollisions(boxLeft, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollisions(boxRight, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::RIGHT) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::RIGHT);
            possibleDirection.erase(it);
        }
    }
    _ia->get<ComponentMovable>()->setDirection(possibleDirection.at((std::rand() % possibleDirection.size() + 1) - 1));
    _ia->get<ComponentModel>()->setRotateAngle(_ia->get<ComponentMovable>()->getDirection());
    _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x + getMovement(_ia).at("x"),
        _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + getMovement(_ia).at("z")));
    raylib::Vector3 min(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 max(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox box(min, max);
    if (ecs::SystemCollision::checkCollisions(box, _ia, _core.getEntities())) {
        _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x - getMovement(_ia).at("x"),
            _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - getMovement(_ia).at("z")));
    }
}

void SystemIA::move(ecs::IEntity *_ia, ecs::Core &_core)
{
    std::vector<ComponentMovable::Direction> possibleDirection = {
        ComponentMovable::Direction::DOWN, ComponentMovable::Direction::UP, ComponentMovable::Direction::LEFT, ComponentMovable::Direction::RIGHT};
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    /* possible direction */
    raylib::Vector3 minBoxUp(
        _ia->get<ComponentModel>()->getPos().x - 0.3f + speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 maxBoxUp(
        _ia->get<ComponentModel>()->getPos().x + 0.3f + speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox boxUp(minBoxUp, maxBoxUp);
    raylib::Vector3 minBoxDown(
        _ia->get<ComponentModel>()->getPos().x - 0.3f - speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 maxBoxDown(
        _ia->get<ComponentModel>()->getPos().x + 0.3f - speed, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox boxDown(minBoxDown, maxBoxDown);
    raylib::Vector3 minBoxLeft(
        _ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f - speed);
    raylib::Vector3 maxBoxLeft(
        _ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f - speed);
    raylib::BoundingBox boxLeft(minBoxLeft, maxBoxLeft);
    raylib::Vector3 minBoxRight(
        _ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f + speed);
    raylib::Vector3 maxBoxRight(
        _ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f + speed);
    raylib::BoundingBox boxRight(minBoxRight, maxBoxRight);
    if (ecs::SystemCollision::checkCollisions(boxUp, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::UP);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollisions(boxDown, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::DOWN);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollisions(boxLeft, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::LEFT);
            possibleDirection.erase(it);
        }
    }
    if (ecs::SystemCollision::checkCollisions(boxRight, _ia, _core.getEntities())) {
        if (std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::RIGHT) != possibleDirection.end()) {
            auto it = std::find(possibleDirection.begin(), possibleDirection.end(), ComponentMovable::Direction::RIGHT);
            possibleDirection.erase(it);
        }
    }
    _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x + getMovement(_ia).at("x"),
        _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + getMovement(_ia).at("z")));
    raylib::Vector3 min(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 max(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox box(min, max);
    if (ecs::SystemCollision::checkCollisions(box, _ia, _core.getEntities())) {
        _ia->get<ComponentModel>()->setPos(raylib::Vector3(_ia->get<ComponentModel>()->getPos().x - getMovement(_ia).at("x"),
            _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - getMovement(_ia).at("z")));
        _ia->get<ComponentMovable>()->setDirection(possibleDirection.at((std::rand() % possibleDirection.size() + 1) - 1));
        _ia->get<ComponentModel>()->setRotateAngle(_ia->get<ComponentMovable>()->getDirection());
    }
}

ecs::IEntity *SystemIA::getBombInRange(ecs::IEntity *_ia, ecs::Core &_core)
{
    for (auto *e : _core.getEntities()) {
        if (e->has<ComponentExplodable>() && e->has<ComponentModel>() && e->has<ComponentDroppable>()) {
            raylib::Vector3 bbIaHorizontalmin(_ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y,
                _ia->get<ComponentModel>()->getPos().z - e->get<ComponentExplodable>()->getBlastRange() - 0.3f);
            raylib::Vector3 bbIaHorizontalmax(_ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y,
                _ia->get<ComponentModel>()->getPos().z + e->get<ComponentExplodable>()->getBlastRange() + 0.3f);
            raylib::BoundingBox bbIaHorizontal(bbIaHorizontalmin, bbIaHorizontalmax);
            raylib::Vector3 bbIaVerticalmin(_ia->get<ComponentModel>()->getPos().x - e->get<ComponentExplodable>()->getBlastRange() - 0.3f,
                _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
            raylib::Vector3 bbIaVerticalmax(_ia->get<ComponentModel>()->getPos().x + e->get<ComponentExplodable>()->getBlastRange() + 0.3f,
                _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
            raylib::BoundingBox bbIaVertical(bbIaVerticalmin, bbIaVerticalmax);
            raylib::Vector3 bbBombmin(
                e->get<ComponentModel>()->getPos().x - 0.5f, e->get<ComponentModel>()->getPos().y, e->get<ComponentModel>()->getPos().z - 0.5f);
            raylib::Vector3 bbBombmax(
                e->get<ComponentModel>()->getPos().x + 0.5f, e->get<ComponentModel>()->getPos().y, e->get<ComponentModel>()->getPos().z + 0.5f);
            raylib::BoundingBox bbBomb(bbBombmin, bbBombmax);
            if (ecs::SystemCollision::checkCollisions(bbIaHorizontal, bbBomb) || ecs::SystemCollision::checkCollisions(bbIaVertical, bbBomb))
                return (e);
        }
    }
    return (nullptr);
}

ComponentMovable::Direction SystemIA::getDirectionOfTheBomb(ecs::IEntity *_ia, ecs::IEntity *bomb)
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

bool SystemIA::isKillableBlockInRange(ecs::IEntity *_ia, ecs::Core &_core)
{
    raylib::Vector3 bbIaHorizontalmin(
        _ia->get<ComponentModel>()->getPos().x - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 1 - 0.3f);
    raylib::Vector3 bbIaHorizontalmax(
        _ia->get<ComponentModel>()->getPos().x + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 1 + 0.3f);
    raylib::BoundingBox bbIaHorizontal(bbIaHorizontalmin, bbIaHorizontalmax);
    raylib::Vector3 bbIaVerticalmin(
        _ia->get<ComponentModel>()->getPos().x - 1 - 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z - 0.3f);
    raylib::Vector3 bbIaVerticalmax(
        _ia->get<ComponentModel>()->getPos().x + 1 + 0.3f, _ia->get<ComponentModel>()->getPos().y, _ia->get<ComponentModel>()->getPos().z + 0.3f);
    raylib::BoundingBox bbIaVertical(bbIaVerticalmin, bbIaVerticalmax);
    for (auto *e : _core.getEntities()) {
        if (e->has<ComponentKillable>() && e->has<ComponentCollider>() && e->has<ComponentCube>() && e->has<ComponentDrawable>()
            && e->get<ComponentDrawable>()->getIsDrawable3D() && e->has<ComponentModel>()) {
            raylib::Vector3 bbBlockmin(
                e->get<ComponentModel>()->getPos().x - 0.5f, e->get<ComponentModel>()->getPos().y, e->get<ComponentModel>()->getPos().z - 0.5f);
            raylib::Vector3 bbBlockmax(
                e->get<ComponentModel>()->getPos().x + 0.5f, e->get<ComponentModel>()->getPos().y, e->get<ComponentModel>()->getPos().z + 0.5f);
            raylib::BoundingBox bbBlock(bbBlockmin, bbBlockmax);
            if (ecs::SystemCollision::checkCollisions(bbIaHorizontal, bbBlock) || ecs::SystemCollision::checkCollisions(bbIaVertical, bbBlock))
                return (true);
        }
    }
    return (false);
}

std::map<std::string, float> SystemIA::getMovement(ecs::IEntity *_ia)
{
    std::map<std::string, float> movement = {{"x", 0}, {"z", 0}};
    ComponentMovable::Direction direction = _ia->get<ComponentMovable>()->getDirection();
    float speed = _ia->get<ComponentMovable>()->getSpeed();

    if (direction == ComponentMovable::Direction::UP) {
        movement.at("x") += speed;
    }
    if (direction == ComponentMovable::Direction::DOWN) {
        movement.at("x") -= speed;
    }
    if (direction == ComponentMovable::Direction::LEFT) {
        movement.at("z") -= speed;
    }
    if (direction == ComponentMovable::Direction::RIGHT) {
        movement.at("z") += speed;
    }
    return (movement);
}
