/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemCollision
*/

#ifndef SYSTEMCOLLISION_HPP_
#define SYSTEMCOLLISION_HPP_

#include "ISystem.hpp"
#include "core/core.hpp"

namespace ecs
{
    typedef enum movement { DEFAULT, LEFT, RIGHT, UP, DOWN } movement;

    class SystemCollision : public ecs::ISystem {
      public:
        SystemCollision() = default;
        SystemCollision(const SystemCollision &other) = delete;
        ~SystemCollision() = default;
        SystemCollision &operator=(const SystemCollision &other) = delete;

        void update(ecs::Core &index);

      private:
    };
} // namespace ecs

#endif /* !SYSTEMCOLLISION_HPP_ */
