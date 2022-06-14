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

void raylib::ModelAnimation::Unload(::ModelAnimation anim)
{
    ::UnloadModelAnimation(anim);
}

void raylib::ModelAnimation::Unload(unsigned int animCount)
{
    ::UnloadModelAnimations(this, animCount);
}

void raylib::ModelAnimation::UpdateAnimation(::Model &model, ::ModelAnimation &anim, int frame)
{
    ::UpdateModelAnimation(model, anim, frame);
}

bool raylib::ModelAnimation::IsModelAnimationValid(::Model &model, ::ModelAnimation &anim) const
{
    return ::IsModelAnimationValid(model, anim);
}

void raylib::ModelAnimation::Load(const std::string &fileName, unsigned int *animCount)
{
    ::ModelAnimation *anims = ::LoadModelAnimations(fileName.c_str(), animCount);

    this->boneCount = anims->boneCount;
    this->bones = anims->bones;
    this->frameCount = anims->frameCount;
    this->framePoses = anims->framePoses;
}
