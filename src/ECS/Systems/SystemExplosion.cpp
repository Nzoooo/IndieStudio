/*
** EPITECH PROJECT, 10)22
** B-YEP400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemExplosion
*/

#include "SystemExplosion.hpp"
#include <cmath>
#include <iostream>

ecs::SystemExplosion::SystemExplosion()
{
}

ecs::SystemExplosion::~SystemExplosion()
{
}

raylib::BoundingBox ecs::SystemExplosion::_createBoundingBoxExplosion(ecs::IEntity *blast)
{
    raylib::BoundingBox box(raylib::Vector3(blast->get<ComponentFireBlast>()->getPos().x - (blast->get<ComponentFireBlast>()->getSize().x / 2),
                                blast->get<ComponentFireBlast>()->getPos().y - blast->get<ComponentFireBlast>()->getSize().y,
                                blast->get<ComponentFireBlast>()->getPos().z - (blast->get<ComponentFireBlast>()->getSize().z / 2)),
        raylib::Vector3(blast->get<ComponentFireBlast>()->getPos().x + (blast->get<ComponentFireBlast>()->getSize().x / 2),
            blast->get<ComponentFireBlast>()->getPos().y + blast->get<ComponentFireBlast>()->getSize().y,
            blast->get<ComponentFireBlast>()->getPos().z + (blast->get<ComponentFireBlast>()->getSize().z / 2)));
    return (box);
}

void ecs::SystemExplosion::blastGeneration(ecs::Core &core, ecs::IEntity *bomb)
{
    raylib::BoundingBox box;

    raylib::Vector3 pos = bomb->get<ComponentModel>()->getPos();
    ecs::IEntity *blast1 = new ecs::IEntity;
    blast1->add<ComponentDrawable>(false, true);
    std::size_t blastRange = core.getEntity(bomb->get<ComponentExplosion>()->getLabelPlayerOfBomb())->get<ComponentExplodable>()->getBlastRange();
    float range = 0.0f;
    if (blastRange % 2 == 0)
        range = std::ceil(static_cast<float>(blastRange) / 3);
    else
        range = std::floor(static_cast<float>(blastRange) / 3);
    pos.x += range;
    blast1->add<ComponentFireBlast>(ComponentFireBlast::Direction::North, pos, raylib::Vector3(static_cast<float>(blastRange), 0.5, 0.5));
    box = _createBoundingBoxExplosion(blast1);
    while (SystemCollision::checkCollisionsFireBlastBlocks(box, core.getEntities())) {
        box = _createBoundingBoxExplosion(blast1);
        blast1->get<ComponentFireBlast>()->setSize(raylib::Vector3(blast1->get<ComponentFireBlast>()->getSize().x - 0.1f,
            blast1->get<ComponentFireBlast>()->getSize().y, blast1->get<ComponentFireBlast>()->getSize().z));
    }
    core.addEntity(blast1);

    pos = bomb->get<ComponentModel>()->getPos();
    ecs::IEntity *blast2 = new ecs::IEntity;
    blast2->add<ComponentDrawable>(false, true);
    pos.z += range;
    blast2->add<ComponentFireBlast>(ComponentFireBlast::Direction::East, pos, raylib::Vector3(0.5, 0.5, static_cast<float>(blastRange)));
    box = _createBoundingBoxExplosion(blast2);
    while (SystemCollision::checkCollisionsFireBlastBlocks(box, core.getEntities())) {
        box = _createBoundingBoxExplosion(blast2);
        blast2->get<ComponentFireBlast>()->setSize(raylib::Vector3(blast2->get<ComponentFireBlast>()->getSize().x,
            blast2->get<ComponentFireBlast>()->getSize().y, blast2->get<ComponentFireBlast>()->getSize().z - 0.1f));
    }
    core.addEntity(blast2);

    pos = bomb->get<ComponentModel>()->getPos();
    ecs::IEntity *blast3 = new ecs::IEntity;
    blast3->add<ComponentDrawable>(false, true);
    pos.x -= range;
    blast3->add<ComponentFireBlast>(ComponentFireBlast::Direction::South, pos, raylib::Vector3(static_cast<float>(blastRange), 0.5, 0.5));
    box = _createBoundingBoxExplosion(blast3);
    while (SystemCollision::checkCollisionsFireBlastBlocks(box, core.getEntities())) {
        box = _createBoundingBoxExplosion(blast3);
        blast3->get<ComponentFireBlast>()->setSize(raylib::Vector3(blast3->get<ComponentFireBlast>()->getSize().x - 0.1f,
            blast3->get<ComponentFireBlast>()->getSize().y, blast3->get<ComponentFireBlast>()->getSize().z));
    }
    core.addEntity(blast3);

    pos = bomb->get<ComponentModel>()->getPos();
    ecs::IEntity *blast4 = new ecs::IEntity;
    blast4->add<ComponentDrawable>(false, true);
    pos.z -= range;
    blast4->add<ComponentFireBlast>(ComponentFireBlast::Direction::West, pos, raylib::Vector3(0.5, 0.5, static_cast<float>(blastRange)));
    box = _createBoundingBoxExplosion(blast4);
    while (SystemCollision::checkCollisionsFireBlastBlocks(box, core.getEntities())) {
        box = _createBoundingBoxExplosion(blast4);
        blast4->get<ComponentFireBlast>()->setSize(raylib::Vector3(blast4->get<ComponentFireBlast>()->getSize().x,
            blast4->get<ComponentFireBlast>()->getSize().y, blast4->get<ComponentFireBlast>()->getSize().z - 0.1f));
    }
    core.addEntity(blast4);
    if (core.getEntity("SoundBomb") != nullptr)
        core.getEntity("SoundBomb")->get<ComponentSound>()->getSound().PlayMulti();
    core.getEntity(bomb->get<ComponentExplosion>()->getLabelPlayerOfBomb())
        ->get<ComponentBombs>()
        ->setNbCurrBombs(core.getEntity(bomb->get<ComponentExplosion>()->getLabelPlayerOfBomb())->get<ComponentBombs>()->getNbCurrBombs() - 1);
}

void ecs::SystemExplosion::update(ecs::Core &core)
{
    int i = 0;
    for (auto *e : core.getEntities()) {
        i++;
        if (e->has<ComponentExplosion>() && e->get<ComponentExplosion>()->getTimeLeft() > 0) {
            e->get<ComponentExplosion>()->setTimeLeft(e->get<ComponentExplosion>()->getTimeLeft() - 1.0);
            if (e->get<ComponentExplosion>()->getTimeLeft() == 0) {
                e->get<ComponentDrawable>()->setIsDrawable3D(false);
                blastGeneration(core, e);
            }
        }
        if (e->has<ComponentFireBlast>() && e->get<ComponentFireBlast>()->getTimer() >= 0) {
            e->get<ComponentFireBlast>()->timer(1.0);
            if (e->has<ComponentFireBlast>() && e->get<ComponentFireBlast>()->getTimer() == 0) {
                e->get<ComponentDrawable>()->setIsDrawable3D(false);
            }
        }
    }
}
