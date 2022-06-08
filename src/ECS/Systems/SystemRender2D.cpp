/*
** EPITECH PROJECT, 2022
** SystemRender2D
** File description:
** SystemRender2D
*/

#include "SystemRender2D.hpp"
#include "IComponentDraw.hpp"

void SystemRender2D::update(ecs::Core &index)
{
    for (auto *e : index.getEntities()) {
        if (e->has<ComponentDrawable>() &&
            e->get<ComponentDrawable>()->getIsDrawable2D()) {
            for (auto *c : e->getAllComponents()) {
                if (dynamic_cast<ecs::IComponentDraw *>(c) != nullptr) {

                }
            }
        }
    }
}
