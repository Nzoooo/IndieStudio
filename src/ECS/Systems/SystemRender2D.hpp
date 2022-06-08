/*
** EPITECH PROJECT, 2022
** SystemRender2D
** File description:
** SystemRender2D
*/

#pragma once

#include "ISystem.hpp"
#include "../../core/core.hpp"

class SystemRender2D : ecs::ISystem {
    public:
        SystemRender2D() = default;
        SystemRender2D(const SystemRender2D &other) = delete;
        ~SystemRender2D() = default;
        SystemRender2D &operator=(const SystemRender2D &other) = delete;

        void update(ecs::Core &index) override;

    protected:
    private:
};
