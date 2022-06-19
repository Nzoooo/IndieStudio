/*
** EPITECH PROJECT, 2022
** ComponentModel
** File description:
** ComponentModel
*/

#include "ComponentModel.hpp"
#include <iostream>

ComponentModel::ComponentModel(std::string modelPath, raylib::Vector3 pos, raylib::Vector3 scale, std::string animPath, unsigned int animCount,
    float rotateAngle, raylib::Vector3 rotateAxis)
    : _animFrameCounter(0)
{
    _model.Load(modelPath);
    _pos = pos;
    _initialPos = pos;
    _scale = scale;
    _rotateAxis = rotateAxis;
    _rotateAngle = rotateAngle;
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
    _model.DrawEx(_pos, _rotateAxis, _rotateAngle, _scale, raylib::Color::White());
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

raylib::Vector3 ComponentModel::getPos() const
{
    return (_pos);
}

raylib::Vector3 ComponentModel::getInitialPos() const
{
    return (_initialPos);
}

raylib::Vector3 ComponentModel::getScale() const
{
    return (_scale);
}

raylib::Vector3 ComponentModel::getRotateAxis() const
{
    return (_rotateAxis);
}

float ComponentModel::getRotateAngle() const
{
    return (_rotateAngle);
}

void ComponentModel::setPos(raylib::Vector3 pos)
{
    _pos = pos;
}

void ComponentModel::setScale(raylib::Vector3 scale)
{
    _scale = scale;
}

void ComponentModel::setRotateAxis(raylib::Vector3 rotateAxis)
{
    _rotateAxis = rotateAxis;
}

void ComponentModel::setRotateAngle(float rotateAngle)
{
    _rotateAngle = rotateAngle;
}

void ComponentModel::setRotateAngle(ComponentMovable::Direction dir)
{
    switch (dir) {
        case ComponentMovable::UP: setRotateAngle(270.0f); break;
        case ComponentMovable::DOWN: setRotateAngle(90.0f); break;
        case ComponentMovable::LEFT: setRotateAngle(0.0f); break;
        case ComponentMovable::RIGHT: setRotateAngle(180.0f); break;
        default: break;
    }
}
