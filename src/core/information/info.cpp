/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info
*/

#include "info.hpp"

static ecs::IEntity *createBackground()
{
    ecs::IEntity *entity = new ecs::IEntity();

    raylib::Vector3 position(10.0f, -10.0f, 10.0f);
    raylib::Vector3 size(10.0f, 1.0f, 10.0f);
    entity->add<ComponentDrawable>(true, false);
    entity->add<ComponentTransparency>(200);
    entity->add<ComponentRectangle>(10, 10, 200, 100);
    entity->get<ComponentRectangle>()->setColor(entity->get<ComponentTransparency>()->sumWithColor(raylib::Color::Blue()));
    return (entity);
}

void displayInformations(ecs::Core &core)
{
    core.addEntity(createBackground());
    for (auto &entity : core.getEntities()) {
        // if (entity->has<ComponentControllable>()) {
        //     // It's a player
        // }
        // else if (entity->has<ComponentHealth>()) {
        //     // It's a bot
        // }
    }
}
