/*
** EPITECH PROJECT, 2022
** Mouse
** File description:
** Mouse
*/

#pragma once

#include "raylib.hpp"

namespace raylib
{
    class Mouse {
      public:
        Mouse() = default;
        ~Mouse() = default;

        ::Vector2 GetPos();
        int GetX();
        int GetY();
        void SetPos(int x, int y);
        bool IsButtonPressed(int button);
        bool IsButtonDown(int button);
        bool IsButtonReleased(int button);
        bool IsButtonUp(int button);
        void SetMouseScale(float scaleX, float scaleY);
        void SetCursor(int cursor);

        static MouseCursor MouseCursorDefault();
        static MouseCursor MouseCursorArrow();
        static MouseCursor MouseCursorIbeam();
        static MouseCursor MouseCursorCrosshair();
        static MouseCursor MouseCursorPointingHand();
        static MouseCursor MouseCursorResizeEw();
        static MouseCursor MouseCursorResizeNs();
        static MouseCursor MouseCursorResizeNwse();
        static MouseCursor MouseCursorResizeNesw();
        static MouseCursor MouseCursorResizeAll();
        static MouseCursor MouseCursorNotAllowed();

        static MouseButton MouseButtonLeft();
        static MouseButton MouseButtonRight();
        static MouseButton MouseButtonMiddle();
        static MouseButton MouseButtonSide();
        static MouseButton MouseButtonExtra();
        static MouseButton MouseButtonForward();
        static MouseButton MouseButtonBack();

      protected:
      private:
    };
} // namespace raylib
