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
            if (it->has<ComponentDrawable>() && it->get<ComponentDrawable>()->getIsDrawable3D() == true) {
                if (it->has<ComponentCube>()) {
                    it->get<ComponentCube>()->Draw();
                }
                if (it->has<ComponentMesh>()) {
                    it->get<ComponentMesh>()->Draw();
                }
            }
        }
    }
} // namespace ecs
