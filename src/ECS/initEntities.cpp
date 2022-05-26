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
    ecs::IEntity *e = new ecs::IEntity();
    ecs::IEntity *r = new ecs::IEntity();

    e->add<ComponentMovable>(ComponentMovable::Direction::DOWN, 5, true);
    r->add<ComponentMovable>(ComponentMovable::Direction::UP, 5, false);
    e->add<ComponentTransform>(256, 256, 100, 100);
    index.addEntity(e);
    index.addEntity(r);
    return (index);
}