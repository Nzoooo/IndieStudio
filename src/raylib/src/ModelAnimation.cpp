/*
** EPITECH PROJECT, 2022
** ModelAnimation
** File description:
** ModelAnimation
*/

#include "../include/ModelAnimation.hpp"
#include "../include/RaylibException.hpp"

raylib::ModelAnimation::ModelAnimation()
{
}

raylib::ModelAnimation::~ModelAnimation()
{
}

void raylib::ModelAnimation::Unload()
{
    ::UnloadModelAnimation(*this);
}

void raylib::ModelAnimation::UpdateAnimation(::Model &model, int frame)
{
    ::UpdateModelAnimation(model, *this, frame);
}

bool raylib::ModelAnimation::IsModelAnimationValid(::Model &model) const
{
    return ::IsModelAnimationValid(model, *this);
}