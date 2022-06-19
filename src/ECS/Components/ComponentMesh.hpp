/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMesh
*/

#ifndef COMPONENTMESH_HPP_
#define COMPONENTMESH_HPP_

#include "IComponent.hpp"
#include "raylib/include/Color.hpp"
#include "raylib/include/Mesh.hpp"
#include "raylib/include/Model.hpp"
#include "raylib/include/RaylibException.hpp"
#include "raylib/include/Texture.hpp"
#include "raylib/include/Vector3.hpp"

class ComponentMesh : public ecs::IComponent {
  public:
    ComponentMesh(raylib::Vector3 initialPos, raylib::Vector3 size, raylib::Color colorCube, raylib::Texture texture)
        : _initialPos(initialPos), _size(size), _color(colorCube), _texture(texture)
    {
        _mesh.GenCube(_size.x, _size.y, _size.z);
        _model.Load(_mesh);
        _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    };
    ~ComponentMesh();

    void setPos(raylib::Vector3 initialPos);
    void setSize(raylib::Vector3 size);

    raylib::Vector3 getPos() const;
    raylib::Vector3 getSize() const;
    raylib::Color getColor() const;

    void Draw();

  private:
    raylib::Vector3 _initialPos;
    raylib::Vector3 _size;
    raylib::Model _model;
    raylib::Mesh _mesh;
    raylib::Color _color;
    raylib::Texture _texture;
};

#endif /* !COMPONENTMESH_HPP_ */
