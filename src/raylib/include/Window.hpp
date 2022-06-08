/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#pragma once

#include <string>
#include "Color.hpp"
#include "raylib.hpp"

namespace raylib
{
    class Window {
      public:
        static void Close();
        static void Init(int width = 800, int height = 600, const std::string &title = "raylib");
        static bool isReady();
        static bool ShouldClose();
        static bool IsFullscreen();
        static bool IsMinimized();
        static bool IsMaximized();
        static bool IsResized();
        static void Maximize();
        static void Minimize();
        static void Restore();
        static void SetIcon(::Image &image);
        static void SetTitle(const std::string &title);
        static void SetPosition(int x, int y);
        static void SetMinSize(int width, int height);
        static void SetSize(int width, int height);
        static int GetWidth();
        static int GetHeight();
        static ::Vector2 GetPosition();
        static void BeginDrawing();
        static void EndDrawing();
        static float GetFrameTime();
        static double GetTime();
        static void Clear(Color color);

      protected:
      private:
    };
} // namespace raylib
