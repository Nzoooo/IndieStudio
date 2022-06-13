/*
** EPITECH PROJECT, 2022
** Gamepad
** File description:
** Gamepad
*/

#include "../include/Gamepad.hpp"

int raylib::Gamepad::gamepadNumber = 3;

namespace raylib
{
    bool Gamepad::IsAvailable(int number)
    {
        return (::IsGamepadAvailable(number));
    }

    const std::string Gamepad::GetName(int number)
    {
        return (static_cast<std::string>(::GetGamepadName(number)));
    }

    bool Gamepad::IsButtonPressed(int number, int button)
    {
        return (::IsGamepadButtonPressed(number, button));
    }

    bool Gamepad::IsButtonDown(int number, int button)
    {
        return (::IsGamepadButtonDown(number, button));
    }

    bool Gamepad::IsButtonReleased(int number, int button)
    {
        return (::IsGamepadButtonReleased(number, button));
    }

    bool Gamepad::IsButtonUp(int number, int button)
    {
        return (::IsGamepadButtonUp(number, button));
    }

    int Gamepad::GetButtonPressed()
    {
        return (::GetGamepadButtonPressed());
    }

    int Gamepad::GetAxisCount(int number)
    {
        return (::GetGamepadAxisCount(number));
    }

    float Gamepad::GetAxisMovement(int number, int axis)
    {
        return (::GetGamepadAxisMovement(number, axis));
    }

    GamepadButton Gamepad::GamepadButtonUnknown()
    {
        return (GAMEPAD_BUTTON_UNKNOWN);
    }

    GamepadButton Gamepad::GamepadButtonLeftFaceUp()
    {
        return (GAMEPAD_BUTTON_LEFT_FACE_UP);
    }

    GamepadButton Gamepad::GamepadButtonLeftFaceRight()
    {
        return (GAMEPAD_BUTTON_LEFT_FACE_RIGHT);
    }

    GamepadButton Gamepad::GamepadButtonLeftFaceDown()
    {
        return (GAMEPAD_BUTTON_LEFT_FACE_DOWN);
    }

    GamepadButton Gamepad::GamepadButtonLeftFaceLeft()
    {
        return (GAMEPAD_BUTTON_LEFT_FACE_LEFT);
    }

    GamepadButton Gamepad::GamepadButtonRightFaceUp()
    {
        return (GAMEPAD_BUTTON_RIGHT_FACE_UP);
    }

    GamepadButton Gamepad::GamepadButtonRightFaceRight()
    {
        return (GAMEPAD_BUTTON_RIGHT_FACE_RIGHT);
    }

    GamepadButton Gamepad::GamepadButtonRightFaceDown()
    {
        return (GAMEPAD_BUTTON_RIGHT_FACE_DOWN);
    }

    GamepadButton Gamepad::GamepadButtonRightFaceLeft()
    {
        return (GAMEPAD_BUTTON_RIGHT_FACE_LEFT);
    }

    GamepadButton Gamepad::GamepadButtonLeftTrigger1()
    {
        return (GAMEPAD_BUTTON_LEFT_TRIGGER_1);
    }

    GamepadButton Gamepad::GamepadButtonLeftTrigger2()
    {
        return (GAMEPAD_BUTTON_LEFT_TRIGGER_2);
    }

    GamepadButton Gamepad::GamepadButtonRightTrigger1()
    {
        return (GAMEPAD_BUTTON_RIGHT_TRIGGER_1);
    }

    GamepadButton Gamepad::GamepadButtonRightTrigger2()
    {
        return (GAMEPAD_BUTTON_RIGHT_TRIGGER_2);
    }

    GamepadButton Gamepad::GamepadButtonMiddleLeft()
    {
        return (GAMEPAD_BUTTON_MIDDLE_LEFT);
    }

    GamepadButton Gamepad::GamepadButtonMiddle()
    {
        return (GAMEPAD_BUTTON_MIDDLE);
    }

    GamepadButton Gamepad::GamepadButtonMiddleRight()
    {
        return (GAMEPAD_BUTTON_MIDDLE_RIGHT);
    }

    GamepadButton Gamepad::GamepadButtonLeftThumb()
    {
        return (GAMEPAD_BUTTON_LEFT_THUMB);
    }

    GamepadButton Gamepad::GamepadButtonRightThumb()
    {
        return (GAMEPAD_BUTTON_RIGHT_THUMB);
    }

    GamepadAxis Gamepad::GamepadAxisLeftX()
    {
        return (GAMEPAD_AXIS_LEFT_X);
    }

    GamepadAxis Gamepad::GamepadAxisLeftY()
    {
        return (GAMEPAD_AXIS_LEFT_Y);
    }

    GamepadAxis Gamepad::GamepadAxisLeftTrigger()
    {
        return (GAMEPAD_AXIS_LEFT_TRIGGER);
    }

    GamepadAxis Gamepad::GamepadAxisRightX()
    {
        return (GAMEPAD_AXIS_RIGHT_X);
    }

    GamepadAxis Gamepad::GamepadAxisRightY()
    {
        return (GAMEPAD_AXIS_RIGHT_Y);
    }

    GamepadAxis Gamepad::GamepadAxisRightTrigger()
    {
        return (GAMEPAD_AXIS_RIGHT_TRIGGER);
    }
} // namespace raylib
