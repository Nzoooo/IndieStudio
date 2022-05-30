/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib {
    class Window {
        public:
            Window(int width = 800, int height = 600, const std::string &title = "raylib");
            Window(const Window &other) = delete;
            ~Window();

            void Close();
            void Init(int width = 800, int height = 600, const std::string &title = "raylib");
            bool isReady() const;
            bool ShouldClose() const;
            bool IsFullscreen();
            bool IsMinimized();
            bool IsMaximized();
            bool IsResized();
            void Maximize();
            void Minimize();
            void Restore();
            void SetIcon(::Image &image);
            void SetTitle(const std::string &title);
            void SetPosition(int x, int y);
            void SetMinSize(int width, int height);
            void SetSize(int width, int height);
            int GetWidth();
            int GetHeight();
            ::Vector2 GetPosition();
            void BeginDrawing();
            void EndDrawing();
            float GetFrameTime();
            double GetTime();

        protected:
        private:
    };
}
