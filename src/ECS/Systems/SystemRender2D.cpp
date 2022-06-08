/*
** EPITECH PROJECT, 2022
** SystemRender2D
** File description:
** SystemRender2D
*/

#include "SystemRender2D.hpp"

void SystemRender2D::update(ecs::Core &index)
{
    for (auto *it : index.getEntities()) {
        if (it->has<ComponentDrawable>() &&
        it->get<ComponentDrawable>()->getIsDrawable2D()) {
            if (it->has<ComponentRaylib>())
                it->get<ComponentRaylib>()->Draw();
        }
    }
}
