/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemExplosion
*/

#pragma once

#include "ISystem.hpp"

namespace ecs
{
    class SystemExplosion : public ecs::ISystem {
      public:
        SystemExplosion();
        ~SystemExplosion();

        void update(ecs::Core &core);

      private:
    };
} // namespace ecs
