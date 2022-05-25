/*
** EPITECH PROJECT, 2022
** ComponentCollider.hpp
** File description:
** ComponentCollider.hpp
*/

#pragma once

class ComponentCollider {
    public:
        ComponentCollider(bool takeCollider = false, bool isCollidable = true) : _takeCollider(takeCollider), _isCollidable(isCollidable) {};
        ~ComponentCollider() = default;

        bool getTakeCollider() const;
        bool getIsCollidable() const;

        void setTakeCollider(bool takeCollider);
        void setIsCollidable(bool isCollidable);

    protected:
    private:
        bool _takeCollider;
        bool _isCollidable;
};