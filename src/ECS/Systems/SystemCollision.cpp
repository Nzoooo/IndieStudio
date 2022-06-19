/*
** EPITECH PROJECT, 2022
** SystemCollision
** File description:
** SystemCollision
*/

#include "SystemCollision.hpp"

namespace ecs
{
    bool SystemCollision::checkCollisions(raylib::BoundingBox &box, ecs::IEntity *it, std::vector<ecs::IEntity *> entities)
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
            if (box.checkCollision(box2)) {
                if (it->has<ComponentCollider>() && !it->get<ComponentCollider>()->getIsAbleToCollide() && e->has<ComponentCube>()
                    && e->has<ComponentCollider>() && e->has<ComponentKillable>())
                    return (false);
                return (true);
            }
        }
        return (false);
    }

    void SystemCollision::checkCollisionsBoosts(raylib::BoundingBox &box, ecs::IEntity *it, std::vector<ecs::IEntity *> entities)
    {
        raylib::BoundingBox box2;

        for (auto *e : entities) {
            if (e->has<ComponentCube>() && e->has<ComponentPickable>()) {
                raylib::BoundingBox tmpBox(raylib::Vector3(e->get<ComponentCube>()->getPos().x - 0.2, e->get<ComponentCube>()->getPos().y - 0.2,
                                               e->get<ComponentCube>()->getPos().z - 0.2),
                    raylib::Vector3(
                        e->get<ComponentCube>()->getPos().x + 0.2, e->get<ComponentCube>()->getPos().y + 0.2, e->get<ComponentCube>()->getPos().z + 0.2));
                box2 = tmpBox;
            }
            if (box.checkCollision(box2)) {
                if (e->has<ComponentPickable>() && e->has<ComponentDrawable>() && e->get<ComponentDrawable>()->getIsDrawable3D()) {
                    e->get<ComponentDrawable>()->setIsDrawable3D(false);
                    if (e->get<ComponentCube>()->getTexturePath() == "assets/16/boost_block_pass.png") {
                        it->get<ComponentCollider>()->setIsAbleToCollide(false);
                        it->get<ComponentCollider>()->setTimeNonCollide();
                    }
                    if (e->get<ComponentCube>()->getTexturePath() == "assets/16/boost_nb_bombs.png")
                        it->get<ComponentBombs>()->setNbMaxBombs(it->get<ComponentBombs>()->getNbMaxBombs() + 1);
                    if (e->get<ComponentCube>()->getTexturePath() == "assets/16/boost_radius_bombs.png")
                        it->get<ComponentExplodable>()->setBlastRange(it->get<ComponentExplodable>()->getBlastRange() + 1);
                    if (e->get<ComponentCube>()->getTexturePath() == "assets/16/boost_speed.png") {
                        it->get<ComponentMovable>()->setSpeed(it->get<ComponentMovable>()->getSpeed() + BASE_SPEED_PLAYERS);
                    }
                }
                return;
            }
        }
    }
} // namespace ecs
