/*
** EPITECH PROJECT, 2022
** ComponentModel
** File description:
** ComponentModel
*/

#include "ComponentModel.hpp"

ComponentModel::ComponentModel(std::string modelPath, raylib::Vector3 pos, std::string animPath, unsigned int animCount) : _animFrameCounter(0)
{
    _model.Load(modelPath);
    _pos = pos;
    _animCount = animCount;
    if (animPath != "")
        _anim.Load(animPath, &_animCount);
}

ComponentModel::~ComponentModel()
{
    _anim.Unload(_animCount);
}

void ComponentModel::Draw()
{
    _model.Draw(_pos, 1.0f, raylib::Color::White());
}

void ComponentModel::Update(int whichAnim)
{
    if (_anim.getAnims() != nullptr) {
        _anim.UpdateAnimation(_model, _anim.getAnims()[whichAnim], _animFrameCounter);
        _animFrameCounter++;
        if (_animFrameCounter >= _anim.getAnims()[whichAnim].frameCount)
            _animFrameCounter = 0;
    }
}
