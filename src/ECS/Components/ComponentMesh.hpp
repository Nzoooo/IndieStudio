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
#include "raylib/include/Model.hpp"
#include "raylib/include/Mesh.hpp"
#include "raylib/include/Vector3.hpp"
#include "raylib/include/RaylibException.hpp"


class ComponentMesh : public ecs::IComponent {
    public:
        ComponentMesh(raylib::Vector3 initialPos, raylib::Vector3 size, raylib::Color colorCube) : _initialPos(initialPos), _size(size), _color(colorCube)
        {
            _mesh.GenCube(_size.x, _size.y, _size.z);
            _model.Load(_mesh);
        };
        ~ComponentMesh();

        void setPos(raylib::Vector3 initialPos);
        void setSize(raylib::Vector3 size);

        raylib::Vector3 getPos();
        raylib::Vector3 getSize();

        void Draw();

    private:
        raylib::Vector3 _initialPos;
        raylib::Vector3 _size;
        raylib::Model _model;
        raylib::Mesh _mesh;
        raylib::Color _color;
};

#endif /* !COMPONENTMESH_HPP_ */
