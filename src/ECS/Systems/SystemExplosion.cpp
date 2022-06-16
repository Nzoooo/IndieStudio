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

    blast1->add<ComponentDrawable>(false, true);
    pos.z -= 0.2;
    blast1->add<ComponentModel>("models3D/laserBeam.obj", pos, raylib::Vector3(1.0f, 1.0f, bomb->get<ComponentExplodable>()->getBlastRange() / 20.0f), 0.0);
    core.addEntity(blast1);

    ecs::IEntity *blast2 = new ecs::IEntity;

    blast2->add<ComponentDrawable>(false, true);
    pos.z += 0.2;
    pos.x -= 0.2;
    blast2->add<ComponentModel>("models3D/laserBeam.obj", pos, raylib::Vector3(1.0f, 1.0f, bomb->get<ComponentExplodable>()->getBlastRange() / 20.0f), 90.0);
    core.addEntity(blast2);

    ecs::IEntity *blast3 = new ecs::IEntity;

    blast3->add<ComponentDrawable>(false, true);
    pos.x += 0.2;
    pos.z += 0.2;
    blast3->add<ComponentModel>("models3D/laserBeam.obj", pos, raylib::Vector3(1.0f, 1.0f, bomb->get<ComponentExplodable>()->getBlastRange() / 20.0f), 180.0);
    core.addEntity(blast3);

    ecs::IEntity *blast4 = new ecs::IEntity;

    blast4->add<ComponentDrawable>(false, true);
    pos.z -= 0.2;
    pos.x += 0.2;
    blast4->add<ComponentModel>("models3D/laserBeam.obj", pos, raylib::Vector3(1.0f, 1.0f, bomb->get<ComponentExplodable>()->getBlastRange() / 20.0f), 270.0);
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
