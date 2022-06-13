/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** ComponentMesh
*/

#ifndef COMPONENTMESH_HPP_
#define COMPONENTMESH_HPP_

#include "IComponent.hpp"
#include "raylib/include/Model.hpp"
#include "raylib/include/Mesh.hpp"
#include "raylib/include/Vector3.hpp"
#include "raylib/include/RaylibException.hpp"


class ComponentMesh : public ecs::IComponent {
    public:
        ComponentMesh(raylib::Vector3 initialPos, raylib::Vector3 size) : _initialPos(initialPos), _size(size) {};
        ~ComponentMesh();

        void setPos(raylib::Vector3 initialPos);
        void setSize(raylib::Vector3 size);

        raylib::Vector3 getPos();
        raylib::Vector3 getSize();

        void loadModel();

        void Draw();

    private:
        raylib::Vector3 _initialPos;
        raylib::Vector3 _size;
        raylib::Model _model;
        raylib::Mesh _mesh;
};

#endif /* !COMPONENTMESH_HPP_ */
