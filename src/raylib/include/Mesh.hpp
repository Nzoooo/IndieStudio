/*
** EPITECH PROJECT, 2022
** Mesh
** File description:
** Mesh
*/

#pragma once

#include "raylib.hpp"

namespace raylib
{
    class Mesh : public ::Mesh {
      public:
        Mesh() = default;
        Mesh(const Mesh &other) = delete;
        ~Mesh();

        void Unload();
        void GenPoly(int sides, float radius);
        void GenPlane(float width, float length, int resX, int resZ);
        void GenCube(float width, float height, float length);
        void GenSphere(float radius, int rings, int slices);
        void GenHemiSphere(float radius, int rings, int slices);
        void GenCylinder(float radius, float height, int slices);
        void GenCone(float radius, float height, int slices);
        void GenTorus(float radius, float size, int radSeg, int sides);
        void GenKnot(float radius, float size, int radSeg, int sides);
        void GenHeightmap(::Image heightmap, ::Vector3 size);
        void GenCubicmap(::Image cubicmap, ::Vector3 cubeSize);

      protected:
      private:
        void _setMesh(::Mesh mesh);
    };
} // namespace raylib
