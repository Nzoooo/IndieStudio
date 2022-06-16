/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#pragma once

#include "ECS/ecs.hpp"
#include "ISystem.hpp"
#include "raylib/include/Mouse.hpp"
#include "raylib/include/Vector2.hpp"

namespace ecs
{
    class SystemEvent : public ecs::ISystem {
      public:
        SystemEvent() = default;
        SystemEvent(const SystemEvent &other) = delete;
        ~SystemEvent() = default;
        SystemEvent &operator=(const SystemEvent &other) = delete;

        void update(ecs::Core &core);
        void handleControllersMenu(ecs::Core &core);
        void handleControllersConnectPlayers(ecs::Core &core);
        void handleControllersGame(ecs::Core &core);
        void handleControllersGameSettings(ecs::Core &core);
        void handleControllersWin(ecs::Core &core);

      private:
        void _detectNbControllers();
        bool _isControllerAssign(ecs::Core &core, int gamepadNumber);
        void _assignController(ecs::Core &core, int gamepadNumber);
        void _reassignControllers(ecs::Core &core, int gamepadNumber);
        void _resetStateButtons(ecs::Core &core, int idButton);
        void _handleButtonsMoveUpDown(ecs::Core &core, int upOrDown);
        void _handleClickOnButtons(ecs::Core &core);
    };
} // namespace ecs
