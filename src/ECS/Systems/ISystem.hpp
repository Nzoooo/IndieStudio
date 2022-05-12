/*
** EPITECH PROJECT, 2022
** Project
** File description:
** ISystem
*/

#pragma once

namespace ecs
{
    class World;

    class ISystem {
      public:
        virtual ~ISystem()
        {
        }
        virtual void update(ecs::World &world) = 0;

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
