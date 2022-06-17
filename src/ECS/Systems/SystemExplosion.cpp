/*
** EPITECH PROJECT, 10)22
** B-YEP400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemExplosion
*/

#include "SystemExplosion.hpp"
#include <iostream>

ecs::SystemExplosion::SystemExplosion()
{
}

ecs::SystemExplosion::~SystemExplosion()
{
}

void ecs::SystemExplosion::blastGeneration(ecs::Core &core, ecs::IEntity *bomb)
{
    (void)core;
    ecs::IEntity *blast1 = new ecs::IEntity;
    raylib::Vector3 pos = bomb->get<ComponentModel>()->getPos();
    float blastRange = bomb->get<ComponentExplodable>()->getBlastRange() / 2.0;

    blast1->add<ComponentDrawable>(false, true);
    pos.z -= blastRange + 0.3;
    blast1->add<ComponentFireBlast>(
        ComponentFireBlast::Direction::North, pos, raylib::Vector3(0.5, 0.5, static_cast<float>(bomb->get<ComponentExplodable>()->getBlastRange())));
    core.addEntity(blast1);

    ecs::IEntity *blast2 = new ecs::IEntity;

    blast2->add<ComponentDrawable>(false, true);
    pos.z += blastRange + 0.3;
    pos.x -= blastRange + 0.3;
    blast2->add<ComponentFireBlast>(
        ComponentFireBlast::Direction::East, pos, raylib::Vector3(static_cast<float>(bomb->get<ComponentExplodable>()->getBlastRange()), 0.5, 0.5));
    core.addEntity(blast2);

    ecs::IEntity *blast3 = new ecs::IEntity;

    blast3->add<ComponentDrawable>(false, true);
    pos.x += blastRange + 0.3;
    pos.z += blastRange + 0.3;
    blast3->add<ComponentFireBlast>(
        ComponentFireBlast::Direction::South, pos, raylib::Vector3(0.5, 0.5, static_cast<float>(bomb->get<ComponentExplodable>()->getBlastRange())));
    core.addEntity(blast3);

    ecs::IEntity *blast4 = new ecs::IEntity;

    blast4->add<ComponentDrawable>(false, true);
    pos.z -= blastRange + 0.3;
    pos.x += blastRange + 0.3;
    blast4->add<ComponentFireBlast>(
        ComponentFireBlast::Direction::West, pos, raylib::Vector3(static_cast<float>(bomb->get<ComponentExplodable>()->getBlastRange()), 0.5, 0.5));
    core.addEntity(blast4);
}

void ecs::SystemExplosion::update(ecs::Core &core)
{
    int i = 0;
    for (auto *e : core.getEntities()) {
        i++;
        if (e->has<ComponentExplodable>() && e->get<ComponentExplodable>()->getTimeLeft() > 0) {
            e->get<ComponentExplodable>()->setTimeLeft(e->get<ComponentExplodable>()->getTimeLeft() - 1.0);
            std::cout << "Bombe " << i << " explose dans " << e->get<ComponentExplodable>()->getTimeLeft() << "s" << std::endl;
            if (e->get<ComponentExplodable>()->getTimeLeft() == 0) {
                std::cout << "Bombe nb " << i << " vient d'exploser" << std::endl;
                e->remove<ComponentDrawable>();
                blastGeneration(core, e);
            }
        }
    }
}
