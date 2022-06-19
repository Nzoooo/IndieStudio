/*
** EPITECH PROJECT, 2022
** connectPlayers
** File description:
** connectPlayers
*/

#pragma once

#include "ECS/ecs.hpp"
#include "raylib/include/Camera3D.hpp"
#include "raylib/include/Vector3.hpp"
#include "raylib/include/Window.hpp"

ecs::Scenes connectPlayers(ecs::Core &core, std::vector<int> &idControllers);
