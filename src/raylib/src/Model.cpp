/*
** EPITECH PROJECT, 2022
** Model
** File description:
** Model
*/

#include "../include/Model.hpp"
#include "../include/RaylibException.hpp"

raylib::Model::Model()
{
}

raylib::Model::~Model()
{
    Unload();
}

void raylib::Model::Load(const std::string &fileName)
{
    ::Model model = ::LoadModel(fileName.c_str());
    transform = model.transform;

    meshCount = model.meshCount;
    materialCount = model.materialCount;
    meshes = model.meshes;
    materials = model.materials;
    meshMaterial = model.meshMaterial;

    boneCount = model.boneCount;
    bones = model.bones;
    bindPose = model.bindPose;
}

void raylib::Model::Load(::Mesh &mesh)
{
    ::Model model = ::LoadModelFromMesh(mesh);
    transform = model.transform;

    meshCount = model.meshCount;
    materialCount = model.materialCount;
    meshes = model.meshes;
    materials = model.materials;
    meshMaterial = model.meshMaterial;

    boneCount = model.boneCount;
    bones = model.bones;
    bindPose = model.bindPose;
}

void raylib::Model::Unload()
{
    if (meshes != nullptr || materials != nullptr) {
        ::UnloadModel(*this);
        meshes = nullptr;
        materials = nullptr;
    }
}

void raylib::Model::UnloadKeepMeshes()
{
    ::UnloadModelKeepMeshes(*this);
}

::BoundingBox raylib::Model::GetBoundingBox()
{
    return (::GetModelBoundingBox(*this));
}

void raylib::Model::Draw(::Vector3 position, float scale, ::Color tint)
{
    ::DrawModel(*this, position, scale, tint);
}

void raylib::Model::DrawEx(::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint)
{
    ::DrawModelEx(*this, position, rotationAxis, rotationAngle, scale, tint);
}

void raylib::Model::UpdateAnimation(::ModelAnimation &anim, int frame)
{
    ::UpdateModelAnimation(*this, anim, frame);
}

bool raylib::Model::IsModelAnimationValid(::ModelAnimation &anim) const
{
    return ::IsModelAnimationValid(*this, anim);
}
