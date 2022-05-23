/*
** EPITECH PROJECT, 2022
** B-YEP-400-NAN-4-1-indiestudio-matthis.lesur
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <array>

#define MAPSIZE 15

class Map {
    public:
        Map(size_t dimension = MAPSIZE, size_t maxTunnels = 9, size_t maxLength = 9);
        ~Map();

        int **initMap();

        int **getMap();

        void readMap();
    private:
        size_t _dimensions;
        size_t _maxTunnels;
        size_t _maxLength;
        int **_map;
};

#endif /* !MAP_HPP_ */
