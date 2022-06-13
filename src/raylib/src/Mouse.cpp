/*
** EPITECH PROJECT, 2022
** Mouse
** File description:
** Mouse
*/

#include "../include/Mouse.hpp"

namespace raylib
{
    ::Vector2 Mouse::GetPos()
    {
        return (::GetMousePosition());
    }

    int Mouse::GetX()
    {
        return (::GetMouseX());
    }

    int Mouse::GetY()
    {
        return (::GetMouseY());
    }

    void Mouse::SetPos(int x, int y)
    {
        ::SetMousePosition(x, y);
    }

    bool Mouse::IsButtonPressed(int button)
    {
        return (::IsMouseButtonPressed(button));
    }

    bool Mouse::IsButtonDown(int button)
    {
        return (::IsMouseButtonDown(button));
    }

    bool Mouse::IsButtonReleased(int button)
    {
        return (IsMouseButtonReleased(button));
    }

    bool Mouse::IsButtonUp(int button)
    {
        return (::IsMouseButtonUp(button));
    }

    void Mouse::SetMouseScale(float scaleX, float scaleY)
    {
        ::SetMouseScale(scaleX, scaleY);
    }

    void Mouse::SetCursor(int cursor)
    {
        ::SetMouseCursor(cursor);
    }

    MouseCursor Mouse::MouseCursorDefault()
    {
        return (MOUSE_CURSOR_DEFAULT);
    }

    MouseCursor Mouse::MouseCursorArrow()
    {
        return (MOUSE_CURSOR_ARROW);
    }

    MouseCursor Mouse::MouseCursorIbeam()
    {
        return (MOUSE_CURSOR_IBEAM);
    }

    MouseCursor Mouse::MouseCursorCrosshair()
    {
        return (MOUSE_CURSOR_CROSSHAIR);
    }

    MouseCursor Mouse::MouseCursorPointingHand()
    {
        return (MOUSE_CURSOR_POINTING_HAND);
    }

    MouseCursor Mouse::MouseCursorResizeEw()
    {
        return (MOUSE_CURSOR_RESIZE_EW);
    }

    MouseCursor Mouse::MouseCursorResizeNs()
    {
        return (MOUSE_CURSOR_RESIZE_NS);
    }

    MouseCursor Mouse::MouseCursorResizeNwse()
    {
        return (MOUSE_CURSOR_RESIZE_NWSE);
    }

    MouseCursor Mouse::MouseCursorResizeNesw()
    {
        return (MOUSE_CURSOR_RESIZE_NESW);
    }

    MouseCursor Mouse::MouseCursorResizeAll()
    {
        return (MOUSE_CURSOR_RESIZE_ALL);
    }

    MouseCursor Mouse::MouseCursorNotAllowed()
    {
        return (MOUSE_CURSOR_NOT_ALLOWED);
    }

    MouseButton Mouse::MouseButtonLeft()
    {
        return (MOUSE_BUTTON_LEFT);
    }

    MouseButton Mouse::MouseButtonRight()
    {
        return (MOUSE_BUTTON_RIGHT);
    }

    MouseButton Mouse::MouseButtonMiddle()
    {
        return (MOUSE_BUTTON_MIDDLE);
    }

    MouseButton Mouse::MouseButtonSide()
    {
        return (MOUSE_BUTTON_SIDE);
    }

    MouseButton Mouse::MouseButtonExtra()
    {
        return (MOUSE_BUTTON_EXTRA);
    }

    MouseButton Mouse::MouseButtonForward()
    {
        return (MOUSE_BUTTON_FORWARD);
    }

    MouseButton Mouse::MouseButtonBack()
    {
        return (MOUSE_BUTTON_BACK);
    }
} // namespace raylib
