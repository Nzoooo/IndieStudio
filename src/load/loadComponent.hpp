/*
** EPITECH PROJECT, 2022
** Project
** File description:
** loadComponent
*/

#ifndef LOADCOMPONENT_HPP_
#define LOADCOMPONENT_HPP_

#include "ECS/Components/AllComponents.hpp"
#include "ECS/Entities/IEntity.hpp"

void addComponentBombs(std::ifstream &file, ecs::IEntity *entity);
void addComponentCollider(std::ifstream &file, ecs::IEntity *entity);
void addComponentControllable(std::ifstream &file, ecs::IEntity *entity);
void addComponentCube(std::ifstream &file, ecs::IEntity *entity);
void addComponentDrawable(std::ifstream &file, ecs::IEntity *entity);
void addComponentDroppable(std::ifstream &file, ecs::IEntity *entity);
void addComponentExplodable(std::ifstream &file, ecs::IEntity *entity);
void addComponentKillable(std::ifstream &file, ecs::IEntity *entity);
void addComponentMesh(std::ifstream &file, ecs::IEntity *entity);
void addComponentMovable(std::ifstream &file, ecs::IEntity *entity);
void addComponentPickable(std::ifstream &file, ecs::IEntity *entity);
void addComponentRectangle(std::ifstream &file, ecs::IEntity *entity);
void addComponentTexture(std::ifstream &file, ecs::IEntity *entity);
void addComponentTransform(std::ifstream &file, ecs::IEntity *entity);
void addComponentTransparency(std::ifstream &file, ecs::IEntity *entity);
std::string removeTabs(std::string line);

#endif /* !LOADCOMPONENT_HPP_ */
