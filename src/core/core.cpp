/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include "core.hpp"

double clockToMilliseconds(clock_t ticks)
{
    return (ticks / ((double)CLOCKS_PER_SEC)) * ML_BASE;
}

int coreLoop()
{
    clock_t sec_clock = clock();
    clock_t fps_clock = clock();
    int running = 1;
    int fps = 0;
    int avg_fps = FPS_CAP;

    while (running) {
        if (clockToMilliseconds(clock() - fps_clock) >= FPS_CAP_REAL) {
            fps_clock = clock();
            fps++;

            // do tick-based actions here, eg: graphical rendering and stuff like that, I/O checking;
        }

        if (clockToMilliseconds(clock() - sec_clock) >= ML_BASE) {
            sec_clock = clock();
            avg_fps = (avg_fps + fps) / 2;
            // do game logic and stuff like that here, eg: this action happens every X seconds, not X fps...;
            printf("second tick, delta fps: %d, avg fps: %d fps is capped around: %d\n", fps, avg_fps, FPS_CAP);
            fps = 0;
        }
    }

    return (0);
}