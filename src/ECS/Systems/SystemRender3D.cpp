/*
** EPITECH PROJECT, 2022
** SystemRender3D
** File description:
** SystemRender3D
*/

#include "SystemRender3D.hpp"

namespace ecs
{
    void SystemRender3D::update(ecs::Core &index)
    {
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentDrawable>() && it->get<ComponentDrawable>()->getIsDrawable3D()) {
                // if (it->has<ComponentRaylib>())
                //     it->get<ComponentRaylib>()->Draw();
                if (it->has<ComponentModel>())
                    it->get<ComponentModel>()->Draw();
            }
        }
    }
} // namespace ecs
