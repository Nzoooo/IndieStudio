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

    player->add<ComponentMovable>(ComponentMovable::Direction::DOWN, 5, true);
    player->add<ComponentMovable>(ComponentMovable::Direction::UP, 5, true);
    player->add<ComponentMovable>(ComponentMovable::Direction::LEFT, 5, true);
    player->add<ComponentMovable>(ComponentMovable::Direction::RIGHT, 5, true);
    player->add<ComponentCollider>();
    player->add<ComponentKillable>();
    player->add<ComponentTransform>(50, 50, 50, 50);

    ecs::IEntity *cube = new ecs::IEntity();

    raylib::Vector3 pos = {0.0f, 0.0f, 0.0f};
    raylib::Vector3 size = {1.0f, 1.0f, 1.0f};

    cube->add<ComponentDrawable>(true, false);
    cube->add<ComponentCube>(pos, size, BLACK);

    index.addEntity(player);
    index.addEntity(cube);
    return (index);
}
