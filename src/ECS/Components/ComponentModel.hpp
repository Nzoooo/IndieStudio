/*
** EPITECH PROJECT, 2022
** ComponentModel
** File description:
** ComponentModel
*/

#pragma once

#include "IComponent.hpp"
#include "raylib/include/Model.hpp"
#include "raylib/include/Vector3.hpp"
#include "raylib/include/Color.hpp"

class ComponentModel : public ecs::IComponent {
    public:
        ComponentModel(std::string modelPath, raylib::Vector3 pos);
        ~ComponentModel();

        void Draw();

    protected:
    private:
        raylib::Model _model;
        raylib::Vector3 _pos;
};
