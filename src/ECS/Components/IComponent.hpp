/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** IComponent
*/

#pragma once

namespace ecs
{
    class IComponent {
      protected:
        static unsigned int _idCount;
    };

    template <typename T> class TemplateComponent : public IComponent {
      public:
        static unsigned int getId()
        {
            static unsigned int id = ecs::IComponent::_idCount++;
            return id;
        }
    };
} // namespace ecs
