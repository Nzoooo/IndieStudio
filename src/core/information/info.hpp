/*
** EPITECH PROJECT, 2022
** Project
** File description:
** info
*/

#pragma once

#include "ECS/Entities/IEntity.hpp"
#include "ECS/ecs.hpp"

void initInformations(ecs::Core &core);
void updateInformations(ecs::Core &core, ecs::IEntity *player);
