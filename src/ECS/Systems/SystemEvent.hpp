/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#pragma once

#include "ISystem.hpp"
#include "core.hpp"

class SystemEvent : ecs::ISystem {
    public:
        SystemEvent();
        SystemEvent(const SystemEvent &other) = delete;
        ~SystemEvent();
        SystemEvent &operator=(const SystemEvent &other) = delete;

        void update(ecs::Core &index) override;
        void handleControllers();

    protected:
    private:
};
