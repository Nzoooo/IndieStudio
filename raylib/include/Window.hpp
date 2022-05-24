/*
** EPITECH PROJECT, 2022
** Window
** File description:
** Window
*/

#pragma once

#include "raylib.hpp"

class Window {
    public:
        Window();
        Window(int width = 800, int height = 600, const std::string& title = "raylib");
        ~Window();

        void Close(void);
        void Init(int width, int height, const char *title);
        bool isReady() const;
        bool ShouldClose() const;

    protected:
    private:
};
