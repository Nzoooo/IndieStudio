/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** initMap
*/

#ifndef INITMAP_HPP_
#define INITMAP_HPP_

#include "ECS/ecs.hpp"
#include "map/Map.hpp"

ecs::Core mapCreation(std::vector<int> &idControllers, std::vector<int> &Settings, ecs::GameStartMode start_mode);

#endif /* !INITMAP_HPP_ */
