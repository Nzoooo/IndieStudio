/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initEntities
*/

#include "../ECS/ecs.hpp"

ecs::Core initEntities()
{
    ecs::Core index;
    ecs::IEntity *e = new ecs::IEntity();
    ecs::IEntity *r = new ecs::IEntity();
    
    e->add<componentMovable>();
    r->add<componentMovable>(false);
    index.addEntity(e);
    index.addEntity(r);
    return (index);
}