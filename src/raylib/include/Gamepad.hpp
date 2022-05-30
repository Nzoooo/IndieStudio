/*
** EPITECH PROJECT, 2022
** Gamepad
** File description:
** Gamepad
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib {
    class Gamepad {
        public:
            Gamepad();
            ~Gamepad();

            static int gamepadNumber;
            bool IsAvailable();
            const std::string GetName();
            bool IsButtonPressed(int button);
            bool IsButtonDown(int button);
            bool IsButtonReleased(int button);
            bool IsButtonUp(int button);
            int GetButtonPressed();
            int GetAxisCount();
            float GetAxisMovement(int axis);

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
            int number;
    };
}
