/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** core
*/

#ifndef CORE_HEADER
#define CORE_HEADER

#include "ECS/ecs.hpp"
#include "map/Map.hpp"
#include "raylib/include/Camera3D.hpp"
#include "raylib/include/Window.hpp"
#include "raylib/include/raylib.hpp"

#include <chrono>
#include <math.h>
#include <string>
#include <time.h>

#define FPS_CAP      120
#define ML_BASE      1000.0
#define FPS_CAP_REAL (ML_BASE / FPS_CAP)

enum map_object {
    AIR = 0,
    WALL = 1,
    BOX = 2,
};

ecs::Scenes coreLoop(std::vector<int> &idControllers, std::vector<int> &settings, std::string &winner, ecs::GameStartMode start_mode);
ecs::Core mapCreation(std::vector<int> &idControllers, std::vector<int> &settings, ecs::GameStartMode start_mode);

#endif
