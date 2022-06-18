/*
** EPITECH PROJECT, 2022
** SystemRender3D
** File description:
** SystemRender3D
*/

#pragma once

#include "ECS/ecs.hpp"
#include "ISystem.hpp"

namespace ecs
{
    class SystemRender3D : public ecs::ISystem {
      public:
        SystemRender3D() = default;
        SystemRender3D(const SystemRender3D &other) = delete;
        ~SystemRender3D() = default;
        SystemRender3D &operator=(const SystemRender3D &other) = delete;

        void update(ecs::Core &core);

      protected:
      private:
    };
} // namespace ecs
