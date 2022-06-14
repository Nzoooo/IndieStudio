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
#include "raylib/include/ModelAnimation.hpp"

class ComponentModel : public ecs::IComponent {
    public:
        ComponentModel(std::string modelPath, raylib::Vector3 pos, std::string animPath = "", unsigned int animCount = 0);
        ~ComponentModel();

        void Draw();
        void Update(int whichAnim);

    protected:
    private:
        raylib::Model _model;
        raylib::Vector3 _pos;
        raylib::ModelAnimation _anim;
        unsigned int _animCount;
        int _animFrameCounter;
};
