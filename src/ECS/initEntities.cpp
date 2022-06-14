/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initEntities
*/

#include "ecs.hpp"

ecs::Core initEntities()
{
    ecs::Core core;

    ecs::IEntity *player = new ecs::IEntity();

    player->add<ComponentMovable>(ComponentMovable::Direction::DOWN, 5, true);
    player->add<ComponentMovable>(ComponentMovable::Direction::UP, 5, true);
    player->add<ComponentMovable>(ComponentMovable::Direction::LEFT, 5, true);
    player->add<ComponentMovable>(ComponentMovable::Direction::RIGHT, 5, true);
    player->add<ComponentCollider>();
    player->add<ComponentKillable>();
    player->add<ComponentTransform>(50, 50, 50, 50);

    core.addEntity(player);
    return (core);
}
