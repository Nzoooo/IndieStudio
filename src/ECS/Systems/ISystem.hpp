/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ISystem
*/

#pragma once

#include <iostream>

namespace ecs
{
    class Core;

    class ISystem {
      public:
        ~ISystem()
        {
        }
        void update(ecs::Core &core)
        {
            (void)core;
        };

      protected:
        static unsigned int _idCount;
    };

    template <typename T> class TemplateSystem : public ISystem {
      public:
        static unsigned int getId()
        {
            static unsigned int id = ecs::ISystem::_idCount++;
            return id;
        }
    };
} // namespace ecs
