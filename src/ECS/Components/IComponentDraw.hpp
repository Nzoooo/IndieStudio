/*
** EPITECH PROJECT, 2022
** IComponentDraw.hpp
** File description:
** IComponentDraw.hpp
*/

#pragma once

namespace ecs {
    class IComponentDraw {
        public:
            virtual ~IComponentDraw() = default;

            virtual void Draw() = 0;

        protected:
        private:
    };
}