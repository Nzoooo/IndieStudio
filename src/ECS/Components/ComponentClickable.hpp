/*
** EPITECH PROJECT, 2022
** ComponentClickable.hpp
** File description:
** ComponentClickable.hpp
*/

#pragma once

class ComponentClickable {
    public:
        ComponentClickable(bool ableToBeClicked = false) : _ableToBeClicked(ableToBeClicked) {};
        ~ComponentClickable() = default;

        bool getAbleToBeClicked() const;

        void setAbleToBeClicked(bool ableToBeClicked);

    protected:
    private:
        bool _ableToBeClicked;
};