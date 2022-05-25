/*
** EPITECH PROJECT, 2022
** ComponentCollider.hpp
** File description:
** ComponentCollider.hpp
*/

#pragma once

class ComponentCollider {
    public:
        ComponentCollider(bool takeCollider = true) : _takeCollider(takeCollider) {};
        ~ComponentCollider() = default;

        bool getAbleToTakeCollider() const;

        void setAbleToTakeCollider(bool ableToTakeCollider);

    protected:
    private:
        bool _ableToTakeCollider;
};