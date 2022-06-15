/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemExplosion
*/

#include "SystemExplosion.hpp"

ecs::SystemExplosion::SystemExplosion()
{
}

ecs::SystemExplosion::~SystemExplosion()
{
}

void ecs::SystemExplosion::update(ecs::Core &core)
{
    (void)core;
    std::cout << "Update a SystemEplosion boum !" << std::endl;
}
