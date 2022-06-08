/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** SystemExemple
*/

#ifndef SYSTEMEXEMPLE_HPP_
#define SYSTEMEXEMPLE_HPP_

#include "ISystem.hpp"

class CustomSystem : public ecs::ISystem {
    void update(ecs::Core &index)
    {
        (void)index;
        std::cout << "Update a custom system." << std::endl;
    }
};

#endif /* !SYSTEMEXEMPLE_HPP_ */
