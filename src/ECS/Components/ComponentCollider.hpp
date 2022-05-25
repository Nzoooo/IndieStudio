/*
** EPITECH PROJECT, 2022
** ComponentCollider.hpp
** File description:
** ComponentCollider.hpp
*/

#pragma once

class ComponentCollider {
    public:
        ComponentCollider(bool ableToTakeCollider = true) : _ableToTakeCollider(ableToTakeCollider) {};
        ~ComponentCollider() = default;

        bool getAbleToTakeCollider() const;

        void setAbleToTakeCollider(bool ableToTakeCollider);

    protected:
    private:
        bool _ableToTakeCollider;
};