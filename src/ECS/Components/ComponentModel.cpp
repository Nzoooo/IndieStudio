/*
** EPITECH PROJECT, 2022
** ComponentModel
** File description:
** ComponentModel
*/

#include "ComponentModel.hpp"

ComponentModel::ComponentModel(std::string modelPath, raylib::Vector3 pos)
{
    _model.Load(modelPath);
    _pos = pos;
}

ComponentModel::~ComponentModel()
{
}

void ComponentModel::Draw()
{
    _model.Draw(_pos, 1.0f, raylib::Color::White());
}
