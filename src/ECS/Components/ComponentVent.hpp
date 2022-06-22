/*
** EPITECH PROJECT, 2022
** ComponentVent.hpp
** File description:
** ComponentVent.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "ECS/ecs.hpp"
#include "ECS/Entities/IEntity.hpp"

class ComponentVent : public ecs::IComponent {
    public:
        ComponentVent();
        ~ComponentVent() = default;

        void pairVent(ecs::IEntity *ventToPair);
        ecs::IEntity *getPairedVent();
    private:
        ecs::IEntity *_pairedVent;
};