/*
** EPITECH PROJECT, 2022
** SystemEvent
** File description:
** SystemEvent
*/

#include "SystemEvent.hpp"
#include "../../raylib/include/Gamepad.hpp"

namespace ecs {
    void SystemEvent::handleControllers()
    {
        for (int i = 0; i <= raylib::Gamepad::gamepadNumber; i++) {
            if (raylib::Gamepad::IsAvailable(i)) {
                // Draw buttons: xbox home
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddle())) std::cout << "home" << std::endl;

                // Draw buttons: basic
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddleRight())) std::cout << "start" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonMiddleLeft())) std::cout << "select" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceRight())) std::cout << "O" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceDown())) std::cout << "X" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceLeft())) std::cout << "[]" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightFaceUp())) std::cout << "/\\" << std::endl;

                // Draw buttons: d-pad
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceUp())) std::cout << "up" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceDown())) std::cout << "down" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceLeft())) std::cout << "left" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftFaceRight())) std::cout << "right" << std::endl;

                // Draw buttons: left-right back
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonLeftTrigger1())) std::cout << "a" << std::endl;
                if (raylib::Gamepad::IsButtonDown(i, raylib::Gamepad::GamepadButtonRightTrigger1())) std::cout << "b" << std::endl;

                // Draw axis: left joystick
                // std::cout << "GAMEPAD_AXIS_LEFT_X: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftX()) << std::endl;
                // std::cout << "GAMEPAD_AXIS_LEFT_Y: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftY()) << std::endl;

                // Draw axis: right joystick
                // std::cout << "GAMEPAD_AXIS_RIGHT_X: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightX()) << std::endl;
                // std::cout << "GAMEPAD_AXIS_RIGHT_Y: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightY()) << std::endl;

                // Draw axis: left-right triggers
                // std::cout << "GAMEPAD_AXIS_LEFT_TRIGGER: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisLeftTrigger()) << std::endl;
                // std::cout << "GAMEPAD_AXIS_RIGHT_TRIGGER: " << raylib::Gamepad::GetAxisMovement(i, raylib::Gamepad::GamepadAxisRightTrigger()) << std::endl;
            }
        }
    }

    void SystemEvent::update(ecs::Core &index)
    {
        handleControllers();
    }
}
