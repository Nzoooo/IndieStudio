/*
** EPITECH PROJECT, 2022
** SystemCollision
** File description:
** SystemCollision
*/

#include "SystemCollision.hpp"

namespace ecs
{
    bool SystemCollision::checkCollisions(raylib::BoundingBox &box, std::vector<ecs::IEntity *> entities)
    {
        raylib::BoundingBox box2;

        for (auto *e : entities) {
            if (e->has<ComponentMesh>() && e->has<ComponentCollider>()) {
                if (e->get<ComponentMesh>()->getSize().z > 1.0f) {
                    raylib::BoundingBox tmpBox(raylib::Vector3(e->get<ComponentMesh>()->getPos().x - 0.5, e->get<ComponentMesh>()->getPos().y - 0.5,
                                                   e->get<ComponentMesh>()->getPos().z - (e->get<ComponentMesh>()->getSize().z / 2)),
                        raylib::Vector3(e->get<ComponentMesh>()->getPos().x + 0.5, e->get<ComponentMesh>()->getPos().y + 0.5,
                            e->get<ComponentMesh>()->getPos().z + (e->get<ComponentMesh>()->getSize().z / 2)));
                    box2 = tmpBox;
                } else {
                    raylib::BoundingBox tmpBox(raylib::Vector3(e->get<ComponentMesh>()->getPos().x - (e->get<ComponentMesh>()->getSize().x / 2),
                                                   e->get<ComponentMesh>()->getPos().y - 0.5, e->get<ComponentMesh>()->getPos().z - 0.5),
                        raylib::Vector3(e->get<ComponentMesh>()->getPos().x + (e->get<ComponentMesh>()->getSize().x / 2),
                            e->get<ComponentMesh>()->getPos().y + 0.5, e->get<ComponentMesh>()->getPos().z + 0.5));
                    box2 = tmpBox;
                }
            }
            if (e->has<ComponentCube>() && e->has<ComponentCollider>()) {
                raylib::BoundingBox tmpBox(raylib::Vector3(e->get<ComponentCube>()->getPos().x - 0.5, e->get<ComponentCube>()->getPos().y - 0.5,
                                               e->get<ComponentCube>()->getPos().z - 0.5),
                    raylib::Vector3(
                        e->get<ComponentCube>()->getPos().x + 0.5, e->get<ComponentCube>()->getPos().y + 0.5, e->get<ComponentCube>()->getPos().z + 0.5));
                box2 = tmpBox;
            }
            if (box.checkCollision(box2))
                return (true);
        }
        return (false);
    }
} // namespace ecs
