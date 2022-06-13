/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** core
*/

#ifndef CORE_HEADER
#define CORE_HEADER

#include <chrono>
#include <math.h>
#include <string>
#include <time.h>
#include "ECS/ecs.hpp"
#include "raylib/include/Window.hpp"
#include "raylib/include/raylib.hpp"

#define FPS_CAP      120
#define ML_BASE      1000.0
#define FPS_CAP_REAL (ML_BASE / FPS_CAP)

int coreLoop(ecs::Core);

#endif
