/*
** EPITECH PROJECT, 2022
** SystemRender3D
** File description:
** SystemRender3D
*/

#pragma once

#include "ISystem.hpp"
#include "../../core/core.hpp"

class SystemRender3D : ecs::ISystem {
    public:
        SystemRender3D() = default;
        SystemRender3D(const SystemRender3D &other) = delete;
        ~SystemRender3D() = default;
        SystemRender3D &operator=(const SystemRender3D &other) = delete;

        void update(ecs::Core &index) override;

    protected:
    private:
};
