/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
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

void ecs::SystemExplosion::blastGeneration(ecs::Core &core)
{
    (void)core;
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
                blastGeneration(core);
            }
        }
    }
}
