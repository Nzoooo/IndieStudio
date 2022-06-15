/*
** EPITECH PROJECT, 2022
** Project
** File description:
** loadComponent
*/

#ifndef LOADCOMPONENT_HPP_
#define LOADCOMPONENT_HPP_

#include "ECS/Components/ComponentClickable.hpp"
#include "ECS/Components/ComponentCollider.hpp"
#include "ECS/Components/ComponentDrawable.hpp"
#include "ECS/Components/ComponentDroppable.hpp"
#include "ECS/Components/ComponentExplodable.hpp"
#include "ECS/Components/ComponentKillable.hpp"
#include "ECS/Components/ComponentMovable.hpp"
#include "ECS/Components/ComponentPickable.hpp"
#include "ECS/Components/ComponentTransform.hpp"
#include "ECS/Entities/IEntity.hpp"

void addComponentClickable(std::ifstream &file, ecs::IEntity *entity);
void addComponentCollider(std::ifstream &file, ecs::IEntity *entity);
void addComponentDrawable(std::ifstream &file, ecs::IEntity *entity);
void addComponentDroppable(std::ifstream &file, ecs::IEntity *entity);
void addComponentExplodable(std::ifstream &file, ecs::IEntity *entity);
void addComponentKillable(std::ifstream &file, ecs::IEntity *entity);
void addComponentMovable(std::ifstream &file, ecs::IEntity *entity);
void addComponentPickable(std::ifstream &file, ecs::IEntity *entity);
void addComponentTransform(std::ifstream &file, ecs::IEntity *entity);
std::string removeTabs(std::string line);

#endif /* !LOADCOMPONENT_HPP_ */
