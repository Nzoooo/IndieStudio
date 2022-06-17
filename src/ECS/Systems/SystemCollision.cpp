/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemCollision
*/

#include "SystemCollision.hpp"
#include "raylib/include/BoundingBox.hpp"
#include "raylib/include/Gamepad.hpp"

// bool collisionDown(Vector3 playerPosition, Vector3 playerSize, Vector3 enemyBoxPos, Vector3 enemyBoxSize)
// {
//     if (CheckCollisionBoxes(
//         (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
//                                 playerPosition.y - playerSize.y/2,
//                                 playerPosition.z - playerSize.z/2},
//                         (Vector3){ playerPosition.x + playerSize.x/2,
//                                 playerPosition.y + playerSize.y/2,
//                                 playerPosition.z + playerSize.z/2 + 0.1f }},
//         (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
//                                 enemyBoxPos.y - enemyBoxSize.y/2,
//                                 enemyBoxPos.z - enemyBoxSize.z/2 },
//                         (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
//                                 enemyBoxPos.y + enemyBoxSize.y/2,
//                                 enemyBoxPos.z + enemyBoxSize.z/2 }})) return true;
//     return false;
// }

// bool collisionUp(Vector3 playerPosition, Vector3 playerSize, Vector3 enemyBoxPos, Vector3 enemyBoxSize)
// {
//     if (CheckCollisionBoxes(
//         (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
//                                 playerPosition.y - playerSize.y/2,
//                                 playerPosition.z - playerSize.z/2 - 0.1f},
//                         (Vector3){ playerPosition.x + playerSize.x/2,
//                                 playerPosition.y + playerSize.y/2,
//                                 playerPosition.z + playerSize.z/2 }},
//         (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
//                                 enemyBoxPos.y - enemyBoxSize.y/2,
//                                 enemyBoxPos.z - enemyBoxSize.z/2 },
//                         (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
//                                 enemyBoxPos.y + enemyBoxSize.y/2,
//                                 enemyBoxPos.z + enemyBoxSize.z/2 }})) return true;
//     return false;
// }

// bool collisionRight(Vector3 playerPosition, Vector3 playerSize, Vector3 enemyBoxPos, Vector3 enemyBoxSize)
// {
//     if (CheckCollisionBoxes(
//         (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
//                                 playerPosition.y - playerSize.y/2,
//                                 playerPosition.z - playerSize.z/2 },
//                         (Vector3){ playerPosition.x + playerSize.x/2 + 0.1f,
//                                 playerPosition.y + playerSize.y/2,
//                                 playerPosition.z + playerSize.z/2 }},
//         (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
//                                 enemyBoxPos.y - enemyBoxSize.y/2,
//                                 enemyBoxPos.z - enemyBoxSize.z/2 },
//                         (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
//                                 enemyBoxPos.y + enemyBoxSize.y/2,
//                                 enemyBoxPos.z + enemyBoxSize.z/2 }})) return true;
//     return false;
// }

// bool collisionLeft(Vector3 playerPosition, Vector3 playerSize, Vector3 enemyBoxPos, Vector3 enemyBoxSize)
// {
//     if (CheckCollisionBoxes(
//         (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2 - 0.1f,
//                                 playerPosition.y - playerSize.y/2,
//                                 playerPosition.z - playerSize.z/2 },
//                         (Vector3){ playerPosition.x + playerSize.x/2,
//                                 playerPosition.y + playerSize.y/2,
//                                 playerPosition.z + playerSize.z/2 }},
//         (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
//                                 enemyBoxPos.y - enemyBoxSize.y/2,
//                                 enemyBoxPos.z - enemyBoxSize.z/2 },
//                         (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
//                                 enemyBoxPos.y + enemyBoxSize.y/2,
//                                 enemyBoxPos.z + enemyBoxSize.z/2 }})) return true;
//     return false;
// }

// movement checkMovement(Vector3 playerPosition, Vector3 playerSize, Vector3 enemyBoxPos, Vector3 enemyBoxSize)
// {
//     bool tmp = false;
//     if (collisionLeft(playerPosition, playerSize, enemyBoxPos, enemyBoxSize))
//         return (LEFT);
//     if (collisionRight(playerPosition, playerSize, enemyBoxPos, enemyBoxSize))
//         return (RIGHT);
//     if (collisionUp(playerPosition, playerSize, enemyBoxPos, enemyBoxSize))
//         return (UP);
//     if (collisionDown(playerPosition, playerSize, enemyBoxPos, enemyBoxSize))
//         return(DOWN);
//     return (DEFAULT);
// }

// Vector3 leftMovementCollision(Vector3 playerPosition)
// {
//     if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.1f;
//     else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.0f;
//     else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.1f;
//     else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.1f;
//     return playerPosition;
// }

// Vector3 rightMovementCollision(Vector3 playerPosition)
// {
//     if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.0f;
//     else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.1f;
//     else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.1f;
//     else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.1f;
//     return playerPosition;
// }

// Vector3 upMovementCollision(Vector3 playerPosition)
// {
//     if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.1f;
//     else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.1f;
//     else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.1f;
//     else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.0f;
//     return playerPosition;
// }

// Vector3 downMovementCollision(Vector3 playerPosition)
// {
//     if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.1f;
//     else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.1f;
//     else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.0f;
//     else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.1f;
//     return playerPosition;
// }

// Vector3 movementPlayer(Vector3 playerPosition)
// {
//     if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.1f;
//     else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.1f;
//     else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.1f;
//     else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.1f;
//     return (playerPosition);
// }

namespace ecs
{
    void SystemCollision::update(ecs::Core &index)
    {
        for (auto *it : index.getEntities()) {
            if (it->has<ComponentCollider>() && it->has<ComponentMovable>()) {
                raylib::Vector3 pos(it->get<ComponentCube>()->getPos());
                raylib::Vector3 size(it->get<ComponentCube>()->getSize());
                for (auto *at : index.getEntities()) {
                    if (at->get<ComponentCollider>() != it->get<ComponentCollider>()) {
                        it->get<ComponentCollider>()->setCollision(raylib::BoundingBox(
                            raylib::Vector3(pos.x - size.x / 2, pos.y - size.y / 2, pos.z - size.z / 2 - 0.1f), raylib::Vector3(pos.x + size.x / 2, pos.y + size.y / 2, pos.z + size.z / 2)));
                        if (it->get<ComponentCollider>()->getCollision().checkCollision(at->get<ComponentCollider>()->getCollision())) {
                            it->get<ComponentCollider>()->add_vector(true);
                            // std::cout << "i don't touch" << std::endl;
                            break;
                        } else {
                            // std::cout << "i touch" << std::endl;
                            it->get<ComponentMovable>()->setSpeed(0.001f);
                            pos.x += 0.1f;
                            it->get<ComponentCube>()->_posTmp = pos;
                            it->get<ComponentCollider>()->add_vector(false);
                        }
                    }
                    // if (it->get<ComponentMovable>()->getDirection() == ComponentMovable::Direction::DOWN) {
                    //     if (!it->get<ComponentCollider>()->getCollision().checkCollision(at->get<ComponentCollider>()->getCollision())) {
                    //         it->get<ComponentMovable>()->setSpeed(0.0001f);
                    //         it->get<ComponentCube>()->setPos(it->get<ComponentCube>()->_posTmp);
                    //         std::cout << "i don't touch" << std::endl;
                    //         break;
                    //     } else if (it->get<ComponentCollider>()->getCollision().checkCollision(at->get<ComponentCollider>()->getCollision())) {
                    //         std::cout << "i touch" << std::endl;
                    //     }
                    // }
                }
                // if (it->get<ComponentMovable>()->getDirection() == ComponentMovable::Direction::LEFT) {
                //     it->get<ComponentCube>()->setPos(it->get<ComponentCube>()->_posTmp);
                //     // it->get<ComponentMovable>()->setSpeed(0.0001f);
                // }
                // if (it->get<ComponentMovable>()->getDirection() == ComponentMovable::Direction::RIGHT) {
                //     it->get<ComponentCube>()->setPos(it->get<ComponentCube>()->_posTmp);
                //     // it->get<ComponentMovable>()->setSpeed(0.0001f);
                // }
                // if (it->get<ComponentMovable>()->getDirection() == ComponentMovable::Direction::UP) {
                //     it->get<ComponentCube>()->setPos(it->get<ComponentCube>()->_posTmp);
                //     // it->get<ComponentMovable>()->setSpeed(0.0001f);
                // }
                // if (it->get<ComponentMovable>()->getDirection() == ComponentMovable::Direction::DOWN) {
                //     it->get<ComponentCube>()->setPos(it->get<ComponentCube>()->_posTmp);

                // }
            }
        }
    }
} // namespace ecs
