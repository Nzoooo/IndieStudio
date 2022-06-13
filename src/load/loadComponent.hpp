/*
** EPITECH PROJECT, 2022
** Project
** File description:
** loadComponent
*/

#ifndef LOADCOMPONENT_HPP_
#define LOADCOMPONENT_HPP_

#include "ECS/Components/ComponentKillable.hpp"
#include "ECS/Components/ComponentMovable.hpp"
#include "ECS/Components/ComponentTransform.hpp"
#include "ECS/Entities/IEntity.hpp"

void addComponentMovable(std::ifstream &file, ecs::IEntity *entity);
void addComponentTransform(std::ifstream &file, ecs::IEntity *entity);
void addComponentKillable(std::ifstream &file, ecs::IEntity *entity);
std::string removeTabs(std::string line);

#endif /* !LOADCOMPONENT_HPP_ */
