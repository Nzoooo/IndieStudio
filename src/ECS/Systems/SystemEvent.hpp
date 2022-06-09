/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#pragma once

#include "ISystem.hpp"
#include "../../core/core.hpp"
#include "../../raylib/include/Vector2.hpp"

namespace ecs {
    class SystemEvent : public ecs::ISystem {
        public:
            SystemEvent() = default;
            SystemEvent(const SystemEvent &other) = delete;
            ~SystemEvent() = default;
            SystemEvent &operator=(const SystemEvent &other) = delete;

            void update(ecs::Core &index);
            void handleControllers();

        protected:
        private:
    };
}
