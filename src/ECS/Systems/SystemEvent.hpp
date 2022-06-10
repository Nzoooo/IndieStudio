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
#include "../../raylib/include/Mouse.hpp"

namespace ecs {
    class SystemEvent : public ecs::ISystem {
        public:
            SystemEvent() = default;
            SystemEvent(const SystemEvent &other) = delete;
            ~SystemEvent() = default;
            SystemEvent &operator=(const SystemEvent &other) = delete;

            void update(ecs::Core &index);
            void handleControllersMenu(ecs::Core &index);
            void handleControllersConnectPlayers(ecs::Core &index);
            void handleControllersGame(ecs::Core &index);
            void handleControllersGameSettings(ecs::Core &index);
            void handleControllersWin(ecs::Core &index);

        protected:
        private:
            void _detectNbControllers();
            bool _isControllerAssign(ecs::Core &index, int gamepadNumber);
            void _assignController(ecs::Core &index, int gamepadNumber);
            void _reassignControllers(ecs::Core &index, int gamepadNumber);
            void _resetStateButtons(ecs::Core &index, int idButton);
            void _handleButtonsMoveUpDown(ecs::Core &index, int upOrDown);
            void _handleClickOnButtons(ecs::Core &index);
    };
}
