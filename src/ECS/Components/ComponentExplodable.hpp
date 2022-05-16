/*
** EPITECH PROJECT, 2022
** ComponentExplodable.hpp
** File description:
** ComponentExplodable.hpp
*/

#pragma once

#include "IComponent.hpp"
#include <string>

class ComponentExplodable : public ecs::IComponent {
    public:
        ComponentExplodable(std::size_t deflagrationRange = 0, bool ableToExplode = false) : _deflagrationRange(deflagrationRange), _ableToExplode(ableToExplode) {};
        ~ComponentExplodable() = default;

        std::size_t getDeflagrationRange() const;
        bool getAbleToExplode() const;

        void setDeflagrationRange(std::size_t deflagrationRange);
        void setAbleToExplode(bool ableToExplode);

    protected:
    private:
        std::size_t _deflagrationRange;
        bool _ableToExplode;
};