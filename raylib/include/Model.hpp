/*
** EPITECH PROJECT, 2022
** Model
** File description:
** Model
*/

#pragma once

namespace raylib {
    class Model : public ::Model {
        public:
            Model();
            ~Model();

            void Load(const std::string& fileName);
            void Load(::Mesh& mesh);
            void Unload();
            void UnloadKeepMeshes();
            ::BoundingBox GetBoundingBox();
            void Draw(::Vector3 position, float scale, ::Color tint);
            void DrawEx(::Vector3 position, ::Vector3 rotationAxis, float rotationAngle, ::Vector3 scale, ::Color tint);
            void raylib::Model::UpdateAnimation(::ModelAnimation& anim, int frame);
            bool raylib::Model::IsModelAnimationValid(::ModelAnimation& anim) const;

        protected:
        private:
    };
}
