/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initEntities
*/

#include "ecs.hpp"

ecs::Core initEntities()
{
    ecs::Core index;

    ecs::IEntity *player = new ecs::IEntity();

    player->add<ComponentMovable>(5);
    player->add<ComponentMovable>(5);
    player->add<ComponentMovable>(5);
    player->add<ComponentMovable>(5);
    player->add<ComponentCollider>();
    player->add<ComponentKillable>();
    player->add<ComponentTransform>(50, 50, 50, 50);

    index.addEntity(player);
    return (index);
}
