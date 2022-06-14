/*
** EPITECH PROJECT, 2022
** Mesh
** File description:
** Mesh
*/

#include "../include/Mesh.hpp"
#include <cstdio>

namespace raylib
{
    Mesh::~Mesh()
    {
        Unload();
    }

    void Mesh::Unload()
    {
        ::UnloadMesh(*this);
    }

    void Mesh::GenPoly(int sides, float radius)
    {
        _setMesh(::GenMeshPoly(sides, radius));
    }

    void Mesh::GenPlane(float width, float length, int resX, int resZ)
    {
        _setMesh(::GenMeshPlane(width, length, resX, resZ));
    }

    void Mesh::GenCube(float width, float height, float length)
    {
        _setMesh(::GenMeshCube(width, height, length));
    }

    void Mesh::GenSphere(float radius, int rings, int slices)
    {
        _setMesh(::GenMeshSphere(radius, rings, slices));
    }

    void Mesh::GenHemiSphere(float radius, int rings, int slices)
    {
        _setMesh(::GenMeshHemiSphere(radius, rings, slices));
    }

    void Mesh::GenCylinder(float radius, float height, int slices)
    {
        _setMesh(::GenMeshCylinder(radius, height, slices));
    }

    void Mesh::GenCone(float radius, float height, int slices)
    {
        _setMesh(::GenMeshCone(radius, height, slices));
    }

    void Mesh::GenTorus(float radius, float size, int radSeg, int sides)
    {
        _setMesh(::GenMeshTorus(radius, size, radSeg, sides));
    }

    void Mesh::GenKnot(float radius, float size, int radSeg, int sides)
    {
        _setMesh(::GenMeshKnot(radius, size, radSeg, sides));
    }

    void Mesh::GenHeightmap(::Image heightmap, ::Vector3 size)
    {
        _setMesh(::GenMeshHeightmap(heightmap, size));
    }

    void Mesh::GenCubicmap(::Image cubicmap, ::Vector3 cubeSize)
    {
        _setMesh(::GenMeshCubicmap(cubicmap, cubeSize));
    }

    void Mesh::_setMesh(::Mesh mesh)
    {
        vertexCount = mesh.vertexCount;
        triangleCount = mesh.triangleCount;

        vertices = mesh.vertices;
        texcoords = mesh.texcoords;
        texcoords2 = mesh.texcoords2;
        normals = mesh.normals;
        tangents = mesh.tangents;
        colors = mesh.colors;
        indices = mesh.indices;

        animVertices = mesh.animVertices;
        animNormals = mesh.animNormals;
        boneIds = mesh.boneIds;
        boneWeights = mesh.boneWeights;

        vaoId = mesh.vaoId;
        vboId = mesh.vboId;
    }
} // namespace raylib
