/*
** EPITECH PROJECT, 2022
** ComponentModel
** File description:
** ComponentModel
*/

#pragma once

#include "ComponentMovable.hpp"
#include "IComponent.hpp"
#include "raylib/include/BoundingBox.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Model.hpp"
#include "raylib/include/ModelAnimation.hpp"
#include "raylib/include/Vector3.hpp"

class ComponentModel : public ecs::IComponent {
  public:
    ComponentModel(std::string modelPath, raylib::Vector3 pos, raylib::Vector3 scale = {1.0f, 1.0f, 1.0f}, std::string animPath = "",
        unsigned int animCount = 0, float rotateAngle = 180.0f, raylib::Vector3 rotateAxis = {0.0f, 1.0f, 0.0f});
    ~ComponentModel();

    void Draw();
    void Update(int whichAnim);
    raylib::Vector3 getPos() const;
    raylib::Vector3 getInitialPos() const;
    raylib::Vector3 getScale() const;
    raylib::Vector3 getRotateAxis() const;
    float getRotateAngle() const;
    void setPos(raylib::Vector3 pos);
    void setScale(raylib::Vector3 scale);
    void setRotateAxis(raylib::Vector3 rotateAxis);
    void setRotateAngle(float rotateAngle);
    void setRotateAngle(ComponentMovable::Direction dir);

  protected:
  private:
    raylib::Model _model;
    raylib::Vector3 _pos;
    raylib::Vector3 _initialPos;
    raylib::Vector3 _scale;
    raylib::Vector3 _rotateAxis;
    float _rotateAngle;
    raylib::ModelAnimation _anim;
    unsigned int _animCount;
    int _animFrameCounter;
};
