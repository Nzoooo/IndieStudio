/*
** EPITECH PROJECT, 2022
** SystemRender2D
** File description:
** SystemRender2D
*/

#include "SystemRender2D.hpp"

void SystemRender2D::update(ecs::Core &index)
{
    for (auto *e : index.getEntities()) {
        if (e->has<ComponentDrawable>() &&
            e->get<ComponentDrawable>()->getIsDrawable2D()) {
            if (e->has<ComponentRectangle>())
                e->get<ComponentRectangle>()->Draw();
        }
    }
}
