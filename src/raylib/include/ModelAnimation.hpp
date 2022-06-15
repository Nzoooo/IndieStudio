/*
** EPITECH PROJECT, 2022
** ModelAnimation
** File description:
** ModelAnimation
*/

#pragma once

#include <string>
#include "raylib.hpp"

namespace raylib
{
    class ModelAnimation : public ::ModelAnimation {
      public:
        ModelAnimation();
        ModelAnimation(const ModelAnimation &other) = delete;
        ~ModelAnimation();

        void Unload(::ModelAnimation &anim);
        void Unload(unsigned int animCount);
        void UpdateAnimation(::Model &model, ::ModelAnimation &anim, int frame);
        bool IsModelAnimationValid(::Model &model, ::ModelAnimation &anim) const;
        void Load(const std::string &fileName, unsigned int *animCount);
        ::ModelAnimation *getAnims() const;

      protected:
      private:
        ::ModelAnimation *_anims;
    };
} // namespace raylib
