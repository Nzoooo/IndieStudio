/*
** EPITECH PROJECT, 2022
** ComponentNoClippable.cpp
** File description:
** ComponentNoClippable.cpp
*/

#include "ComponentNoClippable.hpp"

bool ComponentNoClippable::getAbleToNoClip() const
{
    return (_ableToNoClip);
}

void ComponentNoClippable::setAbleToNoClip(bool ableToNoClip)
{
    _ableToNoClip = ableToNoClip;
}