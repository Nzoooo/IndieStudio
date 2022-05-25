/*
** EPITECH PROJECT, 2022
** ModelAnimation
** File description:
** ModelAnimation
*/

#pragma once

#include "raylib.hpp"

namespace raylib {
    class ModelAnimation : public ::ModelAnimation {
        public:
            ModelAnimation();
            ModelAnimation(const ModelAnimation &other) = delete;
            ~ModelAnimation();

            void Unload();
            void UpdateAnimation(::Model &model, int frame);
            bool IsModelAnimationValid(::Model &model) const;
            //Do the LoadModelAnimations method

        protected:
        private:
    };
}
