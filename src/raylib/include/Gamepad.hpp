/*
** EPITECH PROJECT, 2022
** Gamepad
** File description:
** Gamepad
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class Gamepad {
      public:
        static int gamepadNumber;
        static bool IsAvailable(int number);
        static const std::string GetName(int number);
        static bool IsButtonPressed(int number, int button);
        static bool IsButtonDown(int number, int button);
        static bool IsButtonReleased(int number, int button);
        static bool IsButtonUp(int number, int button);
        static int GetButtonPressed();
        static int GetAxisCount(int number);
        static float GetAxisMovement(int number, int axis);

        static GamepadButton GamepadButtonUnknown();
        static GamepadButton GamepadButtonLeftFaceUp();
        static GamepadButton GamepadButtonLeftFaceRight();
        static GamepadButton GamepadButtonLeftFaceDown();
        static GamepadButton GamepadButtonLeftFaceLeft();
        static GamepadButton GamepadButtonRightFaceUp();
        static GamepadButton GamepadButtonRightFaceRight();
        static GamepadButton GamepadButtonRightFaceDown();
        static GamepadButton GamepadButtonRightFaceLeft();
        static GamepadButton GamepadButtonLeftTrigger1();
        static GamepadButton GamepadButtonLeftTrigger2();
        static GamepadButton GamepadButtonRightTrigger1();
        static GamepadButton GamepadButtonRightTrigger2();
        static GamepadButton GamepadButtonMiddleLeft();
        static GamepadButton GamepadButtonMiddle();
        static GamepadButton GamepadButtonMiddleRight();
        static GamepadButton GamepadButtonLeftThumb();
        static GamepadButton GamepadButtonRightThumb();

        static GamepadAxis GamepadAxisLeftX();
        static GamepadAxis GamepadAxisLeftY();
        static GamepadAxis GamepadAxisLeftTrigger();
        static GamepadAxis GamepadAxisRightX();
        static GamepadAxis GamepadAxisRightY();
        static GamepadAxis GamepadAxisRightTrigger();

      protected:
      private:
    };
} // namespace raylib
