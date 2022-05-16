/*
** EPITECH PROJECT, 2022
** ComponentNoClippable.hpp
** File description:
** ComponentNoClippable.hpp
*/

#pragma once

class ComponentNoClippable {
    public:
        ComponentNoClippable(bool ableToNoClip = false) : _ableToNoClip(ableToNoClip) {};
        ~ComponentNoClippable() = default;

        bool getAbleToNoClip() const;

        void setAbleToNoClip(bool ableToNoClip);

    protected:
    private:
        bool _ableToNoClip;
};