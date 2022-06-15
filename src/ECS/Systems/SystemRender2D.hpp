/*
** EPITECH PROJECT, 2022
** SystemRender2D
** File description:
** SystemRender2D
*/

#pragma once

#include "ECS/ecs.hpp"
#include "ISystem.hpp"

namespace ecs
{
    class SystemRender2D : public ecs::ISystem {
      public:
        SystemRender2D() = default;
        SystemRender2D(const SystemRender2D &other) = delete;
        ~SystemRender2D() = default;
        SystemRender2D &operator=(const SystemRender2D &other) = delete;

        void update(ecs::Core &core);

      protected:
      private:
    };
} // namespace ecs
